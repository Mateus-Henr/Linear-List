#include "processo.h"
#include <stdlib.h>
#include <time.h>

void inicializa_Tempo(Hora *hora)
{
    time_t hora_atual;
    time((time_t *)hora_atual);
    struct tm *MeuTempo = localtime(&hora_atual);
    hora->horas = MeuTempo->tm_hour;
    hora->minutos = MeuTempo->tm_min;
    hora->segundos = MeuTempo->tm_sec;
}

void inicializa_Processo(Processo *processo)
{
    inicializa_Tempo(processo->hora);
    processo->PID = rand() % 2000000;
    processo->prioridade = 1 + rand() % 4;
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
void set_Prioridade(Processo *processo, int nova_prioridade)
{
    processo->prioridade = nova_prioridade;
}

int get_Prioridade(Processo *processo)
{
    return processo->prioridade;
}

//Hora de Criação

void set_Hora(Processo *processo, int nova_hora, int novo_minutos, int novo_segundos)
{
    Hora *hora_atual = processo->hora;
    hora_atual->horas = nova_hora;
    hora_atual->minutos = novo_minutos;
    hora_atual->segundos = novo_segundos;
}

int get_Hora(Processo *processo)
{
    return processo->hora;
}