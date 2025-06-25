/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <string.h>


struct ficha_pessoal {
    char nome[50];
    long int matri;
   // float h\h;
    //int salario; // Número de telefone
};

int opcao;
int main(void) {
    struct ficha_pessoal ficha[30];
    int i;
    //salario = 
do {
    printf(" --- Controle de horas trabalhadas ---\n");
    printf(" --- 0. Sair --- \n");
    printf(" --- 1. Inserir --- \n");
    printf(" --- 2. Alterar --- \n");
    printf(" --- 3. Pesquisar --- \n");
    printf(" --- 5. Listar --- \n");
    printf(" --- 5. Excluir --- \n");
    printf("Sua opção: ");
    scanf("%d",&opcao);
    
switch(opcao){
    case 0: printf("Até a próxima!\n");
        break;
    case 1: //Inserir();
        break;
    case 2: //Alterar();
       break;
    case 3: //Pesquisar();
       break;
    case 4: //Listar();
       break;
    case 5: //Excluir();
       break;
    default: printf("Opção inválida\n");
}
  } while (opcao != 0);
    
        return 0;
}
/*}
    for(i = 0; i < 3; i++) {
        printf("Digite seu nome: ");
        scanf(" %[^\n]", ficha[i].nome);  // Espaço antes de %[^\n] consome o newline anterior

        printf("Digite seu numero de matricula: ");
        scanf("%ld", &ficha[i].matri);
    }

    printf("\n--- Dados digitados ---\n");
    for(i = 0; i < 3; i++) {
        printf("Nome: %s | Matricula: %ld\n", ficha[i].nome, ficha[i].matri);
    }

    return 0;
}*/
