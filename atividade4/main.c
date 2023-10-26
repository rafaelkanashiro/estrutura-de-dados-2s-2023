#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"
#include "bubble_sort.c"

int main() {
    int tamanho;
    printf("Informe o tamanho da lista de números: ");
    scanf("%d", &tamanho);

    int *numeros = (int *)malloc(tamanho * sizeof(int));

    if (numeros == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Informe os números separados por espaços:\n");

    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &numeros[i]);
    }

    // Ordene o array usando o Bubble Sort
    bubble_sort(numeros, tamanho);

    // Imprima os números ordenados
    printf("Saída: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    // Libere a memória alocada
    free(numeros);

    return 0;
}

