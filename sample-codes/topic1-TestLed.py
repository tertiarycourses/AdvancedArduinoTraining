# Test the LED

from pyfirmata2 import Arduino, util
import time

board = Arduino('/dev/tty.wchusbserial1410')

# Light up the LED
# board.digital[13].write(1)

# Blink the LED
while True:
    board.digital[13].write(1)
    time.sleep(1)
    board.digital[13].write(0)
    time.sleep(1)