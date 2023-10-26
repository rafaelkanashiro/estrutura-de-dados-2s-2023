// pilha.h
#ifndef PILHA_H
#define PILHA_H

typedef struct Pilha {
    int* elementos;
    int topo;
    int capacidade;
} Pilha;

Pilha* criar_pilha(int capacidade);
bool empilhar(Pilha* pilha, int elemento);
bool pilha_vazia(Pilha* pilha);
int desempilhar(Pilha* pilha);
void destruir_pilha(Pilha* pilha);

#endif // PILHA_H

