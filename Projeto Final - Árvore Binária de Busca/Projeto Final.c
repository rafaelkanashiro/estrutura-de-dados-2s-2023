#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Definição da estrutura do nó da árvore
struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Função para criar um novo nó
struct TreeNode* criarNo(int key) {
    struct TreeNode* novoNo = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    novoNo->key = key;
    novoNo->left = novoNo->right = NULL;
    return novoNo;
}

// Função para inserir um valor na ABB
struct TreeNode* inserir(struct TreeNode* raiz, int key) {
    if (raiz == NULL) {
        return criarNo(key);
    }

    if (key < raiz->key) {
        raiz->left = inserir(raiz->left, key);
    } else if (key > raiz->key) {
        raiz->right = inserir(raiz->right, key);
    }

    return raiz;
}

// Função para encontrar o nó mínimo na ABB
struct TreeNode* encontrarMin(struct TreeNode* raiz) {
    while (raiz->left != NULL) {
        raiz = raiz->left;
    }
    return raiz;
}

// Função para remover um valor da ABB
struct TreeNode* removerNo(struct TreeNode* raiz, int key) {
    if (raiz == NULL) {
        return raiz;
    }

    if (key < raiz->key) {
        raiz->left = removerNo(raiz->left, key);
    } else if (key > raiz->key) {
        raiz->right = removerNo(raiz->right, key);
    } else {
        if (raiz->left == NULL) {
            struct TreeNode* temp = raiz->right;
            free(raiz);
            return temp;
        } else if (raiz->right == NULL) {
            struct TreeNode* temp = raiz->left;
            free(raiz);
            return temp;
        }

        struct TreeNode* temp = encontrarMin(raiz->right);
        raiz->key = temp->key;
        raiz->right = removerNo(raiz->right, temp->key);
    }

    return raiz;
}

// Função para buscar um valor na ABB
int buscar(struct TreeNode* raiz, int key) {
    if (raiz == NULL) {
        return 0;
    }

    if (key == raiz->key) {
        return 1;
    } else if (key < raiz->key) {
        return buscar(raiz->left, key);
    } else {
        return buscar(raiz->right, key);
    }
}

// Funções para percorrer a árvore em ordem, pré-ordem e pós-ordem
void emOrdem(struct TreeNode* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->left);
        printf("%d ", raiz->key);
        emOrdem(raiz->right);
    }
}

void preOrdem(struct TreeNode* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->key);
        preOrdem(raiz->left);
        preOrdem(raiz->right);
    }
}

void posOrdem(struct TreeNode* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->left);
        posOrdem(raiz->right);
        printf("%d ", raiz->key);
    }
}

// Funções para encontrar o valor mínimo e máximo na ABB
int encontrarMinimo(struct TreeNode* raiz) {
    while (raiz->left != NULL) {
        raiz = raiz->left;
    }
    return raiz->key;
}

int encontrarMaximo(struct TreeNode* raiz) {
    while (raiz->right != NULL) {
        raiz = raiz->right;
    }
    return raiz->key;
}

// Função para liberar a memória da árvore
void liberarArvore(struct TreeNode* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->left);
        liberarArvore(raiz->right);
        free(raiz);
    }
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
    struct TreeNode* raiz = NULL;

    // Inserir valores
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 70);
    inserir(raiz, 60);
    inserir(raiz, 80);

    // Realizar buscas
    printf("Busca 20: %s\n", buscar(raiz, 20) ? "Encontrado" : "Não encontrado");
    printf("Busca 90: %s\n", buscar(raiz, 90) ? "Encontrado" : "Não encontrado");

    // Percorrer a árvore
    printf("Percorrimento em ordem: ");
    emOrdem(raiz);
    printf("\n");

    printf("Percorrimento pré-ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Percorrimento pós-ordem: ");
    posOrdem(raiz);
    printf("\n");

    // Encontrar valor mínimo e máximo
    printf("Valor mínimo: %d\n", encontrarMinimo(raiz));
    printf("Valor máximo: %d\n", encontrarMaximo(raiz));

    // Remover valores
    raiz = removerNo(raiz, 20);
    raiz = removerNo(raiz, 30);

    // Percorrer a árvore após remoções
    printf("Percorrimento em ordem após remoções: ");
    emOrdem(raiz);
    printf("\n");

    // Liberar memória
    liberarArvore(raiz);

    return 0;
}

