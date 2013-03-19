/* DirectorioActual.c */
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {

  int retVal;
  pid_t pid;

  pid = fork();

  if (pid == (pid_t)(-1)) {
    fprintf(stderr, "%s, Fallo al hacer el fork\n",
	    strerror(errno));
    exit(13);
  }
  else if (pid == 0) {
    execl("/bin/ls", "ls", "-l", (char *) 0);
    // No se debe ejecutar este código
    fprintf(stderr, "No pudo ejecutar /bin/ls %s\n", strerror(errno));
  }
  else {
    wait(&retVal);
    // Verifica si el hijo terminó bien
    if (WIFEXITED(retVal)) {
      fprintf(stdout, "El proceso termino bien: %d\n",
	      WEXITSTATUS(retVal));
    }
    else if (WIFSIGNALED(retVal)) { // Fue señalizado
      fprintf(stderr, "La senal capturada: %d\n",
	      WTERMSIG(retVal));
    }
    else if (WIFSTOPPED(retVal)) {
      fprintf(stderr, "El proceso se encuentra parado: %d\n",
	      WSTOPSIG(retVal));
    }
  }
}
