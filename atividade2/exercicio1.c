#include <stdio.h>

// Função para calcular a soma dos elementos de um array
int soma_array(int array[], int tamanho) {
    int soma = 0;

    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }

    return soma;
}

int main() {
    int tamanho;
    printf("Informe o tamanho do array: ");
    scanf("%d", &tamanho);

    int array[tamanho];

    printf("Informe os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int resultado = soma_array(array, tamanho);

    printf("Soma dos elementos do array: %d\n", resultado);

    return 0;
}
