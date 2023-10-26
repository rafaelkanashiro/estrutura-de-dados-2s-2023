#include <stdio.h>

// Função para contar a quantidade de ocorrências de um elemento em um array
int conta_int_array(int array[], int tamanho, int busca) {
    int contador = 0;
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == busca) {
            contador++;
        }
    }
    return contador;
}

int main() {
    int tamanho;
    printf("Informe o tamanho do array de inteiros: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Tamanho inválido.\n");
        return 1; // Saída de erro
    }

    int array[tamanho];

    printf("Informe os elementos do array de inteiros:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int busca;
    printf("Informe o número de busca: ");
    scanf("%d", &busca);

    int resultado = conta_int_array(array, tamanho, busca);

    printf("Quantidade de vezes que o número %d aparece no array: %d\n", busca, resultado);

    return 0;
}

