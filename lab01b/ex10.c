#include <stdio.h>

void multiplicarLinhaPorNumero(int matriz[][3], int linha, int colunas, int numero) {
    for (int j = 0; j < colunas; j++) {
        matriz[linha][j] *= numero;
    }
}

void multiplicarColunaPorNumero(int matriz[][3], int linhas, int coluna, int numero) {
    for (int i = 0; i < linhas; i++) {
        matriz[i][coluna] *= numero;
    }
}

int main() {
    int matriz[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    multiplicarLinhaPorNumero(matriz, 1, 3, 2);  
    multiplicarColunaPorNumero(matriz, 3, 2, 3); 

    printf("\nMatriz após multiplicação de linha e coluna:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
