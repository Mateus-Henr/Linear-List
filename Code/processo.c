#include "processo.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

Processo *inicializa_processo()
{
    Processo *processo = malloc(sizeof *processo);

    processo->PID = rand();
    processo->prioridade = 1 + (rand() % 5);
    inicializa_tempo(processo);

    return processo;
}

void inicializa_tempo(Processo *processo)
{
    time_t hora_cru;
    struct tm *hora_atual;

    time(&hora_cru);
    hora_atual = localtime(&hora_cru);
    processo->hora = hora_atual;
}

unsigned int get_PID(Processo *processo)
{
    return processo->PID;
}

void set_PID(Processo *processo, unsigned int novo_PID)
{
    processo->PID = novo_PID;
}

//Prioridade
void set_prioridade(Processo *processo, unsigned int nova_prioridade)
{
    processo->prioridade = nova_prioridade;
}

unsigned int get_prioridade(Processo *processo)
{
    return processo->prioridade;
}

char *formata_hora(Processo *processo)
{
    return asctime(processo->hora);
}