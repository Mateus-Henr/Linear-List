#include "processo.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

TProcesso *inicializa_processo()
{
    TProcesso *processo = malloc(sizeof *processo);

    processo->PID = rand();
    processo->prioridade = 1 + (rand() % 5);
    inicializa_tempo(processo);

    return processo;
}

void inicializa_tempo(TProcesso *processo)
{
    time_t hora_cru;
    struct tm *hora_atual;

    time(&hora_cru);
    hora_atual = localtime(&hora_cru);
    processo->hora = hora_atual;
}

char *get_hora(TProcesso *processo)
{
    return asctime(processo->hora);
}

unsigned int get_PID(TProcesso *processo)
{
    if (processo)
    {
        return processo->PID;
    }
    else
    {
        return -1; // TProcesso nulo.
    }
}

void set_PID(TProcesso *processo, unsigned int novo_PID)
{
    processo->PID = novo_PID;
}

unsigned int get_prioridade(TProcesso *processo)
{
    return processo->prioridade;
}

void set_prioridade(TProcesso *processo, unsigned int nova_prioridade)
{
    processo->prioridade = nova_prioridade;
}