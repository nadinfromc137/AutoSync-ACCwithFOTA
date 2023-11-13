import tkinter as tk
from tkinter import ttk
import serial
from time import sleep

# Configure the serial port settings
port = "/dev/ttyS0"  
baudrate = 9600  

# Open the serial port
ser = serial.Serial(port, baudrate)

def on_FOTA_selected():
    
    data=4
    ser.write(bytes([data]))
    ser.flush()

    received=ser.read()
    print(received)
    if(received=='k'):
       print(received)
           
       
       # Read the hex file
       hex_file_path ="ACC_FOTA_BREAKING_.hex"  
       with open(hex_file_path, "r") as file:
    
            i=0
            while True:
              char = file.read(1)
              print(char)
              byte_data = char.encode("utf-8")
              ser.write(byte_data)
              sleep(0.03)
              if char=='\n':
                sleep(0.03)
                receive=ser.read()
                print(receive)
                if receive=='ok':
                   continue
                else:
                   sleep(0.03)
                   continue
         
              ser.flush()
              if not char:
                break
        
       print("Done")



    



def on_speed_selected():
    selected_speed = speed_combobox.get() 
     
    if selected_speed=="0":
     data=0
    
     ser.write(bytes([data]))
     ser.flush()
     print("Selected speed:", selected_speed)
    elif selected_speed=="30":
     data=3
     
     ser.write(bytes([data]))
     ser.flush()
     print("Selected speed:", selected_speed)
    elif selected_speed=="60":
     data=6
     
     ser.write(bytes([data]))
     ser.flush()
     print("Selected speed:", selected_speed)
    elif selected_speed=="90":
     data=9
     
     ser.write(bytes([data]))
     ser.flush()
     print("Selected speed:", selected_speed)
def on_acc_selected():
    selected_acc = acc_combobox.get()
    if selected_acc=="Adaptive":
     data=1
     
     ser.write(bytes([data]))
     ser.flush()
     print("Selected ACC:", selected_acc)
    elif selected_acc=="Normal":
     data=2
     ser.write(bytes([data])) 
     ser.write(data)
     ser.flush()
     print("Selected ACC:", selected_acc)
    elif selected_acc=="Cruise Control OFF":
     data=5
     
     ser.write(bytes([data]))
     ser.flush()
     print("Selected ACC:", selected_acc)

# Create the main window
window = tk.Tk()
window.title("GUI with Speed and ACC Selection")
window.geometry("300x200")
window.configure(background='#213363')

# Apply a custom font to the title
title_font = ("Arial", 20, "bold")

# Title label
title_label = ttk.Label(window, text="AutoSync", font=title_font, foreground="white", background="#213363")
title_label.pack(pady=50)


# ACC selection
acc_label = ttk.Label(window, text="Cruise Control Mode:")
acc_label.pack(pady=10)

acc_combobox = ttk.Combobox(window, values=["Adaptive", "Normal","Cruise Control OFF"])
acc_combobox.pack(pady=2)


acc_button = ttk.Button(window, text="Select", command=on_acc_selected)
acc_button.pack(pady=5)

# Speed selection
speed_label = ttk.Label(window, text="Select Speed:" )
speed_label.pack(pady=10)

speed_combobox = ttk.Combobox(window, values=["0", "30", "60","90"])
speed_combobox.pack(pady=2)

speed_button = ttk.Button(window, text="Select", command=on_speed_selected)
speed_button.pack(pady=5)


#FOTA selection
FOTA_button = ttk.Button(window, text="Update New Version", command=on_FOTA_selected)
FOTA_button.place(x=440,y=400)
acc_button.pack(pady=10)

# Start the main event loop
window.mainloop()


#speed_0-->0x00
#speed_30-->0x30
#speed_60-->0x60
#speed_90-->0x90

#adaptive_mode-->0x01  

#normal_mode-->0x02  

#ACC_OFF-->0x03

