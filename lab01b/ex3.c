#include <stdio.h>

int main() {
    int maxNumero = 9;  
    int espacos = 0;

    for (int i = 1; i <= maxNumero; i += 2) {
        for (int j = 0; j < espacos; j++) {
            printf("   ");
        }
        
        for (int j = i; j <= maxNumero; j++) {
            printf("%2d ", j);
        }

        printf("\n");
        espacos++;
    }
    return 0;
}
