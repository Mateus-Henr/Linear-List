#include <stdio.h>
#include <locale.h>
#include "teste.c"

#define ZERO 0
#define EXIT 0
#define PRIMEIRA_OPCAO 1
#define SEGUNDA_OPCAO 2
#define MOSTRAR_OPCOES 3
#define OPCAO_INVALIDA "\nOpção Inválida\n"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    int loop = 1;
    gera_arquivo(500, 16, 1000);

    while (loop)
    {
        int escolha = -1;
        printf("Olá");
        printf("Digite a opção:");
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
                printf("Informações de arquivo\n");
                if (!scanf("%d", &escolha))
                {
                    printf(OPCAO_INVALIDA);
                    break;
                }
                if (escolha == PRIMEIRA_OPCAO)
                {
                    unsigned int qtd_operacoes, num_arquivo, tamanho_lista;

                    printf("\nDigite a quantidade de operações: ");
                    if (!scanf("%d", &qtd_operacoes))
                    {
                        printf(OPCAO_INVALIDA);
                        break;
                    }

                    printf("\nDigite o número do arquivo que deseja criar: ");
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
                }
                else if (escolha == SEGUNDA_OPCAO)
                {
//                        ler_aquivo();
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