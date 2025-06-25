/*********************************************************************************
Tema: SISTEMA DE GERENCIAMENTO DE REGISTROS GENERICO
Professor: Alexandre Carlos Brandão Ramos
Membros da equipe: Camily Perroni, Israel P. Gomes, Letícia Carvalho e Rhadija Dib
Turma: 04
Horarios: 2M45 4M23

Objetivo:
Implementar um sistema de gerenciamento de registros generico em C,
incluindo funcionalidades de Cadastro, Listagem, Pesquisa, Exclusao,
Alteracao e Geracao de Relatorios.

*********************************************************************************/


#include <stdio.h>    // Para funcoes de entrada/saida como printf, scanf
#include <string.h>   // Para funcoes de manipulacao de strings como strcmp, strcpy

// Definicão da estrutura para armazenar os dados de cada Registro
typedef struct {
    long int id;               // Identificador unico do registro
    char descricao_nome[100];  // Nome/descricao do registro
    int campo_num1_int;        // Primeiro campo numerico inteiro
    float campo_num2_float;    // Segundo campo numerico real
    float campo_calculado;     // Campo calculado (campo_num1_int * campo_num2_float)
} Registro;

// Variável global para controlar a quantidade de registros cadastrados
// Em um sistema real, o tamanho poderia ser gerenciado dinamicamente ou passado como parametro.
// Para fins de prova, uma variavel global é comum para simplificar.
int tam = 0; // 'tam' e a quantidade de registros que ja foram cadastrados.

// Funcao para limpar o buffer de entrada do teclado
// Essencial apos o uso de scanf para evitar problemas com caracteres de nova linha pendentes
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funcao para verificar se uma Descricao/Nome ja existe no sistema
// Recebe o array de registros e a descricao a ser procurada
// Retorna 1 se o nome existir, 0 caso contrario
int existeDescricaoNome(Registro reg[], const char *nome_procurado) {
    for (int i = 0; i < tam; i++) {
        // Compara as strings (nomes/descricoes)
        if (strcmp(reg[i].descricao_nome, nome_procurado) == 0) {
            return 1; // Nome/Descricao encontrado
        }
    }
    return 0; // Nome/Descricao nao encontrado
}

// Funcao para verificar se um ID ja existe no sistema
// Recebe o array de registros e o ID a ser procurado
// Retorna 1 se o ID existir, 0 caso contrario
int existeID(Registro reg[], long int id_procurado) {
    for (int i = 0; i < tam; i++) {
        if (reg[i].id == id_procurado) {
            return 1; // ID encontrado
        }
    }
    return 0; // ID nao encontrado
}

// Funcao para listar todos os registros cadastrados no sistema
// Recebe o array de registros
void listar(Registro reg[]) {
    if (tam == 0) {
        printf("Nenhum registro cadastrado no sistema.\n");
        return; // Sai da funcao se nao houver registros
    }

    printf("\n--- LISTAGEM DE REGISTROS CADASTRADOS ---\n");
    for (int i = 0; i < tam; i++) {
        printf("\nIdentificador: %li", reg[i].id);
        printf("\nDescricao/Nome: %s", reg[i].descricao_nome);
        printf("\nCampo Numerico 1 (Int): %d", reg[i].campo_num1_int);
        printf("\nCampo Numerico 2 (Real): %.4f", reg[i].campo_num2_float);
        // Recalcula o campo calculado para garantir que esta atualizado
        reg[i].campo_calculado = reg[i].campo_num1_int * reg[i].campo_num2_float;
        printf("\nCampo Calculado: %.4f\n", reg[i].campo_calculado);
    }
    printf("--- FIM DA LISTAGEM ---\n");
}

// Funcao para pesquisar e exibir os detalhes de um registro por ID
// Recebe o array de registros
void pesquisar(Registro reg[]) {
    long int temp_id;
    int found = 0; // Flag para indicar se o registro foi encontrado

    if (tam == 0) {
        printf("Nenhum registro cadastrado no sistema.\n");
        return;
    }

    printf("Pesquise por um registro inserindo seu ID: ");
    scanf("%li", &temp_id);
    clearInputBuffer(); // Limpa o buffer apos scanf

    for (int i = 0; i < tam; i++) {
        if (reg[i].id == temp_id) {
            printf("\n--- REGISTRO ENCONTRADO ---\n");
            printf("Identificador: %li\n", reg[i].id);
            printf("Descricao/Nome: %s\n", reg[i].descricao_nome);
            printf("Campo Numerico 1 (Int): %d\n", reg[i].campo_num1_int);
            printf("Campo Numerico 2 (Real): %.4f\n", reg[i].campo_num2_float);
            reg[i].campo_calculado = reg[i].campo_num1_int * reg[i].campo_num2_float; // Atualiza campo_calculado
            printf("Campo Calculado: %.4f\n", reg[i].campo_calculado);
            printf("--------------------------\n");
            found = 1;
            break; // Sai do loop assim que o registro e encontrado
        }
    }

    if (found == 0) {
        printf("Registro nao encontrado no sistema.\n");
    }
}

// Funcao para excluir um registro do sistema por ID
// Recebe o array de registros
void excluir(Registro reg[]) {
    long int temp_id;
    int found = 0; // Flag para indicar se o registro foi encontrado

    if (tam == 0) {
        printf("Nenhum registro cadastrado no sistema para excluir.\n");
        return;
    }

    printf("Insira o ID do registro que voce deseja excluir: ");
    scanf("%li", &temp_id);
    clearInputBuffer(); // Limpa o buffer apos scanf

    for (int i = 0; i < tam; i++) {
        if (reg[i].id == temp_id) {
            // Desloca os elementos do array para "cobrir" o registro excluido
            for (int j = i; j < tam - 1; j++) {
                reg[j] = reg[j + 1];
            }
            tam--; // Decrementa a quantidade de registros cadastrados
            printf("Registro excluido com sucesso!\n");
            found = 1;
            break; // Sai do loop assim que o registro e excluido
        }
    }
    if (found == 0) {
        printf("Registro nao encontrado no sistema.\n");
    }
}

// Funcao para permitir alterar os dados de um registro existente
// Recebe o array de registros
void alterarRegistro(Registro reg[]) {
    long int temp_id;
    int index_found = -1; // Armazena o indice do registro encontrado

    if (tam == 0) {
        printf("Nenhum registro cadastrado para alterar.\n");
        return;
    }

    printf("Insira o ID do registro que voce deseja alterar: ");
    scanf("%li", &temp_id);
    clearInputBuffer();

    // Procura o indice do registro
    for (int i = 0; i < tam; i++) {
        if (reg[i].id == temp_id) {
            index_found = i;
            break;
        }
    }

    if (index_found == -1) {
        printf("Registro com ID %li nao encontrado no sistema.\n", temp_id);
        return;
    }

    printf("\n--- ALTERANDO REGISTRO: %s (ID: %li) ---\n", reg[index_found].descricao_nome, reg[index_found].id);
    printf("1. Alterar Descricao/Nome\n");
    printf("2. Alterar Campo Numerico 1 (Inteiro)\n");
    printf("3. Alterar Campo Numerico 2 (Real)\n");
    printf("4. Cancelar\n");
    printf("Escolha uma opcao: ");

    int choice;
    scanf("%d", &choice);
    clearInputBuffer();

    switch (choice) {
        case 1: { // Alterar Descricao/Nome
            char nova_descricao[100];
            do {
                printf("Insira a nova descricao/nome do registro: ");
                scanf("%[^\n]", nova_descricao);
                clearInputBuffer();
                // Verifica se o novo nome ja existe (ignorando o proprio registro)
                int nome_existe_outros = 0;
                for (int i = 0; i < tam; i++) {
                    if (i != index_found && strcmp(reg[i].descricao_nome, nova_descricao) == 0) {
                        nome_existe_outros = 1;
                        break;
                    }
                }
                if (nome_existe_outros) {
                    printf("ERRO! Ja existe outro registro com esta descricao/nome. Insira um diferente.\n");
                }
            } while (existeDescricaoNome(reg, nova_descricao) && strcmp(reg[index_found].descricao_nome, nova_descricao) != 0); // Permite manter o proprio nome
            strcpy(reg[index_found].descricao_nome, nova_descricao);
            printf("Descricao/Nome do registro alterado com sucesso!\n");
            break;
        }
        case 2: { // Alterar Campo Numerico 1 (Inteiro)
            int novo_campo1;
            do {
                printf("Insira o novo valor para o Campo Numerico 1 (Inteiro): ");
                scanf("%i", &novo_campo1);
                clearInputBuffer();
                if (novo_campo1 < 0) {
                    printf("Valor invalido! O Campo Numerico 1 nao pode ser negativo.\n");
                }
            } while (novo_campo1 < 0);
            reg[index_found].campo_num1_int = novo_campo1;
            // Recalcula o campo_calculado apos a alteracao
            reg[index_found].campo_calculado = reg[index_found].campo_num1_int * reg[index_found].campo_num2_float;
            printf("Campo Numerico 1 (Inteiro) do registro alterado com sucesso!\n");
            break;
        }
        case 3: { // Alterar Campo Numerico 2 (Real)
            float novo_campo2;
            do {
                printf("Insira o novo valor para o Campo Numerico 2 (Real): ");
                scanf("%f", &novo_campo2);
                clearInputBuffer();
                if (novo_campo2 <= 0.0) {
                    printf("Valor invalido! O Campo Numerico 2 deve ser um numero positivo.\n");
                }
            } while (novo_campo2 <= 0.0);
            reg[index_found].campo_num2_float = novo_campo2;
            // Recalcula o campo_calculado apos a alteracao
            reg[index_found].campo_calculado = reg[index_found].campo_num1_int * reg[index_found].campo_num2_float;
            printf("Campo Numerico 2 (Real) do registro alterado com sucesso!\n");
            break;
        }
        case 4:
            printf("Alteracao cancelada.\n");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }
    printf("---------------------------\n");
}


// Funcao para gerar um relatorio de analise dos registros
// Recebe o array de registros
void gerarRelatorio(Registro reg[]) {
    if (tam == 0) {
        printf("Nenhum registro cadastrado para gerar relatorio.\n");
        return;
    }

    float total_campos_calculados = 0.0;

    // Inicializa com o primeiro elemento para encontrar min/max
    // Se tam > 0, sabemos que reg[0] existe
    Registro reg_maior_campo2 = reg[0];
    Registro reg_menor_campo2 = reg[0];
    Registro reg_maior_campo1 = reg[0];
    Registro reg_menor_campo1 = reg[0];


    printf("\n--- RELATORIO DE ANALISE DE REGISTROS ---\n");

    for (int i = 0; i < tam; i++) {
        // Garante que campo_calculado esta atualizado antes de usar no relatorio
        reg[i].campo_calculado = reg[i].campo_num1_int * reg[i].campo_num2_float;
        total_campos_calculados += reg[i].campo_calculado; // Soma ao valor total dos campos calculados

        // Compara para encontrar o registro com maior e menor Campo Numerico 2 (Real)
        if (reg[i].campo_num2_float > reg_maior_campo2.campo_num2_float) {
            reg_maior_campo2 = reg[i];
        }
        if (reg[i].campo_num2_float < reg_menor_campo2.campo_num2_float) {
            reg_menor_campo2 = reg[i];
        }

        // Compara para encontrar o registro com maior e menor Campo Numerico 1 (Inteiro)
        if (reg[i].campo_num1_int > reg_maior_campo1.campo_num1_int) {
            reg_maior_campo1 = reg[i];
        }
        if (reg[i].campo_num1_int < reg_menor_campo1.campo_num1_int) {
            reg_menor_campo1 = reg[i];
        }
    }

    printf("Total de registros cadastrados: %d\n", tam);
    printf("Soma total dos Campos Calculados: %.4f\n", total_campos_calculados);

    printf("\n--- Estatisticas por Campo Numerico 2 (Real) ---\n");
    printf("Registro com MAIOR Campo Numerico 2:\n");
    printf("  Descricao: %s, ID: %li, Campo Num. 2: %.4f\n", reg_maior_campo2.descricao_nome, reg_maior_campo2.id, reg_maior_campo2.campo_num2_float);
    printf("Registro com MENOR Campo Numerico 2:\n");
    printf("  Descricao: %s, ID: %li, Campo Num. 2: %.4f\n", reg_menor_campo2.descricao_nome, reg_menor_campo2.id, reg_menor_campo2.campo_num2_float);

    printf("\n--- Estatisticas por Campo Numerico 1 (Inteiro) ---\n");
    printf("Registro com MAIOR Campo Numerico 1:\n");
    printf("  Descricao: %s, ID: %li, Campo Num. 1: %d\n", reg_maior_campo1.descricao_nome, reg_maior_campo1.id, reg_maior_campo1.campo_num1_int);
    printf("Registro com MENOR Campo Numerico 1:\n");
    printf("  Descricao: %s, ID: %li, Campo Num. 1: %d\n", reg_menor_campo1.descricao_nome, reg_menor_campo1.id, reg_menor_campo1.campo_num1_int);

    printf("--- FIM DO RELATORIO ---\n");
}


// Funcao principal do programa
int main() {
    int escolha; // Variavel para armazenar a escolha do usuario
    Registro registros[100]; // Array estatico para armazenar ate 100 registros

    // Loop principal do menu, continua ate que o usuario escolha 'Sair' (opcao 7)
    do {
        printf("\n========= MENU PRINCIPAL =========\n");
        printf("1. Cadastrar Novo Registro\n");
        printf("2. Listar Todos os Registros\n");
        printf("3. Pesquisar Registro\n");
        printf("4. Excluir Registro\n");
        printf("5. Alterar Dados do Registro\n");
        printf("6. Gerar Relatorio de Analise\n");
        printf("7. Sair\n");
        printf("==================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        clearInputBuffer(); // Limpa o buffer apos ler a opcao

        // Usa switch-case para executar a funcao correspondente a escolha do usuario
        switch (escolha) {
            case 1:
                // Validações para cadastro de novo registro
                // Validacao para descricao/nome unico
                do {
                    printf("Insira a descricao/nome do registro: ");
                    scanf("%[^\n]", registros[tam].descricao_nome);
                    clearInputBuffer();
                    if (existeDescricaoNome(registros, registros[tam].descricao_nome)) {
                        printf("ERRO! Ja existe um registro com esta descricao/nome. Insira um diferente.\n");
                    }
                } while (existeDescricaoNome(registros, registros[tam].descricao_nome));

                // Validacao para ID unico e positivo
                do {
                    printf("Insira o Identificador (ID) do registro: ");
                    scanf("%li", &registros[tam].id);
                    clearInputBuffer();
                    if (registros[tam].id <= 0) {
                        printf("ID invalido, o ID do registro deve ser um numero inteiro positivo.\n");
                    } else if (existeID(registros, registros[tam].id)) {
                        printf("ERRO! Ja existe um registro com este ID. Insira um numero de ID diferente.\n");
                    }
                } while (registros[tam].id <= 0 || existeID(registros, registros[tam].id));

                // Validacao para Campo Numerico 1 (Inteiro) nao negativo
                do {
                    printf("Insira o valor para o Campo Numerico 1 (Inteiro): ");
                    scanf("%i", &registros[tam].campo_num1_int);
                    clearInputBuffer();
                    if (registros[tam].campo_num1_int < 0) {
                        printf("Valor invalido! O Campo Numerico 1 nao pode ser negativo.\n");
                    }
                } while (registros[tam].campo_num1_int < 0);

                // Validacao para Campo Numerico 2 (Real) positivo
                do {
                    printf("Insira o valor para o Campo Numerico 2 (Real): ");
                    scanf("%f", &registros[tam].campo_num2_float);
                    clearInputBuffer();
                    if (registros[tam].campo_num2_float <= 0.0) {
                        printf("Valor invalido! O Campo Numerico 2 deve ser um numero positivo.\n");
                    }
                } while (registros[tam].campo_num2_float <= 0.0);

                // Calcula o Campo Calculado no momento do cadastro
                registros[tam].campo_calculado = registros[tam].campo_num1_int * registros[tam].campo_num2_float;
                tam++; // Incrementa a quantidade de registros cadastrados
                printf("Registro cadastrado com exito.\n");
                break;
            case 2:
                listar(registros);
                break;
            case 3:
                pesquisar(registros);
                break;
            case 4:
                excluir(registros);
                break;
            case 5:
                alterarRegistro(registros);
                break;
            case 6:
                gerarRelatorio(registros);
                break;
            case 7: // Opcao para sair
                break;
            default:
                printf("Opcao invalida. Insira um numero entre 1 e 7.\n");
                break;
        }
    } while (escolha != 7); // O loop continua enquanto a opcao nao for 'Sair'

    printf("Programa finalizado. Muito obrigado, ate a proxima!\n");

    return 0; // Indica que o programa terminou com sucesso
}
