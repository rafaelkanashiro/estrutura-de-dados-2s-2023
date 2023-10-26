#include <stdio.h>
#include <stdlib.h>
#include "lista.c"
#include <locale.h>

int main(int argc, char* argv[]) {
	setlocale(LC_ALL,"Portuguese");
	
    No* n0 = no('C', NULL);
    No* n1 = no('E', NULL);
    No* n2 = no('A', no('D', no('B', no('X', no('Z', NULL)))));
    No* n3 = no('U', NULL);
    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n3);
    
    printf("Lista original: ");
    lista_imprimir(n0);

    int existencia = lista_verificar_existencia(n0, 'D');
    printf("\nExiste 'D' na lista? %d", existencia);

    int ocorrencias = lista_verificar_ocorrencias(n0, 'A');
    printf("\n'Ocorr�ncias de 'A' na lista: %d", ocorrencias);

    printf("\nLista inversa: ");
    lista_imprimir_inversa(n0);

    lista_inserir_no_i(n0, 2);
    printf("\nLista ap�s inser��o de 'N' na posi��o 2: ");
    lista_imprimir(n0);

    lista_remover_no_i(n0, 2);
    printf("\nLista ap�s remo��o da posi��o 2: ");
    lista_imprimir(n0);

    lista_remover_no(n0, 'A');
    printf("\nLista ap�s remo��o de 'A': ");
    lista_imprimir(n0);

    lista_liberar(n0);
    n0 = NULL;

    printf("\nLista ap�s liberar mem�ria: ");
    lista_imprimir(n0);

    exit(0);
}

