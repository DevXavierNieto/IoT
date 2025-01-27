import serial

arduino = serial.Serial("COM3", 9600) #9600 es la frecuencia para el arduino

def pressed_key(key):
    if key == "a":
        arduino.write(b"a") #b es de bits y lo de comillas es la letra cruda
    if key == "b":
        arduino.write(b"b")

while True:
    key = input("Introduce un caracter")
    pressed_key(key)

    if key =="q":
        break
arduino.close()