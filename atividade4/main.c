#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"
#include "bubble_sort.c"

int main() {
    int tamanho;
    printf("Informe o tamanho da lista de n�meros: ");
    scanf("%d", &tamanho);

    int *numeros = (int *)malloc(tamanho * sizeof(int));

    if (numeros == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        return 1;
    }

    printf("Informe os n�meros separados por espa�os:\n");

    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &numeros[i]);
    }

    // Ordene o array usando o Bubble Sort
    bubble_sort(numeros, tamanho);

    // Imprima os n�meros ordenados
    printf("Sa�da: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    // Libere a mem�ria alocada
    free(numeros);

    return 0;
}

