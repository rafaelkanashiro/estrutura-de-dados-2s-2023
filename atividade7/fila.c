// fila.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"

Fila* criar_fila(int capacidade) {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->elementos = (int*)malloc(capacidade * sizeof(int));
    fila->frente = 0;
    fila->fim = -1;
    fila->capacidade = capacidade;
    return fila;
}

bool enfileirar(Fila* fila, int elemento) {
    if (fila->fim - fila->frente >= fila->capacidade - 1) {
        return false; // Fila cheia
    }
    fila->elementos[++(fila->fim) % fila->capacidade] = elemento;
    return true;
}

bool fila_vazia(Fila* fila) {
    return fila->frente > fila->fim;
}

int desenfileirar(Fila* fila) {
    if (fila_vazia(fila)) {
        exit(EXIT_FAILURE); // Tratamento de erro para fila vazia
    }
    return fila->elementos[(fila->frente)++ % fila->capacidade];
}

void destruir_fila(Fila* fila) {
    free(fila->elementos);
    free(fila);
}

