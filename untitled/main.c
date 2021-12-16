#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char nome[CHAR_MAX],arquivo[CHAR_MAX], insercoes[CHAR_MAX];
    int N_insercoes;
    FILE *teste;
    printf("Nome do arquivo: ");
    scanf("%s",nome);
    printf("\n%s", nome);
    strcat(strcpy(arquivo, nome), ".txt");
    printf("\n%s",arquivo);
    teste = fopen(arquivo,"w");
    printf("\nNumero de celulas: ");
    scanf("%s",insercoes);

    N_insercoes=atoi(insercoes);
    fclose(teste);
    return 0;
}
