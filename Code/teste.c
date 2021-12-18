#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CEM 100
#define ZERO 0
#define DOIS 2
#define NOME_ARQUIVO "..//..//Arquivos//teste%02d.txt"

void gera_arquivo(unsigned int qtd_operacoes, unsigned int num_arquivo, unsigned int tamanho_lista)
{
    char nome_arquivo[31];
    FILE *file;

    srand(time(NULL));
    sprintf(nome_arquivo, NOME_ARQUIVO, num_arquivo);
    file = fopen(nome_arquivo, "w");

    fprintf(file, "%d", tamanho_lista);
    fprintf(file, "%s", "\n");
    fprintf(file, "%d", qtd_operacoes);
    fprintf(file, "%s", "\n");

    for (int j = 0; j < qtd_operacoes; j++)
    {
        fprintf(file, "%d", rand() % DOIS);
        fprintf(file, "%s", " ");
        fprintf(file, "%d", rand() % CEM);
        fprintf(file, "%s", "\n");
    }

    fclose(file);
}

void mostrar_opcoes()
{
    printf("\n1 - Arquivo\n");
    printf("2 - Digitar valores para teste\n");
}

/* Explicando nome das variáveis da função "lendo_arquivo"
    N = tamanho do vetor para cursores || NLO // Número de linhas de operações especificadas abaixo
    Op = 0 para inserção e 1 para remoção início
*/


//void lendo_arquivo()
//{
//    int N, NLO, Op, i;
//    char nome_arq[CHAR_MAX], local_arq[CHAR_MAX], hold[CHAR_MAX], operacoes[CHAR_MAX];
//    FILE *teste;
//    Lista *lista;
//
//    printf("Nome arquivo: ");
//    scanf("%s", nome_arq);
//    sprintf(local_arq, "..\\Arquivos\\%s", nome_arq);
//    teste = fopen(local_arq, "r");
//
//    //Pegando numero de células do vetor
//    *hold = fgets(1, 6, teste);
//    N = atoi(*hold);
//
//    //inicializando lista com o numero do arquivo de testes
//    lista = inicializa_lista(N);
//
//    //Numero de operaçoes
//    *hold = fgets(2, 3, teste);
//    NLO = 3 + atoi(*hold);
//
//    //
//    for (i = 3; i < NLO + 3; i++)
//    {
//        *operacoes = fgets(i, 5, teste);
//        *hold = strtok(operacoes, " ");
//        Op = atoi(hold[0]);
//        printf("%d", Op);
//    }
//}