#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

#define TABLE_SIZE 100

typedef struct {
    char* chave;
    char* dado;
} Entry;

Entry tabela[TABLE_SIZE];

int hash(char* chave) {
    int sum = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        sum += chave[i];
    }
    return sum % TABLE_SIZE;
}

void hash_table_put(char* chave, char* dado) {
    int index = hash(chave);
    tabela[index].chave = strdup(chave);
    tabela[index].dado = strdup(dado);
}

char* hash_table_get(char* chave) {
    int index = hash(chave);
    return tabela[index].chave ? tabela[index].dado : NULL;
}

int hash_table_contains(char* chave) {
    int index = hash(chave);
    return tabela[index].chave != NULL;
}

void hash_table_remove(char* chave) {
    int index = hash(chave);
    free(tabela[index].chave);
    free(tabela[index].dado);
    tabela[index].chave = NULL;
    tabela[index].dado = NULL;
}

