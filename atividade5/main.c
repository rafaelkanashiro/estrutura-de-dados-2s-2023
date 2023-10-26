#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.c"

#define MAX_PALAVRA 100

int main() {
    char nome_arquivo_entrada[MAX_PALAVRA];
    
    printf("Digite o nome do arquivo de palavras: ");
    scanf("%s", nome_arquivo_entrada);

    FILE *arquivo_entrada = fopen(nome_arquivo_entrada, "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nome_arquivo_entrada);
        return 1;
    }

    // Contar o número de palavras no arquivo
    int num_palavras = 0;
    char palavra[MAX_PALAVRA];
    while (fscanf(arquivo_entrada, "%s", palavra) != EOF) {
        num_palavras++;
    }

    // Voltar ao início do arquivo
    fseek(arquivo_entrada, 0, SEEK_SET);

    // Alocar dinamicamente um array de ponteiros para palavras
    char **palavras = (char **)malloc(num_palavras * sizeof(char *));
    if (palavras == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(arquivo_entrada);
        return 1;
    }

    // Ler as palavras do arquivo e armazená-las no array
    for (int i = 0; i < num_palavras; i++) {
        palavras[i] = (char *)malloc(MAX_PALAVRA * sizeof(char));
        if (fscanf(arquivo_entrada, "%s", palavras[i]) == EOF) {
            printf("Erro ao ler as palavras do arquivo.\n");
            fclose(arquivo_entrada);
            free(palavras);
            return 1;
        }
    }

    // Fechar o arquivo de entrada
    fclose(arquivo_entrada);

    // Ordenar as palavras usando o Bubble Sort
    bubble_sort(palavras, num_palavras);

    // Criar um arquivo de saída para as palavras ordenadas
    char nome_arquivo_saida[MAX_PALAVRA + 15];
    snprintf(nome_arquivo_saida, sizeof(nome_arquivo_saida), "%s_ordenado.txt", nome_arquivo_entrada);

    FILE *arquivo_saida = fopen(nome_arquivo_saida, "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        free(palavras);
        return 1;
    }

    // Escrever as palavras ordenadas no arquivo de saída
    for (int i = 0; i < num_palavras; i++) {
        fprintf(arquivo_saida, "%s\n", palavras[i]);
    }

    // Fechar o arquivo de saída
    fclose(arquivo_saida);

    // Liberar a memória alocada
    for (int i = 0; i < num_palavras; i++) {
        free(palavras[i]);
    }
    free(palavras);

    printf("As palavras foram ordenadas e gravadas em %s.\n", nome_arquivo_saida);

    return 0;
}

