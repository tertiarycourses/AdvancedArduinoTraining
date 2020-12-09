# Activity: Trigger the Email Notification
# In case you encountered error in sending email due to security concern, please ignore this activity

from pyfirmata2 import Arduino, util
import time
import smtplib,ssl

board = Arduino('/dev/tty.wchusbserial1420')

def send_email():
    port = 587  # For starttls
    smtp_server = "smtp.gmail.com"
    sender_email = "xxx"
    receiver_email = "xxx"
    password = "xxx"
    message = "Testing"
    context = ssl.create_default_context()
    with smtplib.SMTP(smtp_server, port) as server:
        server.starttls(context=context)
        server.login(sender_email, password)
        server.sendmail(sender_email, receiver_email, message)
        print("message sent")

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
        print(brightness)
    
    if brightness > 500:
        led.write(1)
        send_email()
    else:
        led.write(0)
        
    time.sleep(5)