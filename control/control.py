import serial
import json

PORT = 'COM5'

def control_servo(servo1, servo2, servo3):
    values = {
        'servo1': str(servo1),
        'servo2': str(servo2),
        'servo3': str(servo3)
    }

    data = json.dumps(values)
    ser = serial.Serial(PORT, 9600, timeout=2)

    if ser.isOpen():
        ser.write(data.encode('ascii'))
        ser.flush()
        try:
            incoming = ser.readline().decode("utf-8")
            print(incoming)
        except Exception as e:
            print(e)
            pass
    else:
        print ("opening error")
    
    ser.close()
    return

if __name__ == '__main__':
    control_servo(115, 105, 95)
    