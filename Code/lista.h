#include "processo.c"

typedef struct
{
    Processo processo;
    int prox;
    int ant;
} Celula;

typedef struct
{
    int tamanho;
    struct Celula *celulas;
    int primeiro;
    int ultimo;
    int numCelOcupados;
} Lista;

Lista inicializa_lista(int tamanho);

int get_numCelOcupados(Lista *lista);

void insere_na_lista(Lista *lista, Processo * processo);

void remove_da_lista(Lista *lista);