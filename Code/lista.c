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

void insere_na_lista(Lista *lista)
{
    unsigned int flag = 0;
    unsigned int meio_lista = 0;
    unsigned int celulas_usadas = get_numCelOcupados(lista);
    unsigned int loop_atual = 0;
    unsigned int esquerda_ou_direita = 0;
    Processo *processo;

    Celula *celulas = (Celula *) lista->celulas;

    // Procura binária
    while (!flag)
    {
        // Primeiro loop
        if (loop_atual == 0)
        {
            meio_lista = celulas_usadas / 2;
        }
        else
        {
            // esquerda_ou_direita | direita = 0 & esquerda = 1
            if (esquerda_ou_direita == 1)
            {
                meio_lista = meio_lista + (meio_lista / 2);
            }
            else
            {
                meio_lista = meio_lista / 2;
            }
        }

        // Adicionando a primeira célula
        if (celulas_usadas == 0)
        {
            // Colocando "-1" pois é a primeira célula.
            celulas[lista->celulasDisp].prox = -1;
            celulas[lista->celulasDisp].ant = -1;

            // Inicializando processo.
            processo = inicializa_processo();

            // Atualizando valores quantidade de células.
            celulas_usadas++;
            lista->celulasDisp++;
        }

        Processo anterior = *celulas[meio_lista].processo;
        Processo proximo = *celulas[meio_lista++].processo;

        if (get_PID(processo) > anterior.PID)
        {
            if (get_PID(processo) > proximo.PID)
            {
                esquerda_ou_direita = 1;
            }
            else
            {
                for (int i = celulas[meio_lista].ant + 1; i < celulas_usadas; i++)
                {

                }

                // Alterando os indexes na célula atual.
                celulas[celulas_usadas].ant = (int) celulas_usadas - 1;
                celulas[celulas_usadas].prox = (int) celulas_usadas;

                // Alterando os indexes na próxima célula.
                celulas[celulas_usadas + 1].ant = (int) celulas_usadas;
                celulas[celulas_usadas + 1].prox = -1;

                // Atualizando valores quantidade de células.
                lista->celulasDisp++;
                celulas_usadas++;
                flag = 1;
            }
        }
        else
        {
            esquerda_ou_direita = 0;
        }

        loop_atual++;
    }
}

void remove_da_lista(Lista *lista)
{
    Celula *celulas = (Celula *) lista->celulas;

    free(celulas[lista->primeiro].processo);
    celulas[lista->primeiro].prox = (int) lista->celulasDisp;
    celulas[lista->primeiro + 1].ant = -1;
    lista->celulasDisp = lista->primeiro;
}