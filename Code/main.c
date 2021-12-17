#include <stdio.h>
#include "lista.c"

int main()
{
    // ---------------------------------------- TESTE LISTA ------------------------------------------------------------
    Lista *lista = inicializa_lista(100);

    for (int i = 0; i < lista->tamanho; i++)
    {
        insere_na_lista(lista);
    }

    printf("\nInformation about the list");
    printf("\nSize of the list: %d", lista->tamanho);
    printf("\nUsed cells: %d", get_numCelOcupados(lista));
    printf("\nFirst position index = %d | Last position index = %d", lista->primeiro, lista->ultimo);

    printf("\n\nDisplaying contents");
    imprime_conteudo(lista);


    // TESTING REMOVAL
    printf("\n\nREMOVENDO\n");

    remove_da_lista(lista);
    remove_da_lista(lista);
    remove_da_lista(lista);

    imprime_conteudo(lista);

    return 0;
}