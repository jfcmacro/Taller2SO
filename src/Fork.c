/* fork.c */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {

  pid_t pid;  /* ID de proceso del proceso hijo */
  
  pid = fork();  /* Crea un nuevo proceso */
  
  if (pid == (pid_t)(-1)) { 
    fprintf(stderr, "%s, Fallo al hacer el fork\n", 
	    strerror(errno));
    exit(13);
  }
  else if (pid == 0) {
    fprintf(stdout, "PID: %ld: El proceso hijo iniciado, el padre es %ld.\n",
	    (long) getpid(),  /* Identificador del proceso hijo */
	    (long) getppid()); /* Identificador del proceso padre */
  }
  else {
    fprintf(stdout, "PID: %ld: PID del hijo iniciado: %ld.\n",
	    (long) getpid(),  /* PID del padre actual */
	    (long) pid);      /* PID del hijo */
  }

  sleep(1);
  return 0;
}
