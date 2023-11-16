#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.c"
#include <time.h>

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Portuguese");

    No* lista_nao_ordenada = NULL;
    No* lista_ordenada = NULL;

    FILE* arquivo = fopen("1kk_rand_float.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    clock_t inicio, fim;
    double tempo_nao_ordenada = 0.0, tempo_ordenada = 0.0;
    float numero;

    while (fscanf(arquivo, "%f", &numero) == 1) {
        No* no_nao_ordenado = criar_no(numero, NULL);
        No* no_ordenado = criar_no(numero, NULL);

        inicio = clock();
        inserir_no_lista(&lista_nao_ordenada, no_nao_ordenado);
        fim = clock();
        tempo_nao_ordenada += ((double) (fim - inicio)) / CLOCKS_PER_SEC;

        inicio = clock();
        inserir_no_ordenado(&lista_ordenada, no_ordenado);
        fim = clock();
        tempo_ordenada += ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    }

    fclose(arquivo);

    // Imprimir as listas
    printf("Tempo médio de inserção na lista não ordenada: ");
    imprimir_lista(lista_nao_ordenada);

    printf("\nTempo médio de inserção na lista ordenada: ");
    imprimir_lista(lista_ordenada);

    // Liberar a memória alocada
    liberar_lista(lista_nao_ordenada);
    liberar_lista(lista_ordenada);

    return 0;
}

