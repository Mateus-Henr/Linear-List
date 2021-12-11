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
        printf("%s", hora_formatada);
    }

    return 0;
}
