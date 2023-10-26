#include <stdio.h>

// Função para encontrar o menor e o maior elemento de um array
void menor_maior_array(int array[], int tamanho, int *menor, int *maior) {
    if (tamanho <= 0) {
        *menor = *maior = 0;
        return;
    }

    *menor = *maior = array[0];

    for (int i = 1; i < tamanho; i++) {
        if (array[i] < *menor) {
            *menor = array[i];
        }
        if (array[i] > *maior) {
            *maior = array[i];
        }
    }
}

int main() {
    int tamanho;
    printf("Informe o tamanho do array: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Tamanho inválido.\n");
        return 1; // Saída de erro
    }

    int array[tamanho];

    printf("Informe os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int menor, maior;
    menor_maior_array(array, tamanho, &menor, &maior);

    printf("Menor elemento do array: %d\n", menor);
    printf("Maior elemento do array: %d\n", maior);

    return 0;
}
