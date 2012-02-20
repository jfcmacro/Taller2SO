#include <stdio.h>
#include <unistd.h>

#define TIMEOUT 30 

int
main(int argc, char *argv[]) {
  
  int valor;

  /**
   * Entra en un ciclo infinito esperando ser
   * terminado
   */
  for (;;) {
    fprintf(stdout, "Esperando señal\n");
    sleep(TIMEOUT);
  }
}
