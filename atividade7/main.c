#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include "pilha.c"
#include "fila.c"

int main() {
	setlocale(LC_ALL, "Portuguese");
    // Exemplo de uso de Pilha: Hist�rico de Navega��o em um Navegador Web
    printf("Exemplo de uso de Pilha: Hist�rico de Navega��o em um Navegador Web:\n");
    Pilha* historico = criar_pilha(10); // Capacidade m�xima de 10 p�ginas no hist�rico

    // Simula��o de navega��o
    empilhar(historico, 1); // Visitou a p�gina 1
    empilhar(historico, 2); // Visitou a p�gina 2
    empilhar(historico, 3); // Visitou a p�gina 3

    printf("P�ginas visitadas no hist�rico:\n");
    while (!pilha_vazia(historico)) {
        int pagina = desempilhar(historico);
        printf("P�gina %d\n", pagina);
    }
    destruir_pilha(historico);

    // Exemplo de uso de Fila: Gerenciamento de Impress�o em uma Fila de Impress�o
    printf("\nExemplo de uso de Fila: Gerenciamento de Impress�o em uma Fila de Impress�o:\n");
    Fila* fila_impressao = criar_fila(5); // Capacidade m�xima de 5 documentos na fila de impress�o

    // Simula��o de impress�o
    for (int i = 1; i <= 7; i++) {
        if (enfileirar(fila_impressao, i)) {
            printf("Documento %d foi adicionado � fila de impress�o. Total de documentos na fila: %d\n", i, fila_impressao->fim - fila_impressao->frente + 1);
        } else {
            printf("A fila de impress�o est� cheia. Documento %d n�o pode ser adicionado.\n", i);
        }
    }

    printf("\nIn�cio da impress�o:\n");
    while (!fila_vazia(fila_impressao)) {
        int documento = desenfileirar(fila_impressao);
        printf("Documento %d foi impresso e removido da fila de impress�o. Total de documentos na fila: %d\n", documento, fila_impressao->fim - fila_impressao->frente + 1);
    }
    destruir_fila(fila_impressao);

    return 0;
}


