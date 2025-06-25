/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>


struct ficha_pessoal {
    char nome[50];
    long int tele;  // Número de telefone
};

int main(void) {
    struct ficha_pessoal ficha[30];
    int i;

    for(i = 0; i < 3; i++) {
        printf("Digite seu nome: ");
        scanf(" %[^\n]", ficha[i].nome);  // Espaço antes de %[^\n] consome o newline anterior

        printf("Digite seu telefone: ");
        scanf("%ld", &ficha[i].tele);
    }

    printf("\n--- Dados digitados ---\n");
    for(i = 0; i < 3; i++) {
        printf("Nome: %s | Telefone: %ld\n", ficha[i].nome, ficha[i].tele);
    }

    return 0;
}
