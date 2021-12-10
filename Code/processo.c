#include "processo.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

Processo inicializa_Processo()
{
    Processo processo;
    time_t t;

    srand((unsigned) time(&t));
    processo.PID = rand();
    processo.prioridade = 1 + (rand() % 5);
    inicializa_Tempo(&processo);

    return processo;
}

void inicializa_Tempo(Processo *processo)
{
    time_t hora_cru;
    struct tm * hora_atual;

    time(&hora_cru);
    hora_atual = localtime(&hora_cru);
    set_Hora(processo, hora_atual->tm_hour, hora_atual->tm_min, hora_atual->tm_sec);
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
    Hora hora_atual;
    hora_atual.horas = nova_hora;
    hora_atual.minutos = novo_minutos;
    hora_atual.segundos = novo_segundos;
    processo->hora = hora_atual;
}
Hora get_Hora(Processo *processo){
    return processo->hora;
}
char* Formata_Hora(Hora *hora){
    char horas[2],minu[2],sec[2];
    char horario[8];
    itoa(hora->horas,horas,10);
    itoa(hora->minutos,minu,10);
    itoa(hora->minutos,sec,10);
    for(int i=0;i<2;++i){
        horario[i]= horas[i];
    }
    horario[2]= ':';
    horario[5]= ':';
    for (int i = 0; i < 2; ++i) {
        horario[3+i]= minu[i];
    }
    for (int i = 0; i < 2; ++i) {
        horario[6+i]= sec[i];
    }

    return horario;
}
