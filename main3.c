/*Implemente um programa que grave um vetor de 100 números inteiros
em dois arquivos, um no formato texto e o outro binário. Use ftell para descobrir o
tamanho dos dois arquivos e explique a diferença observada. Faça os seguintes testes:
1. insira no vetor apenas números inteiros entre 0 e 9.
2. insira no vetor apenas números inteiros entre 1000 e 9999.
3. insira no vetor apenas números inteiros entre 10000 e 99999.*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define maximo 100//maximo de 100 numeros inteiros
int main()
{
    FILE *arq;//abrindo o arquivo 1
    FILE *arq2;//abrindo o arquivo 2
    int vetor[maximo], i, result, calculaFtell = 0;//vetor de tamnho 100
    for(i=0; i < maximo ; i++)//pecorrer o vetor
    {
        vetor[i]=rand()%9;//teste que o professor pediu
    }
    arq = fopen("arquivoNormal.txt","w");//abrindo o primeiro aquivo
    if(arq==NULL)//se nao exixte
    {   printf("===================================================================\n");
        printf("Erro no arquivo\n");
        printf("===================================================================\n");
        return 0;
    }
    arq2= fopen("arquivoBinario.txt","wb");//abrind o sgundo aquivo com wb pois e numero binario
    if(arq2==NULL)//se nao exixte
    {   printf("===================================================================\n");
        printf("Erro no arquivo\n");
        printf("===================================================================\n");
    }
    for(i=0; i<maximo; i++)//pecorrendo o e vetor
    {
        fprintf(arq,"%d ",vetor[i]);//printando no arquivo 1
    }
        result = fwrite(vetor,sizeof(int),100,arq2);//printando em binario no arquivo 2/frwrite e o procedimento usado,e sizeof tambem

    if(result==100)//condiçao para mostrar
    {   printf("===================================================================\n");
        printf("***Guardou no arquivo***\n");
    }
    calculaFtell = ftell(arq);//Funçao que o professor pediu,fteel fala o tamanho do arquivo,e estou compara o tamnho do arquivo 1 com o 2
    printf("Valor do primeiro arquivo: %d\n",calculaFtell);//tamnho do primeiro arquiv0
    calculaFtell = ftell(arq2);//tamanho no segundo arquivo
    printf("Valor do segundo aquivo: %d\n",calculaFtell);//tamnho do segundo arquivo
    printf("===================================================================\n");
    fclose (arq);
    fclose (arq2);
    printf("\tPrimeiro arquivo normal\n\tSegundo arquivo binario");
    printf("\nPressione enter para abrir o arquivo: ");
    getchar();
    //system("cls");//limpar a tela
    system("call arquivoNormal.txt");//abrir os arquivos assim que pressionar enter
    system("call arquivoBinario.txt");//abrir os arquivos assim que pressionar enter
return 0;
}
