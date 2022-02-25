import serial
import time
import numpy as np
lst_of_delays = []

x = input("Enter Distance: ")

ser = serial.Serial('COM7')

while True:
    try:
        ser_bytes = ser.readline()
        decoded_bytes = float(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
        print("{} {}".format(time.time_ns(), decoded_bytes))
        lst_of_delays.append([time.time_ns(), decoded_bytes])
    except:
        print("Keyboard Interrupt")
        path = 'Data of Reading No. 3/Rx' + x + 'm.csv'
        np.savetxt(path, lst_of_delays, delimiter=',')
        break
