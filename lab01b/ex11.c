#include <stdio.h>

void somarLinhasEAtualizar(int matriz[][3], int colunas, int L1, int L2) {
    for (int j = 0; j < colunas; j++) {
        matriz[L2][j] += matriz[L1][j];
    }
}

void multiplicarLinhasEAtualizar(int matriz[][3], int colunas, int L1, int L2) {
    for (int j = 0; j < colunas; j++) {
        matriz[L2][j] *= matriz[L1][j];
    }
}

int main() {
    int matriz[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    somarLinhasEAtualizar(matriz, 3, 0, 1);
    multiplicarLinhasEAtualizar(matriz, 3, 1, 2); 

    printf("\nMatriz após soma e multiplicação de linhas:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

