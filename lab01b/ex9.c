#include <stdio.h>
#include <stdlib.h>

void substituirNegativosPorModulo(int matriz[][3], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] < 0) {
                matriz[i][j] = abs(matriz[i][j]);
            }
        }
    }
}

int main() {
    int matriz[3][3] = {{1, -2, 3},
                        {-4, 5, -6},
                        {7, -8, 9}};

    substituirNegativosPorModulo(matriz, 3, 3);

    printf("\nMatriz após substituição:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

