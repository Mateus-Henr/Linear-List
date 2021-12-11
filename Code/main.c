#include <stdio.h>
#include "processo.c"

int main()
{
    Hora hora;

    Processo processo = inicializa_processo();
    hora = get_hora(&processo);
    char * hora_formatada = formata_hora(&hora);


    if (hora_formatada)
    {
        printf("A process has been created:");
        printf("\nCode: %d", get_PID(&processo));
        printf("\nPriority: %d", get_prioridade(&processo));
        printf("\nCreation time: %s", hora_formatada);
        free(hora_formatada);
    }

    return 0;
}
