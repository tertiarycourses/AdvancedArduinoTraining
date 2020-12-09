# Activity: Toggle two LEDs

from pyfirmata2 import Arduino, util
import time

board = Arduino('/dev/tty.wchusbserial1420')

# Test the LED
# board.digital[13].write(1)

while True:
    board.digital[13].write(1)
    board.digital[11].write(0)
    time.sleep(1)
    board.digital[13].write(0)
    board.digital[11].write(1)
    time.sleep(1)