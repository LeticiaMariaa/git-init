#include <stdio.h>

int determinante_1x1(int matriz[1][1]) {
    return matriz[0][0];
}

int determinante_2x2(int matriz[2][2]) {
    return (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
}

int determinante_3x3(int matriz[3][3]) {
    int det = 0;
    det = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1]) -
          matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]) +
          matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);
    return det;
}

int main() {
    int ordem;

    printf("Digite a ordem da matriz (1, 2 ou 3): ");
    scanf("%d", &ordem);

    if (ordem == 1) {
        int matriz[1][1];
        printf("Digite o único elemento da matriz 1x1: ");
        scanf("%d", &matriz[0][0]);
        printf("Determinante = %d\n", determinante_1x1(matriz));

    } else if (ordem == 2) {
        int matriz[2][2];
        printf("Digite os 4 elementos da matriz 2x2 (linha por linha):\n");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        printf("Determinante = %d\n", determinante_2x2(matriz));

    } else if (ordem == 3) {
        int matriz[3][3];
        printf("Digite os 9 elementos da matriz 3x3 (linha por linha):\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        printf("Determinante = %d\n", determinante_3x3(matriz));

    } else {
        printf("Ordem inválida! Apenas matrizes de ordem 1, 2 ou 3 são suportadas.\n");
    }

    return 0;
}


/* a pessoa monta a matriz*/

#include <stdio.h>
#include <stdlib.h>

int determinante_2x2(int matriz[2][2]) {
    return (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
}

int determinante_3x3(int matriz[3][3]) {
    int det = 0;
    det = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1]) -
          matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]) +
          matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);
    return det;
}

int main() {
    int linhas, colunas;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    // Garantindo que a matriz seja quadrada para calcular o determinante
    if (linhas != colunas) {
        printf("Somente matrizes quadradas possuem determinante!\n");
        return 1;
    }

    int matriz[linhas][colunas];
    printf("Digite os elementos da matriz %dx%d (linha por linha):\n", linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    if (linhas == 1) {
        printf("Determinante = %d\n", matriz[0][0]);
    } else if (linhas == 2) {
        printf("Determinante = %d\n", determinante_2x2(matriz));
    } else if (linhas == 3) {
        printf("Determinante = %d\n", determinante_3x3(matriz));
    } else {
        printf("Cálculo de determinantes para matrizes maiores que 3x3 não está implementado.\n");
    }

    return 0;
}
