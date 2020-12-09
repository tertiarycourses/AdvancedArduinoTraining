# Activity: PIR Sensor

from pyfirmata2 import Arduino, util
import time

board = Arduino('/dev/tty.wchusbserial1430')

it = util.Iterator(board)
it.start()

def blink():
     while True:
          led.write(1)
          time.sleep(1)
          led.write(0)
          time.sleep(1)

pir = board.get_pin('d:9:i')
led = board.get_pin('d:13:o')

pinStateCurrent   = False; # current state of pin
pinStatePrevious  = False; # previous state of pin

while True:
     pinStatePrevious = pinStateCurrent
     pinStateCurrent = pir.read()
     print(pinStateCurrent)
     print(pinStatePrevious)
     time.sleep(0.5)
     if pinStatePrevious == False and pinStateCurrent == True:
          print('Motion detected!')
     elif pinStatePrevious == True and pinStateCurrent == False:
          print('Motion stopped!')
     else:
          print("No readining")
     time.sleep(0.5)
