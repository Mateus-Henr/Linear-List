#include "lista.h"
#include <stdlib.h>

#define FINAL_DA_LISTA -1
#define INICIO_DA_LISTA -1

void imprime_celulas(Lista *lista);

Lista *inicializa_lista(unsigned int tamanho)
{
    // Alocando espaços para as estruturas.
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    lista->celulas = (struct Celula *) malloc(tamanho * sizeof(Celula));

    // Inicialização das células vazias.
    for (int posicao = 0; posicao < tamanho; posicao++)
    {
        int posicao_anterior = posicao - 1;
        int posicao_proximo = posicao + 1;
        Celula celula;

        celula.ant = posicao_anterior;

        if (posicao == (tamanho - 1))
        {
            celula.prox = FINAL_DA_LISTA;
        }
        else
        {
            celula.prox = posicao_proximo;
        }

        celula.processo = NULL;
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

int get_celula_disponivel(Lista *lista)
{
    int celula_disponivel = -1;
    Celula *celulas = (Celula *) lista->celulas;

    for (int i = 0; i < lista->tamanho; i++)
    {
        if (celulas[i].processo == NULL)
        {
            celula_disponivel = i;
            break;
        }
    }

    return celula_disponivel;
}

void insere_na_lista(Lista *lista)
{
    Processo *processo_para_adicionar = inicializa_processo();
    Celula *celulas = (Celula *) lista->celulas;
    int get_primeira_celula_disponivel = get_celula_disponivel(lista);

    if (get_primeira_celula_disponivel == -1)
    {
        printf("Lista cheia!");
        return;
    }

    // Valores iniciais para inserir um novo elemento.
    // Posição no array do elemento a ser adicionado.
    lista->celulasDisp = get_primeira_celula_disponivel;
    celulas[lista->celulasDisp].processo = processo_para_adicionar;

    // ------------------------------------------- PRIMEIRO ELEMENTO ---------------------------------------------------
    // Se for o primeiro elemento sendo adicionado na lista.
    if (get_numCelOcupados(lista) == 0)
    {
        celulas[lista->celulasDisp].ant = INICIO_DA_LISTA;
        celulas[lista->celulasDisp].prox = FINAL_DA_LISTA;

        // Como só temos um elemento apontaremos para esse único elemento.
        lista->primeiro = lista->celulasDisp; // É 0.
        lista->ultimo = lista->celulasDisp; // É 0.
    }
        // -------------------------------------------------------------------------------------------------------------


        // ------------------------------------------- OUTROS ELEMENTOS ------------------------------------------------
    else
    {
        unsigned int encontrou_posicao = 0;
        int elemento_atual = (int) lista->primeiro;

        while (elemento_atual != FINAL_DA_LISTA)
        {
            Processo *processo_atual = celulas[elemento_atual].processo;

            if (get_PID(processo_atual) > get_PID(processo_para_adicionar))
            {
                encontrou_posicao = 1;

                if (celulas[elemento_atual].ant == INICIO_DA_LISTA)
                {
                    celulas[lista->primeiro].ant = (int) lista->celulasDisp;
                    celulas[lista->celulasDisp].prox = (int) lista->primeiro;
                    celulas[lista->celulasDisp].ant = FINAL_DA_LISTA;
                    lista->primeiro = lista->celulasDisp;
                }
                else if (celulas[elemento_atual].prox == FINAL_DA_LISTA)
                {
                    celulas[lista->celulasDisp].prox = celulas[celulas[elemento_atual].ant].prox;
                    celulas[celulas[elemento_atual].ant].prox = (int) lista->celulasDisp;
                    celulas[lista->celulasDisp].ant = celulas[elemento_atual].ant;
                    celulas[lista->ultimo].ant = (int) lista->celulasDisp;
                }
                else
                {
                    int anterior = celulas[elemento_atual].ant;
                    celulas[celulas[elemento_atual].ant].prox = (int) lista->celulasDisp;
                    celulas[elemento_atual].ant = (int) lista->celulasDisp;
                    celulas[lista->celulasDisp].ant = anterior;
                    celulas[lista->celulasDisp].prox = elemento_atual;
                }

                break;
            }

            elemento_atual = celulas[elemento_atual].prox;
            if (elemento_atual != FINAL_DA_LISTA)
            {
                lista->ultimo = elemento_atual;
            }
        }

        if (!encontrou_posicao)
        {
            celulas[lista->ultimo].prox = (int) lista->celulasDisp;
            celulas[lista->celulasDisp].prox = FINAL_DA_LISTA;
            lista->ultimo = (int) lista->celulasDisp;
        }
    }

    lista->numCelOcupados++;
}

// NOT COMPLETELY DONE YET
void remove_da_lista(Lista *lista)
{
    Celula *celulas = (Celula *) lista->celulas;

    if (lista->numCelOcupados == 0)
    {
        printf("Lista Vazia!");
        return;
    }

    free(celulas[lista->primeiro].processo);
    celulas[lista->primeiro].processo = NULL;

    if (celulas[lista->primeiro].prox != FINAL_DA_LISTA)
    {
        celulas[celulas[lista->primeiro].prox].ant = INICIO_DA_LISTA;
        lista->primeiro = celulas[lista->primeiro].prox;
    }

    lista->numCelOcupados--;
}

// NOT COMPLETELY DONE YET
void imprime_celulas(Lista *lista)
{
    Celula *celulas = (Celula *) lista->celulas;

    for (int i = 0; i < lista->tamanho; i++)
    {
        printf("Celula %d\n"
               "ant = %d | prox = %d\n\n",
               i, celulas[i].ant, celulas[i].prox);
    }
}

void imprime_conteudo(Lista *lista)
{
    Celula *celulas = (Celula *) lista->celulas;
    int elemento_atual = (int) lista->primeiro;

    while (1)
    {

        printf("\nPID %d\n"
               "ant = %d | prox = %d\n\n",
               celulas[elemento_atual].processo->PID, celulas[elemento_atual].ant, celulas[elemento_atual].prox);

        elemento_atual = celulas[elemento_atual].prox;

        if (elemento_atual == FINAL_DA_LISTA)
        {
            break;
        }
    }
}