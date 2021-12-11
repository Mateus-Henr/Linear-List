#include "lista.h"
#include <stdlib.h>

Lista inicializa_lista(int tamanho)
{
    Lista *lista = (Lista *) malloc(sizeof(struct Lista *));
    lista->celulas = (struct Celula *) malloc(tamanho * sizeof(lista->celulas));

    lista->numCelOcupados = 0;

    return *lista;
}

Celula inicializa_celula(Processo *processo)
{
    Celula celula;
    celula.processo = *processo;

    return celula;
}

int get_celulas_ocupadas(Lista *lista)
{
    return lista->numCelOcupados;
}

void coloca_em_ordem(Lista *lista)
{
    int flag = 0;
    Celula *celulas = (Celula *) lista->celulas;

    while (!flag)
    {
        flag = 1;
        for (int i = 0; i < (lista->numCelOcupados - 1); i++)
        {
            Processo *atual = &celulas[i].processo;
            Processo *prox = &celulas[i + 1].processo;
            Processo temp;
            if (get_PID(atual) > get_PID(prox))
            {
                temp = *(atual);
                *(atual) = *(prox);
                *(prox) = temp;
                flag = 0;
            }
        }
    }
}

void insere_na_lista(Lista *lista, Celula *celula)
{
    int posicao = lista->numCelOcupados;
    ((Celula *) lista->celulas)[posicao] = *celula;

    if (lista->numCelOcupados == 0)
    {
        lista->primeiro = posicao;
        lista->ultimo = posicao;
    }
    else
    {
        lista->ultimo = posicao;
    }

    lista->numCelOcupados += 1;
    coloca_em_ordem(lista);
}

void remove_da_lista(Lista *lista)
{
    // Yet to implement
}