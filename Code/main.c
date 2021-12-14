#include <stdio.h>
#include "lista.c"

Processo *criar_processo();

int main()
{
    // ---------------------------------------- TESTE LISTA ------------------------------------------------------------

    Lista *lista = inicializa_lista(1000);

    for (int i = 0; i < lista->tamanho; i++)
    {
        Processo *processo_lista = criar_processo();
        coloca_em_ordem(lista, processo_lista);
        free(processo_lista);
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
                printf("\n\nPosition %d | PID = %d", j, ((Celula *) lista->celulas)[j].processo.PID);
                printf("\nPosition %d | Priority = %d", j, ((Celula *) lista->celulas)[j].processo.prioridade);
                printf("\nPosition %d | Time = %s", j, get_hora(&((Celula *) lista->celulas)[j].processo));
                printf("Position %d | ant = %d | prox = %d", j, ((Celula *) lista->celulas)[j].ant,
                       ((Celula *) lista->celulas)[j].prox);
            }
        }
    }

    free(lista);
    // -----------------------------------------------------------------------------------------------------------------

    return 0;
}

Processo *criar_processo()
{
    Processo *processo = inicializa_processo();
    char *hora_formatada = get_hora(processo);

    if (hora_formatada)
    {
        printf("\n\n");
        printf("A process has been created:");
        printf("\nCode: %d", get_PID(processo));
        printf("\nPriority: %d", get_prioridade(processo));
        printf("\nCreation time: %s", hora_formatada);
    }

    return processo;
}
