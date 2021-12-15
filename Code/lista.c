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
        Celula celula;

        if (posicao == 0)
        {
            celula.ant = INICIO_DA_LISTA;
            lista->primeiro = 0;
        }
        else
        {
            celula.ant = posicao;
            lista->ultimo = posicao;
        }

        if (posicao == (tamanho - 1))
        {
            celula.prox = FINAL_DA_LISTA;
        }
        else
        {
            celula.prox = posicao + 1;
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

    lista->celulasDisp = get_celula_disponivel(lista);
    celulas[lista->celulasDisp].processo = processo_para_adicionar;
    lista->ultimo = lista->celulasDisp;

    // Se for o primeiro elemento sendo adicionado na lista.
    if (get_numCelOcupados(lista) == 0)
    {
        celulas[lista->celulasDisp].ant = INICIO_DA_LISTA;
        celulas[lista->celulasDisp].prox = FINAL_DA_LISTA;

        // Como só temos um elemento apontaremos para esse único elemento.
        lista->primeiro = lista->celulasDisp;
        lista->ultimo = lista->celulasDisp;
    }
    else // Executa a partir do segundo elemento.
    {
        // Começando a partir do primeiro elemento.
        int elemento_atual = (int) lista->primeiro;

        // Esse valor é usado da seguinte forma:
        // true = existe um valor na lista maior que o elemento que será adicionado.
        // false = não existe um valor na lista maior que o elemento que será adicionado.
        //         Dessa forma será colocado com indexes de final de lista.
        unsigned int encontrou_posicao = 0;

        int temp_ultima_celula;

        // Enquanto elemento atual não for o último elemento.
        while (elemento_atual != FINAL_DA_LISTA)
        {
            // Pegando o processo inicial para comparar com o processo a ser inserido.
            Processo *processo_atual = celulas[elemento_atual].processo;


            // --------------------------- Encontrado a posição para o elemento. --------------------------- /
            // Comparando para ver se existe algum elemento maior do que o que será adicionado.
            if (get_PID(processo_atual) > get_PID(processo_para_adicionar))
            {
                encontrou_posicao = 1;

                // Alterando o valor da nova célula com o valor da célula maior que encontramos.
                if (celulas[elemento_atual].ant == INICIO_DA_LISTA)
                {
                    // Definindo os indexes corretos caso o elemento se torne o primeiro da lista.
                    celulas[lista->celulasDisp].ant = INICIO_DA_LISTA;
                    celulas[lista->celulasDisp].prox = celulas[elemento_atual].prox;
                }
                else
                {
                    // Definindo os indexes corretos caso o elemento entre em qualquer outro lugar da lista.
                    // É importante lembrar que a posição não poderá ser o último da lista, pois não haverá um elemento
                    // maior do que ele, em outras palavras, a condição "Parent" não será verdadeira.
                    celulas[lista->celulasDisp].ant = celulas[elemento_atual].ant;
                    celulas[lista->celulasDisp].prox = celulas[elemento_atual].prox;
                }

                // Inicializando variáveis para salvar os valores, para editar os indexes dos elementos que vem depois
                // do elemento adicionado.
                int temp_ant;
                int temp_prox;

                // Loop para organizar elementos que vem depois do adicionado.
                while (elemento_atual != FINAL_DA_LISTA)
                {
                    // Checkando se a próxima célula existe.
                    if (celulas[celulas[celulas[elemento_atual].prox].prox].processo != NULL)
                    {
                        temp_ant = celulas[celulas[elemento_atual].prox].prox;
                    }
                    else
                    {
                        break;
                    }

                    // Checkando se a célula depois da próxima existe para mudar o valor.
                    if (celulas[celulas[celulas[celulas[elemento_atual].prox].prox].prox].processo != NULL)
                    {
                        temp_prox = celulas[celulas[celulas[elemento_atual].prox].prox].prox;
                    }
                    else
                    {
                        // Se a próxima célula não existir teremos o final da lista.
                        temp_prox = FINAL_DA_LISTA;
                    }

                    // Passando os valores para os próximos elementos.
                    celulas[elemento_atual].ant = temp_ant;
                    celulas[elemento_atual].prox = temp_prox;

                    // Mudando o valor do elemento atual de forma a ele pegar o próximo index.
                    elemento_atual = celulas[temp_prox].prox;
                }
            }

            // Condição para checkar se o valor já não é o fim da lista (devido ao loop acima).
            if (elemento_atual != FINAL_DA_LISTA)
            {
                // Mudando o valor do elemento para loopar na lista toda.
                elemento_atual = celulas[elemento_atual].prox;
            }
        }

        // Executa se o acima loop chegar ao final da lista e não encontrar uma posição para o elemento a ser adicionado.
        if (!encontrou_posicao)
        {
            // "elemento_atual" será o último elemento devido ao loop.
            if (get_numCelOcupados(lista) == 1)
            {
                celulas[0].prox = 1;
            }
            else
            {
                // Definindo o novo index para o elemento que ERA o último.
                celulas[celulas[lista->celulasDisp].ant].prox = (int) lista->ultimo;
                printf("%d\n", celulas[celulas[lista->celulasDisp].ant].prox);
            }

            // Coloca indexes do final da lista já que não foram encontrados elementos menores.
            celulas[lista->celulasDisp].ant = (int) lista->ultimo;
            celulas[lista->celulasDisp].prox = FINAL_DA_LISTA;
        }

    }
    imprime_celulas(lista);

    lista->numCelOcupados++;
}

void remove_da_lista(Lista *lista)
{
    Celula *celulas = (Celula *) lista->celulas;

    free(celulas[lista->primeiro].processo);
    celulas[lista->primeiro].prox = (int) lista->celulasDisp;
    celulas[lista->primeiro + 1].ant = -1;
    lista->celulasDisp = lista->primeiro;
}

void imprime_celulas(Lista *lista)
{
    Celula *celulas = (Celula *) lista->celulas;

    for (int i = 0; i < lista->tamanho; i++)
    {
        printf("Celula\n"
               "ant = %d | prox = %d\n\n",
               celulas[i].ant, celulas[i].prox);
    }
}