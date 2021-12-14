#include "processo.c"

typedef struct
{
    Processo *processo;
    int prox;
    int ant;
} Celula;

typedef struct
{
    unsigned int tamanho;
    struct Celula *celulas;
    unsigned int primeiro;
    unsigned int ultimo;
    unsigned int celulasDisp;
    unsigned int numCelOcupados;
} Lista;

Lista *inicializa_lista(unsigned int tamanho);

unsigned int get_numCelOcupados(Lista *lista);

void insere_na_lista(Lista *lista);

void remove_da_lista(Lista *lista);