#include <stdio.h>
#include <string.h>

int encontrarCaractere(const char *string, char caractere) {
    int comprimento = strlen(string);
    
    for (int i = 0; i < comprimento; i++) {
        if (string[i] == caractere) {
            return i;
        }
    }
    
    return -1; 
}

int main() {
    char minhaString[] = "Exemplo de string";
    char caractereProcurado = 'd';

    int posicao = encontrarCaractere(minhaString, caractereProcurado);

    if (posicao != -1) {
        printf("O caractere '%c' foi encontrado na posição %d da string.\n", caractereProcurado, posicao);
    } else {
        printf("O caractere '%c' não foi encontrado na string.\n", caractereProcurado);
    }

    return 0;
}

