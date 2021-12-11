#include <stdio.h>
#include "processo.c"
//main
int main()
{
    char y[8];
    Hora x;
    Processo processo = inicializa_Processo();
    x=get_Hora(&processo);
    Formata_Hora(&x);

    return 0;
}
