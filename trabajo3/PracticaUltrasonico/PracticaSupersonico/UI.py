import tkinter as tk
import serial

def init():
    arduino.write(b"a") #b es de bits y lo de comillas es la letra cruda

def fin():
    arduino.write(b"b") #b es de bits y lo de comillas es la letra cruda



arduino = serial.Serial("COM3", 9600) #9600 es la frecuencia para el arduino

window = tk.Tk()
window.geometry("400x100") #Tamaño de la ventana

bttn = tk.Button(window, text="Encender", command=init) #Agregar botón con el texto y el destroy cierra la ventana
bttn.place(x=200, y=0) #Posicionar el botón

bttn_down = tk.Button(window, text="Apagar", command=fin)
bttn_down.place(x=280, y=0) #Posicionar el botón

window.mainloop() #Mostrar todo lo anterior