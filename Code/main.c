#include <stdio.h>
#include "processo.c"

int main()
{
    Processo processo = inicializa_Processo();

    printf("PID: %d", get_PID(&processo));
    printf("\nPrioridade: %d", get_Prioridade(&processo));
    printf("\nHora: %d", processo.hora.horas);
    printf("\nMinutos: %d", processo.hora.minutos);
    printf("\nSegundos: %d", processo.hora.segundos);

    return 0;
}
