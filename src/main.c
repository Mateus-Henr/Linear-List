#include "teste.h"

//int main(void)
//{

    // ---------------------------------------------- TESTE LISTA ------------------------------------------------------

//    TLista *lista = inicializa_lista(5);
//
//
//    for (int i = 0; i < lista->tamanho; i++)
//    {
//        insere_na_lista(lista);
//    }
//
//    printf("\nInformation about the list");
//    printf("\nSize of the list: %d", lista->tamanho);
//    printf("\nUsed cells: %d", get_numCelOcupados(lista));
//    printf("\nFirst position index = %d | Last position index = %d", lista->primeiro, lista->ultimo);
//
//    printf("\n\nDisplaying contents");
//    imprime_conteudo(lista);
//
//    // TESTING REMOVAL
//    printf("\n\nREMOVENDO\n");
//
//    for (int i = 0; i < lista->tamanho; i++)
//    {
//        remove_da_lista(lista);
//    }
//
//    imprime_conteudo(lista);
//
//    for (int i = 0; i < lista->tamanho / 2; i++)
//    {
//        insere_na_lista(lista);
//    }

//    imprime_conteudo(lista);

    // -----------------------------------------------------------------------------------------------------------------


    // ---------------------------------------------- TESTE ARQUIVO ----------------------------------------------------

//    gera_arquivo(10, 10, 1000);
//    TLista *lista = ler_arquivo("teste5ds");
//    if (lista)
//    {
//        imprime_conteudo(lista);
//    }
//
//    // -----------------------------------------------------------------------------------------------------------------
//
//    return 0;
//}

#include <stdio.h>
#include <time.h>
#define ZERO 0
#define EXIT 0
#define TRUE 1
#define CHAR_MAX 100
#define PRIMEIRA_OPCAO 1
#define SEGUNDA_OPCAO 2
#define MOSTRAR_OPCOES 3
#define OPCAO_INVALIDA "\nOpcao Invalida\n"


int main(void)
{
    int begin;
    int loop = TRUE;

    while (loop)
    {
        int escolha = -1;
        printf("Ola, ");
        printf("Digite a opcao:");
        mostrar_opcoes();
        if (!scanf("%d", &escolha))
        {
            printf(OPCAO_INVALIDA);
            continue;
        }

        switch (escolha)
        {
            case EXIT:
                printf("\nBye");
                loop = ZERO;
                break;
            case PRIMEIRA_OPCAO:
                printf("Informacoes de arquivo\n");
                printf("[1] Criar\n[2] Ler Arquivo\n");
                if (!scanf("%d", &escolha))
                {
                    printf(OPCAO_INVALIDA);
                    break;
                }
                if (escolha == PRIMEIRA_OPCAO)
                {
                    unsigned int qtd_operacoes, num_arquivo, tamanho_lista;

                    printf("\nDigite a quantidade de operacoes: ");
                    if (!scanf("%d", &qtd_operacoes))
                    {
                        printf(OPCAO_INVALIDA);
                        break;
                    }

                    printf("\nDigite o numero do arquivo que deseja criar: ");
                    if (!scanf("%d", &num_arquivo))
                    {
                        printf(OPCAO_INVALIDA);
                        break;
                    }

                    printf("\nDigite o tamanho da lista para o arquivo: ");
                    if (!scanf("%d", &tamanho_lista))
                    {
                        printf(OPCAO_INVALIDA);
                        break;
                    }

                    gera_arquivo(qtd_operacoes, num_arquivo, tamanho_lista);
                    printf("\nArquivo gerado!\n");
                }
                else if (escolha == SEGUNDA_OPCAO)
                {
                    char nome_arquivo[CHAR_MAX];
                    printf("Digite o nome do Arquivo:\n");
                    scanf("%s", nome_arquivo);


                    TLista *lista = ler_arquivo(nome_arquivo);
                    imprime_conteudo(lista);

                    break;
                }
                else
                {
                    printf(OPCAO_INVALIDA);
                }
                break;
            case SEGUNDA_OPCAO:
                printf("Digite os valores: ");
                break;
            case MOSTRAR_OPCOES:
                mostrar_opcoes();
                break;
            default:
                printf(OPCAO_INVALIDA);
                break;
        }
    }
    return ZERO;
}