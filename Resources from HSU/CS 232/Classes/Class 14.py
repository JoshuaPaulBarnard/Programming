#  14CS232T


#Frames, within windows
#Tk = "Toolkit"
#Tcl = Tool Command Language
#Tcl / Tk <-- Ruby, Perl, Python
#
#import tkinter <= tkinter.frame(...)
#from tkinter import * <= frame(...)
#widgets - are placed hierachically.  With a master window (Top Level Widget)
#Master Windows include:  Frame -> buttons, Frame -> Labels, Frame -> Entry Box
#
#
#__________________________________________________



import tkinter
##main_window = tkinter.Tk()
#main_window.title("WOOF")
#main_windw = Tk(bg = 'green')
#main_window = tkinter.Tk(bg = 'green')
#main_window.geometry('400x500')


# Methods and Dictionary Values
# main_window.mainloop()  #execute!
# Tkinter widgets:  Frame = "Pure container" for widgets
# Label - Text or images
# Buttons - Press
# Canvas - Draw images
# Check Buttons - check boxes/buttons.  Allows multiple selections.
# Radio buttons - Circular with solid dot in middle, only allows one selection.
# Object Creation - Parameter is parent object


class F_to_C():
    def __init__(self, master_window):
        self.frame_1 = tkinter.Frame(master_window)
        self.frame_1.grid()
        self.string_out = tkinter.StringVar()
        self.my_buttons()
        self.my_entry_box()
        self.my_labels()

    def my_buttons(self):
        self.convert_button = tkinter.Button(self.frame_1, font=('Helvetica', 20))
        self.convert_button['text'] = "Convert"
        self.convert_button['command'] = self.calculate_and_display
        self.convert_button.grid(row = 1, column = 2)

        self.quit_button = tkinter.Button(self.frame_1, font=('Helvetica', 20))
        self.quit_button['text'] = "QUIT"
        self.quit_button['command'] = self.frame_1.quit
        self.quit_button.grid(row = 1, column = 3)

    def my_labels(self):
        self.frame_1_label_1 = tkinter.Label(self.frame_1, font=('Helvetica', 20))
        self.frame_1_label_1['text'] = "Convert F to C"
        self.frame_1_label_1.grid(row = 0, column = 1)

        self.frame_1_label_2 = tkinter.Label(self.frame_1, font=('Helvetica', 20))
        self.frame_1_label_2['text'] = "Enter Farhenheit"
        self.frame_1_label_2.grid(row = 1, column = 0)

        self.frame_1_label_3 = tkinter.Label(self.frame_1, font=('Helvetica', 20))
        self.frame_1_label_3['text'] = "Celsius value: "
        self.frame_1_label_3.grid(row = 2, column = 0)

        self.frame_1_label_4 = tkinter.Label(self.frame_1, font=('Helvetica', 20))
        self.frame_1_label_4['textvariable'] = self.string_out
        self.frame_1_label_4.grid(row = 2, column = 1)
        
    def my_entry_box(self):
        self.degrees_F_box = tkinter.Entry(self.frame_1, font=('Helvetica', 20))
        self.degrees_F_box['width'] = 10
        self.degrees_F_box.grid(row = 1, column = 1)

    def calculate_and_display(self):
        self.degrees_F_value = float(self.degrees_F_box.get())
        self.degrees_C_result = (self.degrees_F_value - 32.0) * 5.0 / 9.0
        self.string_out.set('{:.1f} degrees Celsius'.format(self.degrees_C_result))

    def try_it(self):
        main_window = tkinter.Tk()
        main_window.title("Convert Fahrenheit to Celsius")
        main_window.geometry("800x200")

        x = F_to_C(main_window)

        main_window.mainloop()
        main_window.destroy()
        
