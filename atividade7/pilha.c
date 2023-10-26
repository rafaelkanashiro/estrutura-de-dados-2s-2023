// pilha.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

Pilha* criar_pilha(int capacidade) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->elementos = (int*)malloc(capacidade * sizeof(int));
    pilha->topo = -1;
    pilha->capacidade = capacidade;
    return pilha;
}

bool empilhar(Pilha* pilha, int elemento) {
    if (pilha->topo >= pilha->capacidade - 1) {
        return false; // Pilha cheia
    }
    pilha->elementos[++(pilha->topo)] = elemento;
    return true;
}

bool pilha_vazia(Pilha* pilha) {
    return pilha->topo == -1;
}

int desempilhar(Pilha* pilha) {
    if (pilha_vazia(pilha)) {
        exit(EXIT_FAILURE); // Tratamento de erro para pilha vazia
    }
    return pilha->elementos[(pilha->topo)--];
}

void destruir_pilha(Pilha* pilha) {
    free(pilha->elementos);
    free(pilha);
}

