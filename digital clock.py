import tkinter as tk
from time import strftime

def time_update():
    current_time = strftime('%I:%M:%S %p')
    label.config(text=current_time)
    label.after (1000, time_update)
root = tk.Tk()
root.title("Digital Clock")
label = tk.Label(root, font=('calibri', 60, 'bold'), background='black', foreground='white')
label.pack(pady=20)
time_update()
root.mainloop()
