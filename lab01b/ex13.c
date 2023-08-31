#include <stdio.h>
#include <string.h>

void removerCaractere(char *string, int posicao) {
    int comprimento = strlen(string);

    if (posicao < 0 || posicao >= comprimento) {
        printf("Posição inválida.\n");
        return;
    }

    for (int i = posicao; i < comprimento - 1; i++) {
        string[i] = string[i + 1];
    }

    string[comprimento - 1] = '\0';
}

int main() {
    char minhaString[] = "Exemplo";
    int posicaoARemover = 1; 
    
    printf("String original: %s\n", minhaString);
    
    removerCaractere(minhaString, posicaoARemover);

    printf("Output: %s\n", minhaString);

    return 0;
}
