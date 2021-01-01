#include <string>

#include <grpcpp/grpcpp.h>
#include "sensor_data.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using namespace sensor_data;
using namespace std;

//define a class which is derived from sensor_data::sensor_service::Service (sensor_service is service defined  in proto file)
class sensorServiceImplementation final : public sensor_service::Service {
//switch_request is rpc defined under service "sensor_service" , it takes "Sensor" as input and returns "response" as output
//we are overriding this rpc here
    Status switch_request(
        ServerContext* context, 
        const Sensor* request, 
        response* reply
    ) override {
        cout << "data recieved from client\n";
	cout << "name :" <<request->name()<<endl;
	cout << "temperature :" <<request->temperature()<<endl;
	cout << "humidity :" <<request->humidity()<<endl;
	cout << "door :" <<request->door()<<endl;
	//if temperature crosses >30 make it 20
	if(request->temperature() > 30)
        reply->set_switch_temp_to(20);
	//if humidity crosses >33 make it 25
	if(request->humidity() > 33)
        reply->set_switch_humid_to(25);
	//if temperature crosses >30 or if humidity crosses >33 close the door
	if((request->temperature() > 30) | (request->humidity() > 33))
        reply->set_switch_door_to(OPEN);
        return Status::OK;
    } 
};

void Run() {
    std::string address("0.0.0.0:5000");
    sensorServiceImplementation service;

    ServerBuilder builder;

    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on port: " << address << std::endl;

    server->Wait();
}

int main(int argc, char** argv) {
    Run();

    return 0;
}
