#include "teste.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CEM 100
#define ZERO 0
#define DOIS 2
#define NOME_ARQUIVO_USUARIO "..//..//Arquivos//%s.txt"
#define TAMANHO_STRING_ARQUIVO 31
#define NOME_ARQUIVO "..//..//Arquivos//teste%02d.txt"

void gera_arquivo(unsigned int qtd_operacoes, unsigned int num_arquivo, unsigned int tamanho_lista)
{
    char nome_arquivo[TAMANHO_STRING_ARQUIVO];
    FILE *arquivo;

    srand(time(NULL));
    sprintf(nome_arquivo, NOME_ARQUIVO, num_arquivo);
    arquivo = fopen(nome_arquivo, "w");

    fprintf(arquivo, "%d", tamanho_lista);
    fprintf(arquivo, "%s", "\n");
    fprintf(arquivo, "%d", qtd_operacoes);
    fprintf(arquivo, "%s", "\n");

    for (int j = 0; j < qtd_operacoes; j++)
    {
        fprintf(arquivo, "%d", rand() % DOIS);
        fprintf(arquivo, "%s", " ");
        fprintf(arquivo, "%d", rand() % CEM);
    }

    fclose(arquivo);
}

void mostrar_opcoes()
{
    printf("\n1 - Arquivo\n");
    printf("2 - Digitar valores para teste\n");
}

/* Explicando nome das variáveis da função "ler_arquivo"
    N = tamanho do vetor para cursores || NLO // Número de linhas de operações especificadas abaixo
    Op = 0 para inserção e 1 para remoção início
*/
TLista *ler_arquivo(char *nome_arquivo)
{
    unsigned int num_operacoes;
    unsigned int tamanho_lista;
    char path_arquivo[CHAR_MAX];
    FILE *arquivo;
    TLista *lista;

    sprintf(path_arquivo, NOME_ARQUIVO_USUARIO, nome_arquivo);
    arquivo = fopen(path_arquivo, "r");

    fscanf(arquivo, "%i", &tamanho_lista);

    fscanf(arquivo, "%i", &num_operacoes);

    lista = inicializa_lista(tamanho_lista);

    for (int i = 0; i < num_operacoes; i++)
    {
        unsigned int operacao;
        unsigned int qtd_operacao;

        fscanf(arquivo, "%i %i", &operacao, &qtd_operacao);

        for (int j = 0; j < qtd_operacao; j++)
        {
            operacao ? remove_da_lista(lista) : insere_na_lista(lista);
        }
    }

    fclose(arquivo);

    return lista;
}