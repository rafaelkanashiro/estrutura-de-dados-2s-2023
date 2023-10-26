// fila.h
#ifndef FILA_H
#define FILA_H

typedef struct Fila {
    int* elementos;
    int frente;
    int fim;
    int capacidade;
} Fila;

Fila* criar_fila(int capacidade);
bool enfileirar(Fila* fila, int elemento);
bool fila_vazia(Fila* fila);
int desenfileirar(Fila* fila);
void destruir_fila(Fila* fila);

#endif // FILA_H

