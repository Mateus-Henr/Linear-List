#include <stdio.h>
#include "lista.c"

int main()
{
    // ---------------------------------------- TESTE LISTA ------------------------------------------------------------

    Lista *lista = inicializa_lista(1000);

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
        for (int j = 0; j < get_numCelOcupados(lista); j++)
        {
            if (((Celula *) lista->celulas)[j].prox == i)
            {
                printf("\n\nPosition %d | PID = %d", j, ((Celula *) lista->celulas)[j].processo->PID);
                printf("\nPosition %d | Priority = %d", j, ((Celula *) lista->celulas)[j].processo->prioridade);
                printf("\nPosition %d | Time = %s", j, get_hora(((Celula *) lista->celulas)[j].processo));
                printf("Position %d | ant = %d | prox = %d", j, ((Celula *) lista->celulas)[j].ant,
                       ((Celula *) lista->celulas)[j].prox);
            }
        }
    }

    free(lista);
    // -----------------------------------------------------------------------------------------------------------------

    return 0;
}