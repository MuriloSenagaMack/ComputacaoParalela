#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
  int shmid;
  int size = sizeof(int);
  char path[] = "./";
  key_t key;
  key = ftok(path, 'x');
  int *data; // Ponteiro para a área de memória compartilhada

  shmid = shmget(key, size, 0644 | IPC_CREAT | IPC_EXCL); //criação da memória compartilhada

  if (shmid == -1) { //Verificação se a memória compartilhada foi criada
    perror("Erro shmget()");
    exit(1);
  }

  data = (int *)shmat(shmid, NULL, 0);

  *data = 1;

  printf("Valor inicial da variável processo pai: %d\n", *data);

  pid_t pid = fork();

  if (pid < 0) {
    perror("Erro fork()");
    exit(1);
  }

  if (pid == 0) {
    *data += 2;
    printf("Valor memória compartilhada com processo filho add 2 = %d\n", *data);

    return 0;
  }

  wait(NULL);

  *data *= 4;

  printf("Valor memoria compartilhada com processo pai mult 4 = %d\n", *data);

  if (shmctl(shmid, IPC_RMID, NULL) == -1) {
    perror("Erro shmctl()");
    exit(1);
  }

  exit(0);
}
