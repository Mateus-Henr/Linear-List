#include "lista.h"
#include <stdlib.h>

Lista *inicializa_lista(unsigned int tamanho)
{
    // Alocando espaços para as estruturas.
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    lista->celulas = (struct Celula *) malloc(tamanho * sizeof(Celula));

    // Inicialização das células vazias.
    for (int posicao = 0; posicao < tamanho; posicao++)
    {
        Celula celula;

        if (posicao == 0)
        {
            celula.ant = -1;
            lista->primeiro = -1;
            lista->ultimo = -1;
        }
        else
        {
            celula.ant = posicao;
            lista->ultimo = posicao;
        }

        if (posicao == (tamanho - 1))
        {
            celula.prox = -1;
        }
        else
        {
            celula.prox = posicao++;
        }

        ((Celula *) lista->celulas)[posicao] = celula;
    }

    lista->numCelOcupados = 0;
    lista->tamanho = tamanho;
    lista->celulasDisp = 0;

    return lista;
}

unsigned int get_numCelOcupados(Lista *lista)
{
    return lista->numCelOcupados;
}

void insere(Lista *lista, Processo *processo)
{
    int in = 0, meio = 0, cont, comand, salvador;
    Processo anterior, proxim, save, save2;
    unsigned int celulas_usadas = get_numCelOcupados(lista);
    Celula *celulas = (Celula) lista->celulas;
    Celula copia_celulas[celulas_usadas];

    for (int i = 0; i < celulas_usadas; i++)
    {
        copia_celulas[i] = celulas[i];
    }
    while (in == 0)
    {
        if (cont == 0)
        {
            meio = celulas_usadas / 2;
        }
        else
        {
            if (comand == 1)
            {
                meio = meio + (meio / 2);
            }
            else
            {
                meio = meio / 2;
            }

        }
        if(celulas_usadas==0){
            celulas[lista->celulasDisp].prox=-1;
            inicializa_processo(celulas[lista->celulasDisp].processo);
            celulas_usadas++;
            lista->celulasDisp++;
            celulas[lista->celulasDisp].ant=-1;

        }
        anterior = copia_celulas[meio].processo;
        proxim = copia_celulas[meio++].processo;
        if (processo->PID > anterior.PID)
        {
            if (processo->PID > proxim.PID) { comand = 1; }
            else
            {


                for (int i = copia_celulas[meio++].ant + 1; i < celulas_usadas; i++)
                {


                }

                lista->celulasDisp++;
                celulas_usadas++;


                copia_celulas[celulas_usadas].prox = celulas_usadas;
                copia_celulas[celulas_usadas + 1].prox = -1;
                copia_celulas[celulas_usadas + 1].ant = celulas_usadas;
                in = 1;
            }
        }
        if (processo->PID < anterior.PID) { comand = 0; }
    }
}

void remove_da_lista(Lista *lista)
{
    int in = 0, meio = 0, cont, comand, salvador;
    Processo anterior, proxim, save, save2;
    unsigned int celulas_usadas = get_numCelOcupados(lista);
    Celula *celulas = (Celula) lista->celulas;

    free(celulas[lista->primeiro].processo);
}