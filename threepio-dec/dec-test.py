import serial
import serial.tools.list_ports
import time

# import matplotlib.pyplot as plt

# make sure the 'COM#' is set according the Windows Device Manager
available_ports = serial.tools.list_ports.comports()
print([i.hwid for i in available_ports])
device = None
for p in available_ports:
    if "VID:PID=2341:0043" in p.hwid:
        device = p.device

ser = serial.Serial(device)
time.sleep(2)

data = []
while True:
    line = ser.readline()  # read a byte string
    if line:
        string = line.decode().strip()  # convert the byte string to a unicode string
        data_list = tuple([float(i) for i in string.split(",")])
        print(data_list)
ser.close()
