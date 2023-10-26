#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include "pilha.c"
#include "fila.c"

int main() {
	setlocale(LC_ALL, "Portuguese");
    // Exemplo de uso de Pilha: Histórico de Navegação em um Navegador Web
    printf("Exemplo de uso de Pilha: Histórico de Navegação em um Navegador Web:\n");
    Pilha* historico = criar_pilha(10); // Capacidade máxima de 10 páginas no histórico

    // Simulação de navegação
    empilhar(historico, 1); // Visitou a página 1
    empilhar(historico, 2); // Visitou a página 2
    empilhar(historico, 3); // Visitou a página 3

    printf("Páginas visitadas no histórico:\n");
    while (!pilha_vazia(historico)) {
        int pagina = desempilhar(historico);
        printf("Página %d\n", pagina);
    }
    destruir_pilha(historico);

    // Exemplo de uso de Fila: Gerenciamento de Impressão em uma Fila de Impressão
    printf("\nExemplo de uso de Fila: Gerenciamento de Impressão em uma Fila de Impressão:\n");
    Fila* fila_impressao = criar_fila(5); // Capacidade máxima de 5 documentos na fila de impressão

    // Simulação de impressão
    for (int i = 1; i <= 7; i++) {
        if (enfileirar(fila_impressao, i)) {
            printf("Documento %d foi adicionado à fila de impressão. Total de documentos na fila: %d\n", i, fila_impressao->fim - fila_impressao->frente + 1);
        } else {
            printf("A fila de impressão está cheia. Documento %d não pode ser adicionado.\n", i);
        }
    }

    printf("\nInício da impressão:\n");
    while (!fila_vazia(fila_impressao)) {
        int documento = desenfileirar(fila_impressao);
        printf("Documento %d foi impresso e removido da fila de impressão. Total de documentos na fila: %d\n", documento, fila_impressao->fim - fila_impressao->frente + 1);
    }
    destruir_fila(fila_impressao);

    return 0;
}


