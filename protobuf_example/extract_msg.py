#!/usr/bin/env python3
'''
this code extracts proto message from 'sensor.data' 
which was created by "create_message.out" a cpp application 
and prints sensor values to screen.
'''

from sensor_data_pb2 import Sensor

if __name__ == "__main__":
    with open("sensor.data", 'rb') as file:
        content = file.read()
        print("Retrieve Sensor object from sensor.data")
        sensor = Sensor()
        sensor.ParseFromString(content)
        print(f"Sensor name: {sensor.name}")
        print(f"Sensor temperature: {sensor.temperature}")
        print(f"Sensor humidity: {sensor.humidity}")
    print("Sensor door: {}".format("Open" if sensor.temperature else "Closed"))
