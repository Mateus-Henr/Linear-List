#include "PROCESSOS.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void inicializa_Tempo(Tempo *horario) {
    time_t Tempo_Atual;
    time(Tempo_Atual);
    struct tm *MeuTempo = localtime(&Tempo_Atual);
    horario->Hora = MeuTempo->tm_hour;
    horario->Min = MeuTempo->tm_min;
    horario->Seg = MeuTempo->tm_sec;
}
void inicializa_Processo(Processo *processo){
    inicializa_Tempo(processo->Hora_Atual);
    processo->PID=rand() % 2000000;
    processo->Prioridade= 1+rand() % 4;
}
int get_PID(Processo *processo){
    return processo->PID;
}

int set_PID(Processo *processo, Novo_PID){
    processo->PID= Novo_PID;
}

//Prioridade
int set_Prioridade(Processo *processo, Nova_Prioridade){
    processo->Prioridade=Nova_Prioridade;
}

int get_Prioridade(Processo *processo){
    return processo->Prioridade;
}

//Hora de Criação

int set_Hora(Processo *processo, Novo_seg, Novo_Min, Nova_Hora){
    struct Tempo *hora_atual;
    hora_atual = processo->Hora_Atual;
    hora_atual->Hora;
}
int get_Hora(Processo *processo){
    return processo->Hora_Atual;
}