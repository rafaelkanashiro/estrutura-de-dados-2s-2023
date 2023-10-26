#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para verificar se uma string de busca existe em um array de strings
int busca_string(char *array[], int tamanho, char *busca) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(array[i], busca) == 0) {
            return 1; // A string de busca foi encontrada no array
        }
    }
    return 0; // A string de busca não foi encontrada no array
}

int main() {
    int tamanho;
    printf("Informe o tamanho do array de strings: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Tamanho inválido.\n");
        return 1; // Saída de erro
    }

    char *array[tamanho];

    printf("Informe os elementos do array de strings:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        char buffer[100]; // Tamanho máximo da string
        scanf("%s", buffer);
        array[i] = strdup(buffer); // Aloca memória e copia a string
    }

    char busca[100]; // Tamanho máximo da string de busca
    printf("Informe a string de busca: ");
    scanf("%s", busca);

    int resultado = busca_string(array, tamanho, busca);

    if (resultado) {
        printf("A string de busca existe no array.\n");
    } else {
        printf("A string de busca não existe no array.\n");
    }

    // Libera a memória alocada para as strings do array
    for (int i = 0; i < tamanho; i++) {
        free(array[i]);
    }

    return 0;
}

