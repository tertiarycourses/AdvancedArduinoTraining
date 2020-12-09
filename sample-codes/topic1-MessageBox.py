# Activity: Trigger the Message Box

from pyfirmata2 import Arduino, util
import time
from tkinter import *
from tkinter.ttk import *

board = Arduino('/dev/tty.wchusbserial1430')

it = util.Iterator(board)
it.start()

light = board.get_pin('a:0:i')
led = board.get_pin('d:13:o')

def popupmsg(msg):
    popup = Tk()
    label = Label(popup, text=msg)
    label.pack()
    popup.mainloop()

while True:
    brightness = light.read()
    if brightness == None:
        continue
    else:
        brightness = (brightness*1000)
        print(brightness)

    if brightness > 500:
        led.write(1)
        popupmsg("Light is On")
    else:
        led.write(0)
    
    time.sleep(1)

