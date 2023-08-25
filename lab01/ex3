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
/* Output:
 1  2  3  4  5  6  7  8  9 
    3  4  5  6  7  8  9 
       5  6  7  8  9 
          7  8  9 
             9 
*/
