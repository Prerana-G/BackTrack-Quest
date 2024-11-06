import tkinter as tk
from tkinter import messagebox
import subprocess
import threading

def run_subsets():
    threading.Thread(target=execute_subsets).start()

def execute_subsets():
    try:
        subprocess.Popen(['start', 'cmd', '/k', 'subsets.exe 1 2 3'], shell=True)
    except Exception as e:
        messagebox.showerror("Error", str(e))

def run_nqueens():
    threading.Thread(target=execute_nqueens).start()

def execute_nqueens():
    try:
        subprocess.Popen(['start', 'cmd', '/k', 'nqueens.exe'], shell=True)
    except Exception as e:
        messagebox.showerror("Error", str(e))

#Main window
root = tk.Tk()
root.title("ADA Mini Project: BACKTRACKING")
root.geometry("800x500")  
root.configure(bg="#c8d9e6")

try:
    subsets_icon = tk.PhotoImage(file="subsetIcon.png")
    nqueens_icon = tk.PhotoImage(file="chessIcon.png")
except Exception as e:
    messagebox.showerror("Error", f"Icon not found: {e}")

welcome_label = tk.Label(root, text="Welcome!\n Which Problem would you like to solve?",
                         font=("Palatino Linotype", 20, "bold"), bg="#c8d9e6", fg="#374375", pady=20)
welcome_label.pack(pady=50)

button_frame = tk.Frame(root, bg="#babde2")
#alternate color#7481ab
button_frame.pack(pady=20)

subsets_button = tk.Button(button_frame, text="Sum of Subsets", command=run_subsets,
                           font=("Palatino Linotype", 18), bg="#edd6cc", fg="#013d5a",
                           activebackground="#dfaea1", padx=20, pady=10, relief="raised", bd=5,
                           compound="left", image=subsets_icon)
subsets_button.grid(row=0, column=0, padx=20, pady=20)

nqueens_button = tk.Button(button_frame, text="Nqueens Problem", command=run_nqueens,
                           font=("Palatino Linotype", 18), bg="#edd6cc", fg="#013d5a",
                           activebackground="#dfaea1", padx=20, pady=10, relief="raised", bd=5,
                           compound="left", image=nqueens_icon)
nqueens_button.grid(row=0, column=1, padx=20, pady=20)

root.mainloop()
