#include "processo.c"

typedef int Cursor;

typedef struct
{
    TProcesso *processo;
    Cursor prox;
    Cursor ant;
} TCelula;

typedef struct
{
    unsigned int tamanho;
    struct Celula *celulas;
    Cursor primeiro;
    Cursor ultimo;
    unsigned int celulasDisp;
    unsigned int numCelOcupados;
} TLista;

TLista *inicializa_lista(unsigned int tamanho);

unsigned int get_numCelOcupados(TLista *lista);

void insere_na_lista(TLista *lista);

void remove_da_lista(TLista *lista);