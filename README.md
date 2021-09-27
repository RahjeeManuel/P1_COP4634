# Project 1: Processes | CREATING YOUR OWN SHELL

# Compilation
Compiling the program with command:
    make

# Running Executable File
Running the program with command:
    ./myshell

Running the shell in debug mode:
    ./myshell -Debug

# Commands
The prompt $$$ will show, where you can then type in commands in the format:
    $$$ one two three <four >five &

debug mode will show info such as:
InputRedirect: [four]
OutputRedirect: [five]
Background: [1]
ArgumentCount: [6]
ArgumentVector[0]: [one]
ArgumentVector[1]: [two]
ArgumentVector[2]: [three]
ArgumentVector[3]: [<four]
ArgumentVector[4]: [>five]
ArgumentVector[5]: [&]

Exiting program:
    type command <exit>

Removing object files:
    type command <make clean>
