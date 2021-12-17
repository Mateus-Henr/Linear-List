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
#define LISTA_CHEIA "Lista cheia!\n"
#define LISTA_VAZIA "Lista Vazia!\n"
#define PRINT_ELEMENTO "\n\nPosicao elemento = %d\nPID = %d\nant = %d | prox = %d"

Lista *inicializa_lista(unsigned int tamanho)
{
    // Alocando espaços para as estruturas.
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    lista->celulas = (struct Celula *) malloc(tamanho * sizeof(Celula));

    // Inicialização das células vazias.
    for (int posicao = VALOR_INICIAL; posicao < tamanho; posicao++)
    {
        int posicao_anterior = posicao - UM;
        int posicao_proximo = posicao + UM;
        Celula celula;

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
        ((Celula *) lista->celulas)[posicao] = celula;
    }

    lista->numCelOcupados = NENHUM_ELEMENTO;
    lista->tamanho = tamanho;
    lista->celulasDisp = NENHUM_ELEMENTO;

    return lista;
}

unsigned int get_numCelOcupados(Lista *lista)
{
    return lista->numCelOcupados;
}

int get_celula_disponivel(Lista *lista)
{
    int celula_disponivel = INVALIDO;
    Celula *celulas = (Celula *) lista->celulas;

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

void insere_na_lista(Lista *lista)
{
    Processo *processo_para_adicionar = inicializa_processo();
    Celula *celulas = (Celula *) lista->celulas;
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
            Processo *processo_atual = celulas[elemento_atual].processo;

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
void remove_da_lista(Lista *lista)
{
    Celula *celulas = (Celula *) lista->celulas;

    // Checando se a lista está vazia.
    if (lista->numCelOcupados == NENHUM_ELEMENTO || lista->primeiro == FINAL_DA_LISTA)
    {
        printf(LISTA_VAZIA);
        return;
    }

    // Liberando o processo na memória.
    free(celulas[lista->primeiro].processo);

    // Colocando o processo como nulo para "setar" como uma célula disponível.
    celulas[lista->primeiro].processo = NULL;

    if (celulas[lista->primeiro].prox != FINAL_DA_LISTA)
    {
        celulas[lista->primeiro].ant = celulas[celulas[lista->primeiro].prox].ant;
        celulas[0].ant = -1;
        celulas[celulas[lista->primeiro].prox].ant = INICIO_DA_LISTA;
        lista->primeiro = celulas[lista->primeiro].prox;
    }

    lista->numCelOcupados--;
}

void imprime_conteudo(Lista *lista)
{
    Celula *celulas = (Celula *) lista->celulas;
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