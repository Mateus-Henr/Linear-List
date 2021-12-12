#include "lista.h"
#include <stdlib.h>

Lista *inicializa_lista(unsigned int tamanho)
{
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    lista->celulas = (struct Celula *) malloc(tamanho * sizeof(Celula));

    lista->numCelOcupados = 0;
    lista->tamanho = tamanho;

    return lista;
}

unsigned int get_numCelOcupados(Lista *lista)
{
    return lista->numCelOcupados;
}

void coloca_em_ordem(Lista *lista)
{
    int flag = 0;
    unsigned int celulas_usadas = get_numCelOcupados(lista);

    Celula *celulas = (Celula *) lista->celulas;
    Celula copia_celulas[celulas_usadas];

    for (int i = 0; i < celulas_usadas; i++)
    {
        copia_celulas[i] = celulas[i];
    }

    while (!flag)
    {
        flag = 1;
        for (int i = 0; i < (celulas_usadas - 1); i++)
        {
            Processo *atual = &copia_celulas[i].processo;
            Processo *prox = &copia_celulas[i + 1].processo;
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
        for (int j = 0; j < celulas_usadas; j++)
        {
            if (copia_celulas[i].processo.PID == celulas[j].processo.PID)
            {
                celulas[j].ant = i;

                if (i == 0)
                {
                    celulas[j].ant = -1;
                    lista->primeiro = j;
                }

                if (i == celulas_usadas - 1)
                {
                    celulas[j].prox = -1;
                    lista->ultimo = j;
                }
                else
                {
                    celulas[j].prox = i + 1;
                }
                break;
            }
        }
    }
}

void insere_na_lista(Lista *lista, Processo *processo)
{
    Celula celula;
    unsigned int posicao = get_numCelOcupados(lista);

    celula.processo = *processo;
    celula.ant = -1;
    celula.prox = -1;

    ((Celula *) lista->celulas)[posicao] = celula;

    if (lista->numCelOcupados == 0)
    {
        lista->primeiro = posicao;
        lista->ultimo = posicao;
    }

    lista->numCelOcupados += 1;

}

void remove_da_lista(Lista *lista)
{
}