#include <string>
#include <grpcpp/grpcpp.h>
#include "sensor_data.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using namespace sensor_data;
using namespace std;

class sensor_data_client {
    public:
        sensor_data_client(std::shared_ptr<Channel> channel) : stub_(sensor_service::NewStub(channel)) {}

	response* switch_request(Sensor* request) {

        response *reply = new response();



        ClientContext context;
        //switch_request is defined as rpc under service "sensor_service" in proto file
        Status status = stub_->switch_request(&context, *request, &(*reply));

        if(status.ok()){
            return reply;
        } else {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            return nullptr;
        }
    }

    private:
        std::unique_ptr<sensor_service::Stub> stub_;
};

void Run() {
    std::string address("0.0.0.0:5000");
    sensor_data_client client(
        grpc::CreateChannel(
            address, 
            grpc::InsecureChannelCredentials()
        )
    );

    response* reply;
    Sensor* request = new Sensor();
    request->set_name("Laboratory");
    request->set_temperature(43);
    request->set_humidity(35);
    request->set_door(CLOSED); 
    reply = client.switch_request(request);
    if(reply != nullptr)
    {
       cout<< "response recieved from server\n";
       cout<< reply->switch_temp_to()<<endl;
       cout<< reply->switch_humid_to()<<endl;
       cout<< reply->switch_door_to()<<endl;	
    }
}

int main(int argc, char* argv[]){
    Run();

    return 0;
}
