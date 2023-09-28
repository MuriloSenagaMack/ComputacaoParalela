#include <stdio.h>
#include <stdlib.h>

#define m 8
#define n 8

float A[m][n];
float x[m] = {5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0};
float y[n];

void PreencherMatrizA() {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      A[i][j] = (i * n + j) + 1.0;
    }
  }
}

void MultMatriz() {
  for (int i = 0; i < m; i++) {
    y[i] = 0.0; 
    for (int j = 0; j < n; j++) {
      y[i] += A[i][j] * x[j];
    }
  }
}

int main() {
  PreencherMatrizA();
  MultMatriz();

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
  return 0;
}

