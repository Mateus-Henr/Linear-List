#include <stdio.h>
#include "processo.c"

int main()
{
    Processo *processo;
    inicializa_Processo(processo);

    printf("%d", processo->hora);
    printf("%d", processo->prioridade);

    return 0;
}
