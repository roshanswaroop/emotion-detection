import serial
from time import sleep

# coordinate input to send through serial to Arduino, (x,y) pairs, 2 removed at a time. 
# Processing loop in display.ino occurs in O(N) time, N being num of individual LEDs
# Improvements could be made by caching which LEDs are on and only flipping the XOR 
# of the previous state and the current one
# 0: "Angry", 1: "Disgust", 2: "Fear", 3: "Happy", 4: "Sad", 5: "Surprised", 6: 'Neutral'
commands = ["1 1 1 6 2 2 2 3 2 4 2 5 4 1 4 6 5 0 5 1 5 2 5 5 5 6 5 7", 
            "1 1 1 2 1 3 1 4 1 5 1 6 2 1 2 2 2 3 2 4 2 5 3 2 3 3 3 4 3 5 5 1 5 6 6 1 6 6 7 0 7 1 7 2 7 5 7 6 7 7", 
            "1 1 1 2 1 3 1 4 1 5 1 6 2 1 2 2 2 3 2 4 2 5 2 6 3 2 3 3 3 4 3 5 5 1 5 6 6 1 6 6", 
            "1 2 1 3 1 4 1 5 2 1 2 6 4 1 4 6 5 1 5 6", 
            "1 1 1 6 2 2 2 3 2 4 2 5 4 1 4 6 5 1 5 6", 
            "1 2 1 3 1 4 1 5 2 2 2 3 2 4 2 5 4 1 4 6 5 1 5 6", 
            "2 2 2 3 2 4 2 5 4 1 4 6 5 1 5 6"]



# takes in argmax index relating to emotion, from 0 to 6
def make_face(maxindex):
    # you will have to change the serial port and ensure BAUD rate matches Arduino setup
    ser = serial.Serial('/dev/cu.usbserial-DJ00S6MS', 115200, timeout=1) 
    print(ser.name)
    # flush serial for unprocessed data 
    # this turns off LEDs as well, unsure why
    ser.flushInput()
    com = commands[maxindex]
    ser.write(com.encode())
    print("Waiting for answer")
    while True:
        answer = ser.readline()
        if answer:
            print("Answer:", answer)
            break
        sleep(0.1)
    ser.flushInput()

# if __name__ == '__main__':
#     make_face()