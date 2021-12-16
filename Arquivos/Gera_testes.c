#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main() {
    char nome[CHAR_MAX],arquivo[CHAR_MAX], insercoes[CHAR_MAX], arquivo2[CHAR_MAX],binario_c[CHAR_MAX],calculo_c[CHAR_MAX];
    int N_insercoes,i,binario,calculos;
    FILE *teste;
    
    //leitra do nome do arquivo a ser criado
    srand(time(NULL));
    printf("Nome do arquivo: ");
    scanf("%s",nome);
    strcat(strcpy(arquivo, nome), ".txt");
    strcat(strcpy(arquivo2, "..\\"), arquivo);
    teste = fopen(arquivo2,"w");

    //leitura do numero de celulas a serem criadas
    printf("\nNumero de celulas: ");
    scanf("%s",insercoes);
    fprintf(teste,insercoes);
    fprintf(teste,"\n");

    //geração aleatoria donumero de operações a serem feitas
    N_insercoes=rand() % 100;
    sprintf(insercoes,"%d",N_insercoes);
    fprintf(teste,insercoes);
    fprintf(teste,"\n");
    N_insercoes=atoi(insercoes);

    //Loop para criação das operações a serem feitas
    for(i=0;i<N_insercoes;i++ ){
        binario=rand() % 2;
        calculos=rand() % 100;
        sprintf(binario_c,"%d",binario);
        sprintf(calculo_c,"%d",calculos);
        fprintf(teste, binario_c);
        fprintf(teste, " ");
        fprintf(teste,calculo_c);
        fprintf(teste,"\n");
    }

    fclose(teste);
    return 0;
}
