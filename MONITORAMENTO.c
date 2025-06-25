/*********************************************************************************

Tema: SISTEMA DE MONITORAMENTO E ANÁLISE DE PRODUÇÃO INDUSTRIAL

Professor: Alexandre Carlos Brandão Ramos
Membros da equipe: Camily Perroni, Israel P. Gomes, Letícia Carvalho e Rhadija Dib
Turma: 04
Horários: 2M45 4M23

*********************************************************************************/


#include <stdio.h>
#include <string.h>

typedef struct {
char nome [100];
long int id;
int qtd;
float vun;
float vto;
} cadastro;

int tam = 0; // 'tam' é a quantidade de peças que já foram cadastradas.



void clearInputBuffer() {
int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int existeNome(cadastro cad[], const char*nome_procurado) {
    for (int i = 0; i < tam; i++) {
        if (strcmp(cad[i].nome, nome_procurado) == 0) {
            return 1;
        }
    }
    return 0;
}


int existeID(cadastro cad[], long int id_procurado) {
    for (int i = 0; i < tam; i++) {
        if (cad[i].id == id_procurado)
        {
            return 1;
        }
    }
    return 0;
}


void listar (cadastro cad[]) {
    for (int i = 0; i < tam; i++) {
        printf ("\nID peça: %li", cad[i].id);
        printf ("\nNome: %s", cad[i].nome);
        printf ("\nQuantidade: %d", cad[i].qtd);
        printf ("\nValor unitário: %.4f", cad[i].vun);
        cad[i].vto = cad[i].qtd * cad[i].vun;
        printf ("\nValor total: %.4f\n", cad[i].vto);
        }
        if (tam == 0) printf ("Nenhuma peça cadastrada no sistema.\n");
}    


void pesquisar (cadastro cad[]) {
long int temp;
int found = 0;
        
    if (tam == 0)
    {
    printf ("Nenhuma peça cadastrada no sistema.\n");
    return;
    }
        printf ("Pesquise por uma peça inserindo seu ID: ");
        scanf ("%li", &temp);
        clearInputBuffer();
            
        for (int i = 0; i < tam; i++) {
            if (cad[i].id == temp) {
            printf ("\nID peça: %li", cad[i].id);
            printf ("\nNome: %s", cad[i].nome);
            printf ("\nQuantidade: %d", cad[i].qtd);
            printf ("\nValor unitário: %.4ff\n", cad[i].vun);
            found = 1;
            break;
            }
        }
        
        if (found == 0) 
        {
        printf ("Peça não encontrada no estoque.\n");
        }
}


void excluir (cadastro cad[]) {
long int temp;
int found = 0;

    if (tam == 0) 
    {
    printf ("Nenhuma peça cadastrada no sistema.\n");
    return;
    }
    if (tam > 0) printf ("Insira o ID da peça que você deseja excluir: ");
    scanf ("%li", &temp);
        
    for (int i = 0; i < tam; i++) {
        if (cad[i].id == temp) {
            for (int j = i; j < tam - 1; j++)
            {
            cad[j] = cad[j + 1];
            }
            tam--;
            printf ("Peça excluída!\n");
            found = 1;
            break;
        }
    } if (found == 0) printf ("Peça não encontrada no sistema.\n");
}


int main() {
int E;                  // 'E' advém de escolha.
cadastro cad [100];

    do
    {
        printf ("\n========= MENU PRINCIPAL =========\n1. Cadastrar peça\n2. Listar estoque\n3. Pesquisar peça\n4. Excluir peça\n5. Sair\n==================================\n");
        scanf ("%d", &E);
        clearInputBuffer();
                
        switch (E) {
            case 1:
                do {
                    printf("Insira o nome da peça: ");
                    scanf("%[^\n]", cad[tam].nome);
                    clearInputBuffer();
                    if (existeNome(cad, cad[tam].nome)) { 
                        printf("ERRO! Já existe uma peça com este nome. Insira um nome diferente.\n");
                    }
                } while (existeNome(cad, cad[tam].nome));

                do {
                    printf("Insira o ID da peça: ");
                    scanf("%li", &cad[tam].id);
                    clearInputBuffer();
                    if (cad[tam].id <= 0) {
                        printf("ID inválido, o ID da peça deve ser um maior que zero.\n");
                    } else if (existeID(cad, cad[tam].id)) { 
                        printf("ERRO! Já existe uma peça com este ID. Insira um número de ID diferente.\n");
                    }
                } while (cad[tam].id <= 0 || existeID(cad, cad[tam].id));

                do {
                    printf("Insira o número de peças: ");
                    scanf("%i", &cad[tam].qtd);
                    clearInputBuffer();
                    if (cad[tam].qtd < 0) {
                        printf("Quantidade inválida! O número de peças não pode ser negativo.\n");
                    }
                } while (cad[tam].qtd < 0);
                    
                do {
                    printf("Insira o valor unitário da peça: ");
                    scanf("%f", &cad[tam].vun);
                    clearInputBuffer();
                    if (cad[tam].vun <= 0.0) {
                        printf ("Valor unitário inválido! O valor deve ser um número positivo.\n");
                    }
                } while (cad[tam].vun <= 0.0);

                tam++;
                printf ("Peça cadastrada com êxito.\n");
                break;
            case 2:
                listar(cad);
                break;
            case 3:
                pesquisar(cad);
                break;
            case 4:
                excluir(cad);
                break;
            case 5:
                break;
            default:
                printf ("Opção inválida. Insira um número entre 1 e 5.\n");
                break;
        }
    } while (E != 5);

    printf ("Programa finalizado.\n");

    return 0;
}
