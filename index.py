import RPi.GPIO as GPIO
import time

sw1=21
sw2=20
sw3=16

GPIO.setmode(GPIO.BCM)

GPIO.setup(sw1, GPIO.IN)
GPIO.setup(sw2, GPIO.IN)
GPIO.setup(sw3, GPIO.IN)

while True:
    if GPIO.input(sw1)==1:
        stat1=1
    else:
        stat1=0
    if GPIO.input(sw2)==1:
        stat2=1
    else:
        stat2=0
    if GPIO.input(sw3)==1:
        stat3=1
    else:
        stat3=0
    
    print("sw1:",stat1)
    print("sw2:",stat2)
    print("sw3:",stat3)
    
    time.sleep(0.1)