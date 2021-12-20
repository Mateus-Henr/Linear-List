#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "teste.h"

#define UM 1
#define ZERO 0
#define EXIT 0
#define FALSO 0
#define VALOR_INICIAL 0
#define TRUE 1
#define INVALIDO -1
#define PRIMEIRA_OPCAO 1
#define SEGUNDA_OPCAO 2
#define MOSTRAR_OPCOES 3
#define VALOR_INVALIDO "\nValor Invalido\n"
#define NOME_ARQUIVO_INVALIDO "\nArquivo com nome '%s' nao encontrado.\n"
#define OPCAO_INVALIDA "\nOpcao Invalida\n"
#define LISTA_CHEIA "\nLista cheia!\n"
#define LISTA_VAZIA "\nLista Vazia!\n"

void mostrar_opcoes();

clock_t inicializa_relogio();

double finaliza_relogio(clock_t tempo_inicial);

void limpar_stdin();

int main(void)
{
    int loop = TRUE;
    int imprime_lista = TRUE;
    while (loop)
    {
        int escolha = INVALIDO;
        printf("\n\nSimulador de sistema de gerenciamento de processos");
        printf("\nDigite a opcao:");
        mostrar_opcoes();
        if (!scanf("%d", &escolha))
        {
            printf(OPCAO_INVALIDA);
            limpar_stdin();
            break;
        }

        switch (escolha)
        {
            case EXIT:
                printf("\nBye :(\n");
                loop = FALSO;
                break;
            case PRIMEIRA_OPCAO:
                printf("\nInformacoes de arquivo");
                printf("\n[1] Criar\n[2] Ler Arquivo\n");
                if (!scanf("%d", &escolha))
                {
                    printf(OPCAO_INVALIDA);
                    limpar_stdin();
                    system("cls");
                    break;
                }
                if (escolha == PRIMEIRA_OPCAO)
                {
                    int qtd_operacoes, num_arquivo, tamanho_lista;

                    printf("\nDigite a quantidade de operacao:\n");
                    if (!scanf("%d", &qtd_operacoes) || qtd_operacoes < 0)
                    {
                        printf(OPCAO_INVALIDA);
                        limpar_stdin();
                        break;
                    }

                    printf("\nDigite o numero do arquivo que deseja criar:\n");
                    if (!scanf("%d", &num_arquivo) || qtd_operacoes < 0)
                    {
                        printf(OPCAO_INVALIDA);
                        limpar_stdin();
                        break;
                    }

                    printf("\nDigite o tamanho da lista para o arquivo:\n");
                    if (!scanf("%d", &tamanho_lista) || tamanho_lista < 0)
                    {
                        printf(OPCAO_INVALIDA);
                        limpar_stdin();
                        break;
                    }

                    gera_arquivo(qtd_operacoes, num_arquivo, tamanho_lista);
                    printf("\nArquivo gerado!\n");
                }
                else if (escolha == SEGUNDA_OPCAO)
                {
                    char nome_arquivo[CHAR_MAX];
                    printf("\nDigite o nome do arquivo:\n");
                    scanf("%s", nome_arquivo);

                    clock_t tempo_inicial = inicializa_relogio();
                    TLista *lista = ler_arquivo(nome_arquivo);

                    // Checando se arquivo foi encontrado.
                    if (!lista)
                    {
                        printf(NOME_ARQUIVO_INVALIDO, nome_arquivo);
                        limpar_stdin();
                        break;
                    }

                    double tempo_gasto = finaliza_relogio(tempo_inicial);

                    printf("\nTempo em segundos: %0.2lf\n ", tempo_gasto);
                    arquivo_output(nome_arquivo, tempo_gasto);

                    printf("\nDeseja imprimir o conteudo da lista? [1] Sim [0] Nao\n");
                    if (!scanf("%d", &imprime_lista))
                    {
                        printf(VALOR_INVALIDO);
                        limpar_stdin();
                        break;
                    }

                    if (imprime_lista)
                    {
                        imprime_conteudo(lista);
                    }
                    else if (imprime_lista != FALSO)
                    {
                        printf(VALOR_INVALIDO);
                        limpar_stdin();
                        break;
                    }
                }
                else
                {
                    printf(OPCAO_INVALIDA);
                    limpar_stdin();
                    break;
                }
                break;
            case SEGUNDA_OPCAO:
                printf("\nInsercao de valores pelo usuario\n");
                int tamanho_lista;
                printf("\nDigite o tamanho da lista: \n");

                if (!scanf("%d", &tamanho_lista) || tamanho_lista < 0)
                {
                    printf(VALOR_INVALIDO);
                    limpar_stdin();
                    break;
                }

                TLista *lista = inicializa_lista(tamanho_lista);

                int continuar = TRUE;

                while (continuar)
                {
                    int insere_ou_remove, qtd_operacoes;
                    printf("\n[0] Insercoes  [1] Remocoes:\n ");

                    if (!scanf("%d", &insere_ou_remove))
                    {
                        printf(VALOR_INVALIDO);
                        limpar_stdin();
                        continue;
                    }

                    if (insere_ou_remove == ZERO)
                    {
                        printf("\nQuantidade de inserções:\n ");
                        if (!scanf("%d", &qtd_operacoes) || qtd_operacoes < 0)
                        {
                            printf(VALOR_INVALIDO);
                            limpar_stdin();
                            continue;
                        }

                        clock_t tempo_inicial = inicializa_relogio();

                        unsigned int resultado;

                        for (int i = VALOR_INICIAL; i < qtd_operacoes; i++)
                        {
                            resultado = insere_na_lista(lista);
                        }

                        if (!resultado)
                        {
                            printf(LISTA_CHEIA);
                        }

                        printf("\n%d insercoes concluidas com sucesso.\n", resultado);
                        printf("\nTempo em segundos: %0.2lf\n ", finaliza_relogio(tempo_inicial));

                        printf("\nDeseja imprimir o conteudo da lista? [1] Sim [0] Nao\n");
                        if (!scanf("%d", &imprime_lista))
                        {
                            printf(VALOR_INVALIDO);
                            limpar_stdin();
                            continue;
                        }

                        if (imprime_lista)
                        {
                            imprime_conteudo(lista);
                        }
                        else if (imprime_lista != FALSO)
                        {
                            printf(VALOR_INVALIDO);
                            limpar_stdin();
                            continue;
                        }
                    }
                    else if (insere_ou_remove == UM)
                    {
                        printf("\nQuantidade de remocoes:\n ");
                        if (!scanf("%i", &qtd_operacoes) || qtd_operacoes < 0)
                        {
                            printf(VALOR_INVALIDO);
                            limpar_stdin();
                            continue;
                        }

                        clock_t tempo_inicial = inicializa_relogio();

                        unsigned int resultado;
                        for (int i = VALOR_INICIAL; i < qtd_operacoes; i++)
                        {
                            resultado = remove_da_lista(lista);
                        }

                        if (!resultado)
                        {
                            printf(LISTA_VAZIA);
                        }

                        printf("\n%d Remocoes concluidas com sucesso.\n", resultado);
                        printf("\nTempo em segundos: %0.2lf\n ", finaliza_relogio(tempo_inicial));

                        printf("\nDeseja imprimir o conteudo da lista? [1] Sim [0] Nao\n");
                        if (!scanf("%d", &imprime_lista))
                        {
                            printf(VALOR_INVALIDO);
                            limpar_stdin();
                            continue;
                        }

                        if (imprime_lista)
                        {
                            imprime_conteudo(lista);
                        }
                        else if (imprime_lista != FALSO)
                        {
                            printf(VALOR_INVALIDO);
                            limpar_stdin();
                        }
                    }
                    else
                    {
                        printf(OPCAO_INVALIDA);
                        limpar_stdin();
                        continue;
                    }

                    printf("\nAdicionar mais insersoes ou remocoes?\n");
                    printf("\n[1] Sim [0] Nao\n");
                    if (!scanf("%i", &continuar))
                    {
                        printf(OPCAO_INVALIDA);
                        limpar_stdin();
                    }

                    if (!continuar)
                    {
                        printf("Parando...");
                        continuar = FALSO;
                    }
                    else if (continuar != UM)
                    {
                        printf(OPCAO_INVALIDA);
                        continuar = TRUE;
                        limpar_stdin();
                    }
                }
                break;
            case MOSTRAR_OPCOES:
                mostrar_opcoes();
                break;
            default:
                printf(OPCAO_INVALIDA);
                limpar_stdin();
                break;
        }
    }

    return ZERO;
}


/*
 * Esse método é usado para descrever as opções que o usuário pode escolher, por meio do console.
 */
void mostrar_opcoes()
{
    printf("\n0 - Sair\n");
    printf("1 - Arquivo\n");
    printf("2 - Digitar valores para teste\n");
}

void limpar_stdin(void)
{
    int c = getchar();

    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

clock_t inicializa_relogio(void)
{
    clock_t tempo_inicial = clock();

    return tempo_inicial;
}

double finaliza_relogio(clock_t tempo_inicial)
{
    clock_t tempo_final = clock();
    double tempo_gasto = (double) (tempo_final - tempo_inicial) / CLOCKS_PER_SEC;

    return tempo_gasto;
}