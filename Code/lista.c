#include "lista.h"
#include <stdlib.h>

Lista inicializa_lista(int tamanho)
{
    Lista *lista = (Lista *) malloc(sizeof(struct Lista *));
    lista->celulas = (struct Celula *) malloc(tamanho * sizeof(lista->celulas));

    lista->numCelOcupados = 0;
    lista->tamanho = tamanho;

    return *lista;
}

int get_numCelOcupados(Lista *lista)
{
    return lista->numCelOcupados;
}

void coloca_em_ordem(Lista *lista)
{
    int flag = 0;
    int celulas_usadas = get_numCelOcupados(lista);

    Celula *celulas = (Celula *) lista->celulas;
    int *ptr_celulas[celulas_usadas];

    for (int i = 0; i < celulas_usadas; i++)
    {
        ptr_celulas[i] = (int *) &celulas[i];
    }

    while (!flag)
    {
        flag = 1;
        for (int i = 0; i < (celulas_usadas - 1); i++)
        {
            Processo *atual = &((Celula *) *ptr_celulas[i])->processo;
            Processo *prox = &((Celula *) *ptr_celulas[i + 1])->processo;
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

    for (int i = 0; i < celulas_usadas; i++)
    {
        ((Celula *) ptr_celulas[i])->ant = i;
        ((Celula *) ptr_celulas[i])->prox = i + 1;
    }
}

void insere_na_lista(Lista *lista, Processo *processo)
{
    Celula celula;
    int posicao = get_numCelOcupados(lista);

    celula.processo = *processo;
    celula.ant = -1;
    celula.prox = -1;

    ((Celula *) lista->celulas)[posicao] = celula;

    if (lista->numCelOcupados == 0)
    {
        lista->primeiro = posicao;
        lista->ultimo = posicao;
    }
    else
    {
        lista->ultimo = posicao;
    }

    if (lista->numCelOcupados > 0)
    {
        coloca_em_ordem(lista);
    }

    lista->numCelOcupados += 1;
}

void remove_da_lista(Lista *lista)
{
    // Yet to implement
}