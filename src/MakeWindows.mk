all: CreateProcess

CreateProcess: CreateProcess.c
	gcc -o $@ $< 