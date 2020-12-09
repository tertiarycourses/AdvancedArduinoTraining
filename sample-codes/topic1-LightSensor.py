# Activity: Test the Light Sensor

from pyfirmata2 import Arduino, util
import time

board = Arduino('/dev/tty.wchusbserial1410')

it = util.Iterator(board)
it.start()

light = board.get_pin('a:0:i')
led = board.get_pin('d:13:o')

while True:

    brightness = light.read()
    if brightness == None:
        continue
    else:
        brightness = (brightness*1000)
        print("%.2f" % brightness)
    
        if brightness > 500:
            led.write(1)
        else:
            led.write(0)

    time.sleep(1)