#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define m 8
#define n 8
#define thread_count 8

float A[m][n];
float x[m] = {5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0};
float y[n];

void *Pth_mat_vect(void *rank) {
  long my_rank = (long)rank;
  int i, j;
  int local_m = m / thread_count;
  int my_first_row = my_rank * local_m;
  int my_last_row = (my_rank + 1) * local_m - 1;

  for (i = my_first_row; i <= my_last_row; i++) {
    y[i] = 0.0; // Inicialize y[i] com 0 antes da multiplicação
    for (j = 0; j < n; j++) {
      A[i][j] = (i * n + j) + 1.0;
      y[i] += A[i][j] * x[j]; // Realize a multiplicação da matriz pelo vetor
    }
  }

  return NULL;
}

int main() {
  pthread_t *thread_t;
  long thread;

  thread_t = malloc(thread_count * sizeof(pthread_t));

  for (thread = 0; thread < thread_count; thread++) {
    pthread_create(&thread_t[thread], NULL, Pth_mat_vect, (void *)thread);
  }

  for (thread = 0; thread < thread_count; thread++) {
    pthread_join(thread_t[thread], NULL);
  }

  printf("Matriz A:\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%0.f ", A[i][j]);
    }
    printf("\n");
  }

  printf("\nVetor x:\n");
  for (int i = 0; i < n; i++) {
    if (i < m - 1) {
      printf("%0.f, ", x[i]);
    } else {
      printf("%0.f\n", x[i]);
    }
  }

  printf("\nVetor y:\n");
  for (int i = 0; i < m; i++) {
    if (i < m - 1) {
      printf("%0.f, ", y[i]);
    } else {
      printf("%0.f\n", y[i]);
    }
  }
  printf("\n");
  free(thread_t);
  return 0;
}
 
