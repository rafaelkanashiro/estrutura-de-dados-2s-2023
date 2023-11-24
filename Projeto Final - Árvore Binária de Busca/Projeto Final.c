#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Defini��o da estrutura do n� da �rvore
struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Fun��o para criar um novo n�
struct TreeNode* criarNo(int key) {
    struct TreeNode* novoNo = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    novoNo->key = key;
    novoNo->left = novoNo->right = NULL;
    return novoNo;
}

// Fun��o para inserir um valor na ABB
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

// Fun��o para encontrar o n� m�nimo na ABB
struct TreeNode* encontrarMin(struct TreeNode* raiz) {
    while (raiz->left != NULL) {
        raiz = raiz->left;
    }
    return raiz;
}

// Fun��o para remover um valor da ABB
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

// Fun��o para buscar um valor na ABB
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

// Fun��es para percorrer a �rvore em ordem, pr�-ordem e p�s-ordem
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

// Fun��es para encontrar o valor m�nimo e m�ximo na ABB
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

// Fun��o para liberar a mem�ria da �rvore
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
    printf("Busca 20: %s\n", buscar(raiz, 20) ? "Encontrado" : "N�o encontrado");
    printf("Busca 90: %s\n", buscar(raiz, 90) ? "Encontrado" : "N�o encontrado");

    // Percorrer a �rvore
    printf("Percorrimento em ordem: ");
    emOrdem(raiz);
    printf("\n");

    printf("Percorrimento pr�-ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Percorrimento p�s-ordem: ");
    posOrdem(raiz);
    printf("\n");

    // Encontrar valor m�nimo e m�ximo
    printf("Valor m�nimo: %d\n", encontrarMinimo(raiz));
    printf("Valor m�ximo: %d\n", encontrarMaximo(raiz));

    // Remover valores
    raiz = removerNo(raiz, 20);
    raiz = removerNo(raiz, 30);

    // Percorrer a �rvore ap�s remo��es
    printf("Percorrimento em ordem ap�s remo��es: ");
    emOrdem(raiz);
    printf("\n");

    // Liberar mem�ria
    liberarArvore(raiz);

    return 0;
}

