import serial
ser = serial.Serial('COM7', 9600)
ser.flushInput()

while True:

    ser_bytes = ser.readline()
    decoded_bytes = str(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
    print(decoded_bytes)
