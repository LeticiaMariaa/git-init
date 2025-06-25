#include <stdio.h>
#include <stdlib.h>

// Função para calcular o determinante de uma matriz de qualquer dimensão
int calcular_determinante(int **matriz, int n) {
    if (n == 1) {
        return matriz[0][0];
    }
    if (n == 2) {
        return (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
    }

    int det = 0;
    int **submatriz = (int **)malloc((n - 1) * sizeof(int *));
    for (int i = 0; i < n - 1; i++) {
        submatriz[i] = (int *)malloc((n - 1) * sizeof(int));
    }

    for (int coluna = 0; coluna < n; coluna++) {
        // Criar a submatriz
        for (int i = 1; i < n; i++) {
            int sub_coluna = 0;
            for (int j = 0; j < n; j++) {
                if (j == coluna) continue;
                submatriz[i - 1][sub_coluna] = matriz[i][j];
                sub_coluna++;
            }
        }

        // Expansão de Laplace
        int sinal = (coluna % 2 == 0) ? 1 : -1;
        det += sinal * matriz[0][coluna] * calcular_determinante(submatriz, n - 1);
    }

    // Liberar memória alocada para a submatriz
    for (int i = 0; i < n - 1; i++) {
        free(submatriz[i]);
    }
    free(submatriz);

    return det;
}

int main() {
    int n;

    printf("Digite a ordem da matriz quadrada: ");
    scanf("%d", &n);

    // Alocar memória para a matriz
    int **matriz = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }

    // Ler a matriz
    printf("Digite os elementos da matriz %dx%d (linha por linha):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Calcular o determinante
    int determinante = calcular_determinante(matriz, n);
    printf("O determinante da matriz é: %d\n", determinante);

    // Liberar memória alocada para a matriz
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
