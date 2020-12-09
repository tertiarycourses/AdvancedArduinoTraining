# Activity: Control DC Motor with Temperature Sensor

from pyfirmata2 import Arduino, util
import time

board = Arduino('/dev/tty.wchusbserial1410')

it = util.Iterator(board)
it.start()

temperature = board.get_pin('a:1:i')
motor = board.get_pin('d:3:o')

while True:
    t = temperature.read()
    if t == None:
        continue
    else:
        temp = (t*1000)/1.9
        print(temp)    
        time.sleep(1)
    
    if temp>20:
        motor.write(1)
    else:
        motor.write(0)

    