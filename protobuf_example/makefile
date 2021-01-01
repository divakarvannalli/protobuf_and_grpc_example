CXX = g++

#this line should be enabled if protoc is installed to default path , /usr/lib /usr/include/
#PROTO_LIBS = `pkg-config --cflags --libs protobuf`
#in my case i had installed protoc to $HOME/INSTALL_PROTOC which is "/home/divakar/grpc/grpc-a/" path
PROTO_LIBS = -I/home/divakar/grpc/grpc-a/include/ -L/home/divakar/grpc/grpc-a/lib/ -lprotobuf

APP = create_message.out

all: $(APP)

clean :
	rm -rf *.pb.*
	rm -rf *_pb2.py
	rm -rf $(APP)
	rm -rf sensor.data
	rm -r __pycache__

sensor_data.pb.cc : sensor_data.proto
	protoc --cpp_out=. $<
	protoc --python_out=. $<

$(APP) : create_message.cpp sensor_data.pb.cc
	$(CXX) $^ $(PROTO_LIBS) -o $@
