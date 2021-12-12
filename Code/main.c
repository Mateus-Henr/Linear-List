#include <stdio.h>
#include "lista.c"
#include <Windows.h>

Processo criar_processo();

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

    Lista lista = inicializa_lista(3);

    for (int i = 0; i < 3; i++)
    {
        Processo processo_lista = criar_processo();
        insere_na_lista(&lista, &processo_lista);
        printf("\n\n");
        // Putting the main thread to sleep for testing purposes
        Sleep(1000);
    }

    printf("\nInformation about the list");
    printf("\nSize of the list: %d", lista.tamanho);
    printf("\nOccupied cells: %d", get_numCelOcupados(&lista));

    printf("\nDisplaying contents");
    for (int i = 0; i < get_numCelOcupados(&lista); i++)
    {
        printf("\n\nPosition %d | PIB = %d", i, ((Celula *) lista.celulas)[i].processo.PID);
        printf("\nPosition %d | Priority = %d", i, ((Celula *) lista.celulas)[i].processo.prioridade);
        printf("\nPosition %d | Time = %s", i, formata_hora(&((Celula *) lista.celulas)[i].processo.hora));
        printf("\nPosition %d | ant = %d | prox = %d", i, ((Celula *) lista.celulas)[i].ant,
               ((Celula *) lista.celulas)[i].prox);
    }

    // -----------------------------------------------------------------------------------------------------------------

    return 0;
}

Processo criar_processo()
{
    Processo processo = inicializa_processo();
    Hora hora = get_hora(&processo);
    char *hora_formatada = formata_hora(&hora);

    if (hora_formatada)
    {
        printf("A process has been created:");
        printf("\nCode: %d", get_PID(&processo));
        printf("\nPriority: %d", get_prioridade(&processo));
        printf("\nCreation time: %s", hora_formatada);
        free(hora_formatada);
    }

    return processo;
}
