# Test the Temperature Sensor

from pyfirmata2 import Arduino, util
import time

board = Arduino('/dev/tty.wchusbserial1410')

it = util.Iterator(board)
it.start()

temperature = board.get_pin('a:1:i')

while True:
    t = temperature.read()
    if t == None:
        continue
    else:
        temp = (t*1000)/1.9

    print(temp)    
    time.sleep(1)