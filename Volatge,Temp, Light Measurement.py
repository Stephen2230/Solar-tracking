import pyfirmata
import time
from pyfirmata import Arduino, util
from time import sleep
import os
    
port = '/dev/cu.usbmodem1411'
board = pyfirmata.Arduino(port)

it = util.Iterator(board)

it.start()

Tvl = board.get_pin('a:0:1')

time.sleep(1.0)
print(int(Tvl.read()*5000.0-500.0)/10.0)
