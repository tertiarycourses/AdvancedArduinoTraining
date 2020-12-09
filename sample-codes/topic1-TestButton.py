# Control the LED with Push button

from pyfirmata2 import Arduino, util
import time

board = Arduino('/dev/tty.wchusbserial1410')

it = util.Iterator(board)
it.start()

digital_input = board.get_pin('d:10:i')
led = board.get_pin('d:13:o')

while True:
    sw = digital_input.read()
    if sw is True:
        led.write(1)
    else:
        led.write(0)
    time.sleep(0.1)