from pyfirmata2 import Arduino, util
from urllib.request import urlopen
import time 

board = Arduino('/dev/tty.wchusbserial1410')

it = util.Iterator(board)
it.start()

# Enter Your API key here
myAPI = 'SZSYSRC29W0EG788' 

# URL where we will send the data, Don't change it
baseURL = 'https://api.thingspeak.com/update?api_key=%s' % myAPI 

temperature = board.get_pin('a:1:i')
light = board.get_pin('a:0:i')
led = board.get_pin('d:13:o')

while True:
    t = temperature.read()
    if t == None:
        continue
    else:
        temp = (t*1000)/1.9
        temp = '%.2f' % temp
        print('Temperature : ', temp)    

    brightness = light.read()
    if brightness == None:
        continue
    else:
        brightness = (brightness*1000)
        print('Brightness : ', brightness)
        
        if brightness > 500:
            led.write(1)
        else:
            led.write(0) 

    conn = urlopen(baseURL + '&field1=%s&field2=%s' % (temp, brightness))
    time.sleep(1)
    #conn.close()
