#include <stdio.h>

// Função para multiplicar elementos de dois arrays e armazenar o resultado em um terceiro array
void multiplica_array(int array1[], int array2[], int tamanho, int resultado[]) {
    for (int i = 0; i < tamanho; i++) {
        resultado[i] = array1[i] * array2[i];
    }
}

int main() {
    int tamanho;
    printf("Informe o tamanho dos arrays: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Tamanho inválido.\n");
        return 1; // Saída de erro
    }

    int array1[tamanho], array2[tamanho], resultado[tamanho];

    printf("Informe os elementos do primeiro array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array1[i]);
    }

    printf("Informe os elementos do segundo array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array2[i]);
    }

    multiplica_array(array1, array2, tamanho, resultado);

    printf("Resultado da multiplicação dos arrays:\n[");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", resultado[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}

