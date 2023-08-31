#include <stdio.h>

void transposta(int original[][3], int transposed[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = original[i][j];
        }
    }
}

void PrintMatriz(int matrix[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 3;  
    int cols = 3;  
  
    int originalMatrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int transposedMatrix[3][3];  
  
    printf("Matriz original:\n");
    PrintMatriz(originalMatrix, rows, cols);
    
    transposta(originalMatrix, transposedMatrix, rows, cols);
    printf("\nMatriz transposta:\n");
    PrintMatriz(transposedMatrix, cols, rows);
    
    return 0;
}
