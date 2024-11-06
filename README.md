BackTrack-Quest: README
Project Overview
BackTrack-Quest is an interactive GUI application built using Python’s Tkinter library to visually present solutions to backtracking algorithms. It includes implementations for the N-Queens and Sum of Subsets problems, each of which can be executed through a user-friendly interface.

1. Prerequisites
Python 3: Ensure that Python 3 is installed.
Tkinter: This should come with Python by default, but if not, install it with:
bash
Copy code
pip install tk
Compiled Executables: The project requires subsets.exe and nqueens.exe to execute the Sum of Subsets and N-Queens algorithms. If not present, compile them using a C compiler.

2. Installation
Clone this repository to your local machine:
bash
Copy code
git clone https://github.com/your-username/BackTrack-Quest.git
Ensure that subsets.exe and nqueens.exe are located in the same directory as the program_gui.py file or provide their correct path in the script.

3. Usage
Run the main Python script:
bash
Copy code
python program_gui.py
The GUI will open with options to select either the Sum of Subsets or the N-Queens Problem.

4. Code Overview
Main GUI File (program_gui.py)
This file sets up the GUI interface and manages the execution of the C-based backtracking algorithms.

Components of program_gui.py:

Imports:

tkinter as tk: Used for creating the graphical interface.
messagebox: Provides popup dialogs for errors.
subprocess: Allows running the C executables.
threading: Runs each executable in a separate thread to keep the GUI responsive.
Functions:

run_subsets() and run_nqueens(): Create new threads to call respective algorithms.
execute_subsets() and execute_nqueens(): Use subprocess.Popen to start each executable in a separate command window.
python
Copy code
subprocess.Popen(['start', 'cmd', '/k', 'subsets.exe 1 2 3'], shell=True)
The N-Queens problem is started similarly with nqueens.exe.
GUI Setup:

Root Window: Configures the main application window with size, title, and color.
Icons: Optional icons (subsetIcon.png, chessIcon.png) are used for each button.
Buttons: Buttons for each problem, styled with custom fonts, colors, and associated icons, linked to their respective functions (run_subsets, run_nqueens).
Executable C Programs
subsets.c:

Implements a backtracking solution to the Sum of Subsets problem.
Input example: [1, 2, 3], and calculates subsets that meet a specified sum.
nqueens.c:

Solves the N-Queens problem using backtracking.
Input example: an integer for board size, and outputs all possible solutions where no queens threaten each other.
Both executables should be named subsets.exe and nqueens.exe respectively for proper execution from the GUI.

5. Running the Project
Run program_gui.py using Python.
Choose the problem you wish to solve (either Sum of Subsets or N-Queens).
Each selection opens a new terminal window that runs the corresponding algorithm.
If any error occurs, a popup message box will appear with details.

6. Known Issues
Icons Not Found: If subsetIcon.png or chessIcon.png is missing, an error message will appear, but the program will continue to run.
File Paths: Ensure subsets.exe and nqueens.exe are accessible from the script’s directory or specify the correct path.
