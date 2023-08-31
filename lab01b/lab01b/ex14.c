#include <stdio.h>
#include <string.h>


void inserirCaractere(char *string, int posicao, char caractere) {
    int comprimento = strlen(string);

    if (posicao < 0 || posicao > comprimento) {
        printf("Posição inválida.\n");
        return;
    }

    for (int i = comprimento; i >= posicao; i--) {
        string[i + 1] = string[i];
    }

    string[posicao] = caractere; 
}

int main() {
    char minhaString[100] = "Exemplo";
    int posicaoAInserir = 6; 
    char caractereAInserir = 'a';

    printf("String original: %s\n", minhaString);

    inserirCaractere(minhaString, posicaoAInserir, caractereAInserir);

    printf("String após inserção do caractere: %s\n", minhaString);

    return 0;
}
