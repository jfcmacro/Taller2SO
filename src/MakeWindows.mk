all: WCreateProcess

CreateProcess: WCreateProcess.c
	gcc -o $@ $< 