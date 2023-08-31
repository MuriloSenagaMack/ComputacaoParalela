#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
    float peso;
    float altura;
};

int main() {
    struct Pessoa pessoas[3] = {
        {"Joao", 25, 60.5, 165.0},
        {"Roberta", 30, 75.2, 180.5},
        {"Julio", 22, 55.0, 160.0}
    };

    printf("Dados das pessoas:\n");
    for (int i = 0; i < 3; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Peso: %.2f kg\n", pessoas[i].peso);
        printf("Altura: %.2f cm\n", pessoas[i].altura);
        printf("\n");
    }

    return 0;
}
