/**
this code is to generate a proto message having sensor values,
serializing it and later writing it a file called 'sensor.data'
*/

#include<iostream>
#include "sensor_data.pb.h"
#include <fstream>
using namespace std;
using namespace sensor_data;

int main()
{
   cout << "creating message.."<<endl;
   //create an object of "Sensor" (look sensor_data.proto)
   Sensor sensor;
   //set values of "Sensor" members
   sensor.set_name("Laboratory");
   sensor.set_temperature(23.4);
   sensor.set_humidity(68);
   sensor.set_door(Sensor_SwitchLevel_OPEN);

  //open a file and serialize the data and write to it via filestream
  std::ofstream ofs("sensor.data", std::ios_base::out | std::ios_base::binary);
  sensor.SerializeToOstream(&ofs);

  cout<<"message creation done in file 'sensor.data'!!"<<endl;

   return 0;
}
