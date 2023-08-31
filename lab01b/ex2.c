#include <stdio.h>

int main() {
    float N1 = 7.5, N2 = 8.0, N3 = 6.5, ME = 9.0, MA;
    
    MA = (N1 + N2 * 2 + N3 * 3 + ME) / 7;
    
    char conceito;
    if (MA >= 9) {
        conceito = 'A';
    } else if (MA >= 7.5) {
        conceito = 'B';
    } else if (MA >= 6) {
        conceito = 'C';
    } else if (MA >= 4) {
        conceito = 'D';
    } else {
        conceito = 'E';
    }
    
    printf("Média de Aproveitamento: %.2f\nConceito: %c", MA, conceito);
    
    return 0;
}
