all: WCreateProcess

CreateProcess: WCreateProcess.c
	$(CC) -o $@ $< 
