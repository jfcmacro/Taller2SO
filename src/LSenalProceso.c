/* SenalProceso.c */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#define TIMEOUT 30 

/**
 * Codigo manejador de señales
 */
void
manejador(int senal) {

  fprintf(stderr, "Llego: %d\n", senal);

}

int
main(int argc, char *argv[]) {

  /**
   * Establece los manejadores de señales
   */

  signal(SIGINT, manejador);
  signal(SIGQUIT, manejador);
  signal(SIGTERM, manejador);

   /**
   * Entra en un ciclo infinito esperando ser
   * terminado
   */
  for (;;) {
    fprintf(stdout, "Esperando senal\n");
    sleep(TIMEOUT);
  } 
}
