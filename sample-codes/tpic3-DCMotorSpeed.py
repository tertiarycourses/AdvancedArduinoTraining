# Activity: Test DC Motor

from pyfirmata2 import Arduino, util

board = Arduino('/dev/tty.wchusbserial1410')

motor = board.get_pin('d:3:o')

while True:
    motor.write(1)