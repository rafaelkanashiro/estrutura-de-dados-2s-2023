#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    float y;
} Ponto;

int main() {
    char nome_arquivo[] = "dados.csv"; // Nome do arquivo a ser aberto

    // Abra o arquivo para leitura
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("N�o foi poss�vel abrir o arquivo %s\n", nome_arquivo);
        return 1;
    }

    // Conte o n�mero de linhas no arquivo
    int num_linhas = 0;
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        num_linhas++;
    }

    // Volte para o in�cio do arquivo
    fseek(arquivo, 0, SEEK_SET);

    // Aloque dinamicamente um array de pontos
    Ponto *pontos = (Ponto *)malloc(num_linhas * sizeof(Ponto));

    // Leia os pontos do arquivo
    int i = 0;
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *token = strtok(linha, ",");
        pontos[i].x = atoi(token);

        token = strtok(NULL, ",");
        pontos[i].y = atof(token);

        i++;
    }

    // Calcule a m�dia de x e y
    int soma_x = 0;
    float soma_y = 0.0;
    for (i = 0; i < num_linhas; i++) {
        soma_x += pontos[i].x;
        soma_y += pontos[i].y;
    }

    float media_x = (float)soma_x / num_linhas;
    float media_y = soma_y / num_linhas;

    // Calcule a inclina��o e a intercepta��o da reta de regress�o
    float soma_numerador = 0.0;
    float soma_denominador = 0.0;
    for (i = 0; i < num_linhas; i++) {
        float diff_x = pontos[i].x - media_x;
        float diff_y = pontos[i].y - media_y;
        soma_numerador += diff_x * diff_y;
        soma_denominador += diff_x * diff_x;
    }

    float inclinacao = soma_numerador / soma_denominador;
    float interceptacao = media_y - inclinacao * media_x;

    // Exiba os resultados da regress�o linear
    printf("y = %.2fx + %.2f\n", inclinacao, interceptacao);

    // Libere a mem�ria alocada
    free(pontos);

    // Feche o arquivo
    fclose(arquivo);

    return 0;
}

