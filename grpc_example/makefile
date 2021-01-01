CXX = g++
GRPC_INSTALL_PATH =/home/divakar/grpc/grpc-a
PROTOC = $(GRPC_INSTALL_PATH)/bin/protoc

LIBS = $(GRPC_INSTALL_PATH)/lib/libgrpc++_reflection.a $(GRPC_INSTALL_PATH)/lib/libgrpc++.a $(GRPC_INSTALL_PATH)/lib/libprotobuf.a $(GRPC_INSTALL_PATH)/lib/libgrpc.a $(GRPC_INSTALL_PATH)/lib/libssl.a $(GRPC_INSTALL_PATH)/lib/libcrypto.a $(GRPC_INSTALL_PATH)/lib/libz.a $(GRPC_INSTALL_PATH)/lib/libcares.a -lnsl $(GRPC_INSTALL_PATH)/lib/libre2.a $(GRPC_INSTALL_PATH)/lib/libabsl_hash.a $(GRPC_INSTALL_PATH)/lib/libabsl_bad_variant_access.a $(GRPC_INSTALL_PATH)/lib/libabsl_city.a $(GRPC_INSTALL_PATH)/lib/libabsl_raw_hash_set.a $(GRPC_INSTALL_PATH)/lib/libabsl_hashtablez_sampler.a $(GRPC_INSTALL_PATH)/lib/libabsl_exponential_biased.a $(GRPC_INSTALL_PATH)/lib/libgpr.a $(GRPC_INSTALL_PATH)/lib/libabsl_status.a $(GRPC_INSTALL_PATH)/lib/libabsl_cord.a $(GRPC_INSTALL_PATH)/lib/libabsl_bad_optional_access.a $(GRPC_INSTALL_PATH)/lib/libabsl_synchronization.a $(GRPC_INSTALL_PATH)/lib/libabsl_stacktrace.a $(GRPC_INSTALL_PATH)/lib/libabsl_symbolize.a $(GRPC_INSTALL_PATH)/lib/libabsl_debugging_internal.a $(GRPC_INSTALL_PATH)/lib/libabsl_demangle_internal.a $(GRPC_INSTALL_PATH)/lib/libabsl_graphcycles_internal.a $(GRPC_INSTALL_PATH)/lib/libabsl_time.a $(GRPC_INSTALL_PATH)/lib/libabsl_civil_time.a $(GRPC_INSTALL_PATH)/lib/libabsl_time_zone.a $(GRPC_INSTALL_PATH)/lib/libabsl_malloc_internal.a $(GRPC_INSTALL_PATH)/lib/libabsl_str_format_internal.a $(GRPC_INSTALL_PATH)/lib/libabsl_strings.a $(GRPC_INSTALL_PATH)/lib/libabsl_strings_internal.a $(GRPC_INSTALL_PATH)/lib/libabsl_int128.a $(GRPC_INSTALL_PATH)/lib/libabsl_throw_delegate.a $(GRPC_INSTALL_PATH)/lib/libabsl_base.a $(GRPC_INSTALL_PATH)/lib/libabsl_raw_logging_internal.a -lpthread $(GRPC_INSTALL_PATH)/lib/libabsl_log_severity.a $(GRPC_INSTALL_PATH)/lib/libabsl_spinlock_wait.a -lrt $(GRPC_INSTALL_PATH)/lib/libaddress_sorting.a $(GRPC_INSTALL_PATH)/lib/libupb.a -ldl -lrt -lm -lpthread

INC = $(GRPC_INSTALL_PATH)/include

OBJS = sensor_data.pb.cc \
	sensor_data.grpc.pb.cc \
	sensor_data.pb.o \
	sensor_data.grpc.pb.o \
	sensor_client.o \
	sensor_server.o

APPS = sensor_server \
	sensor_client

all: $(OBJS) $(APPS)

clean :
	rm -rf $(OBJS) *.pb.* $(APPS)

sensor_data.pb.cc : sensor_data.proto
	$(PROTOC) --proto_path=. --cpp_out=. $<

sensor_data.grpc.pb.cc : sensor_data.proto
	$(PROTOC) --proto_path=. --plugin=protoc-gen-grpc=$(GRPC_INSTALL_PATH)/bin/grpc_cpp_plugin --grpc_out=. $<

%.pb.o : %.pb.cc
	$(CXX) -I. -I$(INC) -c -std=c++11 -o $@ $<

%.grpc.pb.o : %.grpc.pb.cc
	$(CXX) -I. -I$(INC) -c -std=c++11 -o $@ $<

%.o : %.cpp
	$(CXX) -I. -I$(INC) -c -std=c++11 -o $@ $<

sensor_server : sensor_server.o sensor_data.pb.o sensor_data.grpc.pb.o
	$(CXX) -std=c++11  $^ -o $@ $(LIBS)

sensor_client : sensor_client.o sensor_data.pb.o sensor_data.grpc.pb.o
	$(CXX) -std=c++11  $^ -o $@ $(LIBS)

