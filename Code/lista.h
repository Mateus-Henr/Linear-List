#include "processo.c"

typedef int Cursor;

typedef struct
{
    Processo *processo;
    Cursor prox;
    Cursor ant;
} Celula;

typedef struct
{
    unsigned int tamanho;
    struct Celula *celulas;
    Cursor primeiro;
    Cursor ultimo;
    unsigned int celulasDisp;
    unsigned int numCelOcupados;
} Lista;

Lista *inicializa_lista(unsigned int tamanho);

unsigned int get_numCelOcupados(Lista *lista);

void insere_na_lista(Lista *lista);

void remove_da_lista(Lista *lista);