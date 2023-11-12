from pyfirmata2 import Arduino, util, STRING_DATA
import time

port = '/dev/cu.usbserial-140'
board = Arduino(port)

data = input("Enter data")
while True:
    board.send_sysex(STRING_DATA, util.str_to_two_byte_iter(data))
    time.sleep(1)

    