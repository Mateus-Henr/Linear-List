#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "teste.h"

#define CEM 100
#define DOIS 2
#define NOME_ARQUIVO_USUARIO "..//..//Arquivos//%s.txt"
#define TAMANHO_STRING_ARQUIVO 31
#define NAO_ENCONTRADO "\nO arquivo com nome '%s' não pode ser encontrado.\n"
#define ERRO_FORMATO "\nErro de formato. Tenha certeza que o arquivo segue o formato especificado.\n"
#define NOME_ARQUIVO "..//..//Arquivos//teste%02d.txt"
#define ERRO_CRIAR_ARQUIVO "\nErro ao tentar criar arquivo.\n"
#define NUMERO_INVALIDO "Número inválido. Deve ser entre 0 e 99"

/*
 * Esse método é utilizado para gerar um arquivo customizado pelo usuário. Ele irá receber informações para incluir
 * dentro de um arquivo com nome "testeNN" onde "NN" é um número especificado pelo usuário.
 * Como explicado anteriormente o número tem que seguir o formato "NN", ou seja, só números de 2 algarismos são válidos.
 */
void gera_arquivo(unsigned int qtd_operacoes, unsigned int num_arquivo, unsigned int tamanho_lista)
{
    // Checando se o número informado pelo usuário é válido.
    if (num_arquivo > 99)
    {
        printf(NUMERO_INVALIDO);
        return;
    }

    char nome_arquivo[TAMANHO_STRING_ARQUIVO];
    FILE *arquivo;

    // Criando "seed" para o "rand()" método para tornar a ordem da geração de números aleatória.
    srand(time(NULL));
    sprintf(nome_arquivo, NOME_ARQUIVO, num_arquivo); // Criando caminho para o arquivo.
    arquivo = fopen(nome_arquivo, "w"); // Criando e abrindo o arquivo para colocar as informações.

    // Caso ocorra um erro ao tentar criar o arquivo.
    if (!arquivo)
    {
        printf(ERRO_CRIAR_ARQUIVO);
        return;
    }

    // Escrevendo dados informados pelo usuário.
    fprintf(arquivo, "%d", tamanho_lista);
    fprintf(arquivo, "%s", "\n");
    fprintf(arquivo, "%d", qtd_operacoes);
    fprintf(arquivo, "%s", "\n");

    // Escrevendo escolha de operações (inserção ou remoção) e a quantidade que as mesmas serão utilizadas de forma
    // aleatória.
    for (int j = 0; j < qtd_operacoes; j++)
    {
        fprintf(arquivo, "%d", rand() % DOIS);
        fprintf(arquivo, "%s", " ");
        fprintf(arquivo, "%d", rand() % CEM);
    }

    fclose(arquivo);
}


/*
 * Esse método é usado para descrever as opções que o usuário pode escolher, por meio do console.
 */
void mostrar_opcoes()
{
    printf("\n1 - Arquivo\n");
    printf("2 - Digitar valores para teste\n");
}


/*
 * O método seguinte foi criado com o intuito de ler data de um arquivo em que o nome será passado pelo usuário.
 * Esse método lerá um arquivo seguindo um formato estrito. O mesmo irá criar uma lista onde irá realizar operações
 * sobre. Tem como retorno o ponteiro da lista onde foram realizadas as operações especificadas no arquivo.
*/
TLista *ler_arquivo(char *nome_arquivo)
{
    unsigned int num_operacoes;
    unsigned int tamanho_lista;
    char path_arquivo[CHAR_MAX];
    FILE *arquivo;
    TLista *lista;

    // Criando caminho para o arquivo. É importante lembrar que devido o uso de uma constante para ler o arquivo
    // informado pelo usuário o mesmo deve estar dentro da pasta "Arquivos" deste projeto.
    sprintf(path_arquivo, NOME_ARQUIVO_USUARIO, nome_arquivo);
    arquivo = fopen(path_arquivo, "r"); // Abrindo o arquivo para leitura.

    // Condição para caso não encontre o arquivo especificado.
    if (!arquivo)
    {
        printf(NAO_ENCONTRADO, nome_arquivo);
        return NULL;
    }

    // Lendo o tamanho da lista (1° dado). Lidando com valores inválidos.
    if (!fscanf(arquivo, "%i", &tamanho_lista))
    {
        printf(ERRO_FORMATO);
        return NULL;
    }

    // Lendo o número de operações (inserções e/ou remoções). Lidando com valores inválidos.
    if (!fscanf(arquivo, "%i", &num_operacoes))
    {
        printf(ERRO_FORMATO);
        return NULL;
    }

    lista = inicializa_lista(tamanho_lista);

    // Criando loop para realizar a quantidade de operações da opcção escolhida pelo usuário.
    for (int i = 0; i < num_operacoes; i++)
    {
        unsigned int operacao;
        unsigned int qtd_operacao;

        if (!fscanf(arquivo, "%i %i", &operacao, &qtd_operacao))
        {
            printf(ERRO_FORMATO);
            return NULL;
        }

        for (int j = 0; j < qtd_operacao; j++)
        {
            operacao ? remove_da_lista(lista) : insere_na_lista(lista);
        }
    }

    fclose(arquivo);

    return lista;
}