#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    float valor;
    struct No* proximo_no;
} No;

No* criar_no(float valor, No* proximo_no);
void inserir_no_lista(No** lista, No* novo_no);
void imprimir_lista(No* lista);
int contar_nos(No* lista);
No* copiar_lista(No* lista);
void concatenar_listas(No* lista_destino, No* lista_origem);
void liberar_lista(No* lista);
int verificar_existencia(No* lista, float valor_busca);
int contar_ocorrencias(No* lista, float valor_busca);
void imprimir_inverso(No* lista);
void inserir_no_posicao(No** lista, int posicao, float valor);
void remover_no_posicao(No** lista, int posicao);
void remover_no_valor(No** lista, float valor);
void inserir_no_ordenado(No** lista, No* novo_no);

#endif

