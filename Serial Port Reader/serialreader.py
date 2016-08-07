import serial
import time
import datetime
import csv
datets = datetime.datetime.fromtimestamp(time.time()).strftime('%Y-%m-%d')
with open("Specify File Location Here"+datets+".csv", "w") as csvfile:

    writefile = csv.writer(csvfile, delimiter=',')
    ser = serial.Serial('/dev/cu.usbserial-DN008ZF2',9600)
    while True:
        line = ser.readline()
        ts = time.time()
        st = datetime.datetime.fromtimestamp(ts).strftime('%Y-%m-%d %H:%M:%S')
        print (st,line.rstrip())
        writefile.writerow([st,line.rstrip()])
        csvfile.flush()
