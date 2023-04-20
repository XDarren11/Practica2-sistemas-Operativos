#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>

int main(void) {

  int pid, estado;
  char programa[20];
  bool repeat = true;
  char exit[] = "exit";

  //poner el ciclo aqui
  while (repeat == true) {

    printf("$");
    scanf("%s", programa);

    if(strcmp(exit,programa)==0){
      _exit(1);
    }

    pid = fork();

    if (programa[0] != '\0') {

      if(pid == -1) {
        printf("Error en fork");
        _exit (-1);
      }
      if(pid==0) {
        execlp(programa,programa,NULL);
        printf("Error el archivo no existe o no es un archivo ejecutable \n");
      }
      else
      {
        wait(NULL);
      }
    }
  }
}
