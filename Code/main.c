#include <stdio.h>
#include "processo.c"

int main()
{
    Processo *processo;
    inicializa_Processo((Processo *) &processo);

    printf("%d", get_Prioridade(processo));
    printf("%d", get_PID(processo));

    return 0;
}
