#include <stdio.h>
#include <string.h>
#include "lista.c"


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

int main()
{
    // ---------------------------------------- TESTE LISTA ------------------------------------------------------------

    Lista *lista = inicializa_lista(10);


    for (int i = 0; i < lista->tamanho; i++)
    {
        insere_na_lista(lista);
    }

    printf("\nInformation about the list");
    printf("\nSize of the list: %d", lista->tamanho);
    printf("\nUsed cells: %d", get_numCelOcupados(lista));
    printf("\nFirst position index = %d | Last position index = %d", lista->primeiro, lista->ultimo);

    printf("\n\nDisplaying contents");
    imprime_conteudo(lista);

    // TESTING REMOVAL
    printf("\n\nREMOVENDO\n");

    for (int i = 0; i < lista->tamanho; i++)
    {
        remove_da_lista(lista);
    }

    imprime_celulas(lista);

//    printf("\nINSERTING ELEMENTS");
//    for (int i = 0; i < lista->tamanho; i++)
//    {
//        insere_na_lista(lista);
//    }
//
//    printf("\n\nAFTER INSERTION");
//    imprime_conteudo(lista);

    return 0;
}
