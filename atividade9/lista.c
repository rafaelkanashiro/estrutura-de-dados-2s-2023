#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* criar_no(float valor, No* proximo_no) {
    No* novo_no = malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo_no = proximo_no;
    return novo_no;
}

void inserir_no_lista(No** lista, No* novo_no) {
    if (*lista == NULL) {
        *lista = novo_no;
    } else {
        inserir_no_lista(&((*lista)->proximo_no), novo_no);
    }
}

void imprimir_lista(No* lista) {
    while (lista != NULL) {
        printf("%.2f ", lista->valor);
        lista = lista->proximo_no;
    }
    printf("\n");
}

int contar_nos(No* lista) {
    int count = 0;
    while (lista != NULL) {
        count++;
        lista = lista->proximo_no;
    }
    return count;
}

No* copiar_lista(No* lista) {
    No* copia = NULL;
    No* atual = lista;

    while (atual != NULL) {
        inserir_no_lista(&copia, criar_no(atual->valor, NULL));
        atual = atual->proximo_no;
    }

    return copia;
}

void concatenar_listas(No* lista_destino, No* lista_origem) {
    while (lista_destino->proximo_no != NULL) {
        lista_destino = lista_destino->proximo_no;
    }
    lista_destino->proximo_no = copiar_lista(lista_origem);
}

void liberar_lista(No* lista) {
    while (lista != NULL) {
        No* temp = lista;
        lista = lista->proximo_no;
        free(temp);
    }
}

int verificar_existencia(No* lista, float valor_busca) {
    while (lista != NULL) {
        if (lista->valor == valor_busca) {
            return 1;  // Valor encontrado na lista
        }
        lista = lista->proximo_no;
    }
    return 0;  // Valor não encontrado
}

int contar_ocorrencias(No* lista, float valor_busca) {
    int ocorrencias = 0;
    while (lista != NULL) {
        if (lista->valor == valor_busca) {
            ocorrencias++;
        }
        lista = lista->proximo_no;
    }
    return ocorrencias;
}

void imprimir_inverso(No* lista) {
    if (lista == NULL) {
        return;
    }
    imprimir_inverso(lista->proximo_no);
    printf("%.2f ", lista->valor);
}

void inserir_no_posicao(No** lista, int posicao, float valor) {
    if (posicao < 0) {
        return;  // Posição inválida
    }

    No* novo_no = criar_no(valor, NULL);

    if (posicao == 0) {
        novo_no->proximo_no = *lista;
        *lista = novo_no;
        return;
    }

    int contador = 0;
    No* atual = *lista;

    while (contador < posicao - 1 && atual != NULL) {
        atual = atual->proximo_no;
        contador++;
    }

    if (atual == NULL) {
        return;  // Posição inválida
    }

    novo_no->proximo_no = atual->proximo_no;
    atual->proximo_no = novo_no;
}

void remover_no_posicao(No** lista, int posicao) {
    if (posicao < 0) {
        return;  // Posição inválida
    }

    if (*lista == NULL) {
        return;  // Lista vazia
    }

    if (posicao == 0) {
        No* temp = *lista;
        *lista = (*lista)->proximo_no;
        free(temp);
        return;
    }

    int contador = 0;
    No* atual = *lista;
    No* anterior = NULL;

    while (contador < posicao && atual != NULL) {
        anterior = atual;
        atual = atual->proximo_no;
        contador++;
    }

    if (atual == NULL) {
        return;  // Posição inválida
    }

    anterior->proximo_no = atual->proximo_no;
    free(atual);
}

void remover_no_valor(No** lista, float valor) {
    if (*lista == NULL) {
        return;  // Lista vazia
    }

    if ((*lista)->valor == valor) {
        No* temp = *lista;
        *lista = (*lista)->proximo_no;
        free(temp);
        remover_no_valor(lista, valor);
        return;
    }

    No* atual = *lista;
    No* anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo_no;
    }

    if (atual == NULL) {
        return;  // Valor não encontrado
    }

    anterior->proximo_no = atual->proximo_no;
    free(atual);
}

void inserir_no_ordenado(No** lista, No* novo_no) {
    if (*lista == NULL || novo_no->valor < (*lista)->valor) {
        novo_no->proximo_no = *lista;
        *lista = novo_no;
        return;
    }

    No* atual = *lista;
    No* anterior = NULL;

    while (atual != NULL && novo_no->valor > atual->valor) {
        anterior = atual;
        atual = atual->proximo_no;
    }

    anterior->proximo_no = novo_no;
    novo_no->proximo_no = atual;
}

