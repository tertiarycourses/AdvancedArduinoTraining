# Activity: Control LED with Temperature Sensor

from pyfirmata2 import Arduino, util
import time

board = Arduino('/dev/tty.wchusbserial1410')

it = util.Iterator(board)
it.start()

temperature = board.get_pin('a:1:i')
led = board.get_pin('d:13:o')

def blink():
    led.write(1)
    time.sleep(1)
    led.write(0)
    time.sleep(1)

while True:
    t = temperature.read()
    if t == None:
        continue
    else:
        temp = (t*1000)/20
        print("%.2f" % temp)  
       
        if temp>20:
            blink()
        else:
            led.write(0)
    time.sleep(0.1)