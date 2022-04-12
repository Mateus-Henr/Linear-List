#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "lista.h"

#define FINAL_DA_LISTA -1
#define INICIO_DA_LISTA -1
#define INVALIDO -1
#define MENOS_UM -1;
#define VALOR_INICIAL 0
#define NENHUM_ELEMENTO 0
#define UM 1
#define ELEMENTO_INICIAL 0
#define LISTA_VAZIA "Lista Vazia!\n"
#define PRINT_ELEMENTO "\n\nPosicao elemento = %d\nPID = %d\nant = %d | prox = %d\n"

/*
 * Essa função é usada para inicializar uma lista. Primeiramente ocorre alocações na memória do array contido nessa
 * estrutura. Após a alocação são inicializadas "Celulas" com cursores predefinidos aos quais
 * apontam para uma próxima célula e uma célula anterior, esses cursores serão posições no array.
 * Então essas "Celulas" são colocadas no array.
 * Há também a inicialização de valores iniciais para as variáveis da estrutura "Lista".
 */
void inicializaLista(Lista *lista, unsigned int tamanho)
{
    // Alocando espaço na memória para o array que compõe a estrutura lista (tamanho informado pelo usuário).
    lista->celulas = (Celula *) malloc(tamanho * sizeof(Celula));

    // Inicialização das células vazias definindo os cursores iniciais para cada uma delas.
    // Um cursor apontará para a próxima célula e o outro apontará para a célula anterior.
    // Extremidades são iguais a "-1".
    for (int posicao = VALOR_INICIAL; posicao < tamanho; posicao++)
    {
        Celula celula;

        celula.ant = MENOS_UM;

        if (posicao == (tamanho - UM))
        {
            celula.prox = FINAL_DA_LISTA;
        }
        else
        {
            celula.prox = posicao + UM;
        }

        celula.processo = NULL;
        ((Celula *) lista->celulas)[posicao] = celula; // Colocando célula no array.
    }

    // Inicializando demais variáveis lista.
    lista->numCelOcupados = NENHUM_ELEMENTO;
    lista->tamanho = tamanho;
    lista->celulasDisp = NENHUM_ELEMENTO;
}


/*
 * Retorna número atual de células sendo ocupadas na lista.
 *
 * @param    lista    ponteiro para a estrutura Lista.
 * @return            número de células ocupadas.
 */
int tamanho(Lista *lista)
{
    return lista->numCelOcupados;
}


/*
 * Função usada para adicionar um elemento na lista.
 * Primeiramente tentamos achar uma célula disponível (posição no vetor) para adicionar um processo que é gerado pelo
 * método "inicializa_processo()".
 * Como a lista deve se manter ordenada os elementos já são colocados nas posições corretas, sendo as mesmas definidas
 * pelo PID do processo de cada célula. Em outras palavras, os cursores das células serão usados para ordenar as mesmas
 * na lista de forma que o PID esteja em uma ordem crescente.
 */
bool insereOrdenado(Lista *lista)
{
    // Checando se há célula disponível.
    if (lista->celulasDisp == INVALIDO)
    {
        // Lista cheia.
        if (tamanho(lista) == lista->tamanho)
        {
            return false;
        }

        lista->celulasDisp = ELEMENTO_INICIAL;
    }

    // Inicializando processo para adicionar a uma célula.
    TProcesso *processo_para_adicionar = inicializa_processo();
    Celula *celulas = (Celula *) lista->celulas;
    int proxCelulaDisp = celulas[lista->celulasDisp].prox;

    // Colocando o processo na posição disponível encontrada.
    celulas[lista->celulasDisp].processo = processo_para_adicionar;

    if (tamanho(lista) == NENHUM_ELEMENTO)
    {
        celulas[lista->celulasDisp].prox = MENOS_UM;
        lista->primeiro = lista->celulasDisp;
        lista->ultimo = lista->celulasDisp;
    }
    else if (get_PID(celulas[lista->celulasDisp].processo) < get_PID(celulas[lista->primeiro].processo))
    {
        celulas[lista->celulasDisp].prox = lista->primeiro;
        celulas[lista->primeiro].ant = lista->celulasDisp;
        lista->primeiro = lista->celulasDisp;
    }
    else if (get_PID(celulas[lista->celulasDisp].processo) >= get_PID(celulas[lista->ultimo].processo))
    {
        celulas[lista->ultimo].prox = lista->celulasDisp;
        celulas[lista->celulasDisp].ant = lista->ultimo;
        celulas[lista->celulasDisp].prox = MENOS_UM;
        lista->ultimo = lista->celulasDisp;
    }
    else
    {
        int currElement = lista->primeiro;

        while (get_PID(celulas[lista->celulasDisp].processo) > get_PID(celulas[currElement].processo))
        {
            currElement = celulas[currElement].prox;
        }

        celulas[celulas[currElement].ant].prox = lista->celulasDisp;
        int antCurrElement = celulas[currElement].ant;
        celulas[currElement].ant = lista->celulasDisp;

        celulas[lista->celulasDisp].ant = antCurrElement;
        celulas[lista->celulasDisp].prox = currElement;
    }

    lista->celulasDisp = proxCelulaDisp;
    lista->numCelOcupados++;

    return true;
}


/*
 * Remove o elemento na primeira posição da lista.
 *
 * @param    lista    ponteiro para a estrutura Lista.
 * @return            sucesso na operação.
 */
bool removeFrente(Lista *lista)
{
    // Checando se a lista está vazia.
    if (tamanho(lista) == NENHUM_ELEMENTO)
    {
        return false;
    }

    Celula *celulas = (Celula *) lista->celulas;

    // Liberando o processo na memória.
    free(celulas[lista->primeiro].processo);
    celulas[lista->primeiro].processo = NULL;

    int tempPrimeiro = lista->primeiro;
    int tempPrimeiroProx = celulas[lista->primeiro].prox;

    // Apontando para a próxima célula disponível.
    celulas[lista->primeiro].ant = INICIO_DA_LISTA;
    celulas[lista->primeiro].prox = lista->celulasDisp;

    // Checando se a célula atual não é a última.
    if (tempPrimeiroProx != FINAL_DA_LISTA)
    {
        // Tornando o próximo elemento início da lista.
        celulas[tempPrimeiroProx].ant = INICIO_DA_LISTA;
        lista->primeiro = tempPrimeiroProx;
        lista->celulasDisp = tempPrimeiro;
    }
    else // Caso e a última célula na lista.
    {
        lista->ultimo = lista->primeiro;
    }

    // Após remover o elemento temos que decrementar o número de células ocupadas.
    lista->numCelOcupados--;

    return true;
}


/*
 * Imprime a lista.
 *
 * @param    lista    ponteiro para a estrutura Lista.
 */
void imprimeData(Lista *lista)
{
    // Caso não haja nenhum elemento.
    if (tamanho(lista) == NENHUM_ELEMENTO)
    {
        printf(LISTA_VAZIA);
        return;
    }

    Celula *celulas = (Celula *) lista->celulas;
    int elemento_atual = lista->primeiro;

    // Usando loop até chegar ao final da lista.
    while (elemento_atual != FINAL_DA_LISTA)
    {
        printf(PRINT_ELEMENTO,
               elemento_atual, celulas[elemento_atual].processo->PID,
               celulas[elemento_atual].ant,
               celulas[elemento_atual].prox);

        elemento_atual = celulas[elemento_atual].prox;
    }
}


/*
 * Limpa a lista na memória.
 *
 * @param    lista    ponteiro para a estrutura Lista.
 */
void destroiLista(Lista *lista)
{
    Celula *celulas = (Celula *) lista->celulas;

    for (int i = VALOR_INICIAL; i < lista->tamanho; i++)
    {
        if (celulas[i].processo != NULL)
        {
            free(celulas[i].processo);
        }
    }

    free(lista->celulas);
}