#include <stdio.h>
#include "processo.c"
//main
int main()
{
    char y[8];
    Hora x;
    Processo processo = inicializa_Processo();
    x=get_Hora(&processo);
    y = Formata_Hora(&x);
    for (int i = 0; i < 8; ++i) {
        printf("%c",y[i]);
    }
    return 0;
}
