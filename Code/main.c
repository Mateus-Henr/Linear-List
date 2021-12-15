#include <stdio.h>
#include "lista.c"

int main()
{
    // ---------------------------------------- TESTE LISTA ------------------------------------------------------------

    Lista *lista = inicializa_lista(4);

    for (int i = 0; i < lista->tamanho; i++)
    {
        insere_na_lista(lista);
    }

    printf("\nInformation about the list");
    printf("\nSize of the list: %d", lista->tamanho);
    printf("\nUsed cells: %d", get_numCelOcupados(lista));
    printf("\nFirst position index = %d | Last position index = %d", lista->primeiro, lista->ultimo);

    printf("\nDisplaying contents");
    for (int i = 0; i < get_numCelOcupados(lista); i++)
    {
        printf("\n\nPosition %d | PID = %d", i, ((Celula *) lista->celulas)[i].processo->PID);
        printf("\nPosition %d | Priority = %d", i, ((Celula *) lista->celulas)[i].processo->prioridade);
        printf("\nPosition %d | Time = %s", i, get_hora(((Celula *) lista->celulas)[i].processo));
        printf("Position %d | ant = %d | prox = %d", i, ((Celula *) lista->celulas)[i].ant,
               ((Celula *) lista->celulas)[i].prox);
    }

    free(lista);
    // -----------------------------------------------------------------------------------------------------------------

    return 0;
}