#include <stdio.h>

void MulLin(int matriz[][3], int row, int num, int cols) {
    for (int i = 0; i < cols; i++) {
        matriz[row][i] *= num;
    }
}


void MulCol(int matriz[][3], int col, int num, int rows) {
    for (int i = 0; i < rows; i++) {
        matriz[i][col] *= num;
    }
}

void displayMatrix(int matrix[][3], int rows, int cols) {
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
    
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int rowToMultiply = 1; 
    int colToMultiply = 2; 
    
    int multiplier = 2; 

    MulLin(matrix, rowToMultiply, multiplier, cols);
    printf("\nMatriz após multiplicar a linha %d:\n", rowToMultiply + 1);
    displayMatrix(matrix, rows, cols);
    
    MulCol(matrix, colToMultiply, multiplier, rows);
    printf("\nMatriz após multiplicar a coluna %d:\n", colToMultiply + 1);
    displayMatrix(matrix, rows, cols);
    
    return 0;
}
