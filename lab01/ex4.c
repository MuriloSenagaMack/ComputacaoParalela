#include <stdio.h>
#include <string.h>

int main() {
    char nome1[] = "Eduardo";
    char nome2[] = "Monica";
    
    int compareResult = strcmp(nome1, nome2);
    
    if (compareResult < 0) {
        printf("Nomes em ordem alfabética: %s, %s\n", nome1, nome2);
    } else if (compareResult > 0) {
        printf("Nomes em ordem alfabética: %s, %s\n", nome2, nome1);
    } else {
        printf("Os nomes são iguais.\n");
    }

    return 0;
}

//Output: Nomes em ordem alfabética: Eduardo, Monica

