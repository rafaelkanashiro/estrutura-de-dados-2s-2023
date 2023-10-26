#include "bubble_sort.h"

void bubble_sort(char *array[], int size) {
    char *temp;
    int swapped;

    for (int i = 0; i < size - 1; i++) {
        swapped = 0; // Flag para otimização
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(array[j], array[j + 1]) > 0) {
                // Troque as palavras se estiverem fora de ordem
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1; // Indique que houve uma troca
            }
        }

        // Se não houve troca na última passagem, as palavras estão ordenadas
        if (swapped == 0) {
            break;
        }
    }
}

