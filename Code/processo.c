#include "processo.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

Processo inicializa_processo()
{
    Processo processo;
    time_t t;

    srand((unsigned) time(&t));
    processo.PID = rand();
    processo.prioridade = 1 + (rand() % 5);
    inicializa_tempo(&processo);

    return processo;
}

void inicializa_tempo(Processo *processo)
{
    time_t hora_cru;
    struct tm *hora_atual;

    time(&hora_cru);
    hora_atual = localtime(&hora_cru);
    processo->hora.horas = hora_atual->tm_hour;
    processo->hora.minutos = hora_atual->tm_min;
    processo->hora.segundos = hora_atual->tm_sec;
}

int get_PID(Processo *processo)
{
    return processo->PID;
}

void set_PID(Processo *processo, int novo_PID)
{
    processo->PID = novo_PID;
}

//Prioridade
void set_prioridade(Processo *processo, int nova_prioridade)
{
    processo->prioridade = nova_prioridade;
}

int get_prioridade(Processo *processo)
{
    return processo->prioridade;
}

void set_hora(Processo *processo, int nova_hora, int novo_minutos, int novo_segundos)
{
    Hora hora_atual;
    hora_atual.horas = nova_hora;
    hora_atual.minutos = novo_minutos;
    hora_atual.segundos = novo_segundos;
    processo->hora = hora_atual;
}

Hora get_hora(Processo *processo)
{
    return processo->hora;
}

char *formata_hora(Hora *hora)
{
    char *hora_formatada = malloc(8);

    // Quando nn conseguir alocar a memória
    if (!hora_formatada)
    {
        return NULL;
    }

    sprintf(hora_formatada, "%02d:%02d:%02d", hora->horas, hora->minutos, hora->segundos);
    return hora_formatada;
}
