#include "lista.h"
#include <stdlib.h>

#define FINAL_DA_LISTA -1
#define INICIO_DA_LISTA -1
#define INVALIDO -1
#define VALOR_INICIAL 0
#define NENHUM_ELEMENTO 0
#define TRUE 1
#define FALSE 0
#define UM 1
#define PRIMEIRO_ELEMENTO 0
#define LISTA_CHEIA "Lista cheia!\n"
#define LISTA_VAZIA "Lista Vazia!\n"
#define PRINT_ELEMENTO "\n\nPosicao elemento = %d\nPID = %d\nant = %d | prox = %d\n"

TLista *inicializa_lista(unsigned int tamanho)
{
    // Alocando espaços para as estruturas.
    TLista *lista = (TLista *) malloc(sizeof(TLista));
    lista->celulas = (struct Celula *) malloc(tamanho * sizeof(TCelula));

    // Inicialização das células vazias.
    for (int posicao = VALOR_INICIAL; posicao < tamanho; posicao++)
    {
        int posicao_anterior = posicao - UM;
        int posicao_proximo = posicao + UM;
        TCelula celula;

        celula.ant = posicao_anterior;

        if (posicao == (tamanho - UM))
        {
            celula.prox = FINAL_DA_LISTA;
        }
        else
        {
            celula.prox = posicao_proximo;
        }

        celula.processo = NULL;
        ((TCelula *) lista->celulas)[posicao] = celula;
    }

    lista->numCelOcupados = NENHUM_ELEMENTO;
    lista->tamanho = tamanho;
    lista->celulasDisp = NENHUM_ELEMENTO;

    return lista;
}

unsigned int get_numCelOcupados(TLista *lista)
{
    return lista->numCelOcupados;
}

int get_celula_disponivel(TLista *lista)
{
    int celula_disponivel = INVALIDO;
    TCelula *celulas = (TCelula *) lista->celulas;

    for (int i = VALOR_INICIAL; i < lista->tamanho; i++)
    {
        if (celulas[i].processo == NULL)
        {
            celula_disponivel = i;
            break;
        }
    }

    return celula_disponivel;
}

void insere_na_lista(TLista *lista)
{
    TProcesso *processo_para_adicionar = inicializa_processo();
    TCelula *celulas = (TCelula *) lista->celulas;
    int get_primeira_celula_disponivel = get_celula_disponivel(lista);

    if (get_primeira_celula_disponivel == INVALIDO)
    {
        printf(LISTA_CHEIA);
        return;
    }

    // Valores iniciais para inserir um novo elemento.
    // Posição no array do elemento a ser adicionado.
    lista->celulasDisp = get_primeira_celula_disponivel;
    celulas[lista->celulasDisp].processo = processo_para_adicionar;

    // ------------------------------------------- PRIMEIRO ELEMENTO ---------------------------------------------------
    // Se for o primeiro elemento sendo adicionado na lista.
    if (get_numCelOcupados(lista) == NENHUM_ELEMENTO)
    {
        celulas[lista->celulasDisp].ant = INICIO_DA_LISTA;
        celulas[lista->celulasDisp].prox = FINAL_DA_LISTA;

        // Como só temos um elemento apontaremos para esse único elemento.
        lista->primeiro = (int) lista->celulasDisp; // É 0.
        lista->ultimo = (int) lista->celulasDisp; // É 0.
    }
        // -------------------------------------------------------------------------------------------------------------


        // ------------------------------------------- OUTROS ELEMENTOS ------------------------------------------------
    else
    {
        unsigned int encontrou_posicao = FALSE;
        int elemento_atual = lista->primeiro;

        while (elemento_atual != FINAL_DA_LISTA)
        {
            TProcesso *processo_atual = celulas[elemento_atual].processo;

            if (get_PID(processo_atual) > get_PID(processo_para_adicionar))
            {
                encontrou_posicao = TRUE;

                if (celulas[elemento_atual].ant == INICIO_DA_LISTA)
                {
                    celulas[lista->primeiro].ant = (int) lista->celulasDisp;
                    celulas[lista->celulasDisp].prox = lista->primeiro;
                    celulas[lista->celulasDisp].ant = FINAL_DA_LISTA;
                    lista->primeiro = (int) lista->celulasDisp;
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

// SHIT CODE FIX IT JOÃO
void remove_da_lista(TLista *lista)
{
    TCelula *celulas = (TCelula *) lista->celulas;

    // Checando se a lista está vazia.
    if (get_numCelOcupados(lista) == NENHUM_ELEMENTO)
    {
        printf(LISTA_VAZIA);
        return;
    }

    if (celulas[lista->primeiro].prox != FINAL_DA_LISTA)
    {
        // Liberando o processo na memória.
        free(celulas[lista->primeiro].processo);

        // Colocando o processo como nulo para "setar" como uma célula disponível.
        celulas[lista->primeiro].processo = NULL;


        celulas[lista->primeiro].ant = celulas[celulas[lista->primeiro].prox].ant;
        if (celulas[celulas[lista->primeiro].prox].prox != FINAL_DA_LISTA)
        {
            celulas[celulas[lista->primeiro].prox].ant = INICIO_DA_LISTA;
        }
        lista->primeiro = celulas[lista->primeiro].prox;
        celulas[PRIMEIRO_ELEMENTO].ant = INICIO_DA_LISTA;
    }
    else
    {
        free(celulas[lista->ultimo].processo);
        celulas[lista->ultimo].processo = NULL;
        lista->primeiro = PRIMEIRO_ELEMENTO;
        lista->ultimo = (int) lista->tamanho;
    }


    lista->numCelOcupados--;
}

void imprime_conteudo(TLista *lista)
{
    if (get_numCelOcupados(lista) == 0)
    {
        printf(LISTA_VAZIA);
        return;
    }

    TCelula *celulas = (TCelula *) lista->celulas;
    int elemento_atual = (int) lista->primeiro;

    while (elemento_atual != FINAL_DA_LISTA)
    {
        printf(PRINT_ELEMENTO,
               elemento_atual, celulas[elemento_atual].processo->PID,
               celulas[elemento_atual].ant,
               celulas[elemento_atual].prox);

        elemento_atual = celulas[elemento_atual].prox;
    }
}