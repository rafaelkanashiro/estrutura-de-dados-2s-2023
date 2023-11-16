#include <stdio.h>
#include "tabela_hash.c"
#include <locale.h>

int main() {
	setlocale(LC_ALL,"Portuguese");
	
    hash_table_put("chave1", "valor1");
    hash_table_put("chave2", "valor2");
    hash_table_put("chave3", "valor3");

    printf("Valor para chave1: %s\n", hash_table_get("chave1"));
    printf("Valor para chave2: %s\n", hash_table_get("chave2"));
    printf("Valor para chave3: %s\n", hash_table_get("chave3"));

    printf("Chave 'chave1' existe na tabela: %s\n", hash_table_contains("chave1") ? "Sim" : "N�o");
    printf("Chave 'chave4' existe na tabela: %s\n", hash_table_contains("chave4") ? "Sim" : "N�o");

    hash_table_remove("chave2");
    printf("Valor para chave2 ap�s remo��o: %s\n", hash_table_get("chave2"));

    return 0;
}

