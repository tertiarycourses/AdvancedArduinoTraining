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

while True:
    t = temperature.read()
    if t == None:
        continue
    else:
        temp = (t*1000)/1.9
        temp = '%.2f' % temp
        conn = urlopen(baseURL + '&field1=%s' % temp)
        #conn.close()
    print(temp)    
    time.sleep(1)
