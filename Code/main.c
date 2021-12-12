#include <stdio.h>
#include "lista.c"
#include <Windows.h>

Processo *criar_processo();

int main()
{
    // ----------------------------------------- TESTE PROCESSO --------------------------------------------------------

//    Processo processo = inicializa_processo();
//    Hora hora = get_hora(&processo);
//    char *hora_formatada = formata_hora(&hora);
//
//
//    if (hora_formatada)
//    {
//        printf("A process has been created:");
//        printf("\nCode: %d", get_PID(&processo));
//        printf("\nPriority: %d", get_prioridade(&processo));
//        printf("\nCreation time: %s", hora_formatada);
//        free(hora_formatada);
//    }

    // -----------------------------------------------------------------------------------------------------------------


    // ---------------------------------------- TESTE LISTA ------------------------------------------------------------

    Lista *lista = inicializa_lista(5000);

    for (int i = 0; i < lista->tamanho; i++)
    {
        Processo *processo_lista = criar_processo();
        insere_na_lista(lista, processo_lista);
        printf("\n\n");

        free(processo_lista);

        // Putting the main thread to sleep for testing purposes
//        Sleep(100);
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
                printf("\n\nPosition %d | PID = %d", i, ((Celula *) lista->celulas)[j].processo.PID);
                printf("\nPosition %d | Priority = %d", i, ((Celula *) lista->celulas)[j].processo.prioridade);
                printf("\nPosition %d | Time = %s", i, formata_hora(&((Celula *) lista->celulas)[j].processo));
                printf("\nPosition %d | ant = %d | prox = %d", i, ((Celula *) lista->celulas)[j].ant,
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
    char *hora_formatada = formata_hora(processo);

    if (hora_formatada)
    {
        printf("A process has been created:");
        printf("\nCode: %d", get_PID(processo));
        printf("\nPriority: %d", get_prioridade(processo));
        printf("\nCreation time: %s", hora_formatada);
    }

    return processo;
}
