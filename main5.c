/*Implemente um programa que carregue para a memória a matriz distâncias gravada
no arquivo do exercício anterior. Implemente uma função que recebe como
parâmetro um vetor de número inteiros contendo as cidades nas quais um viajante
passou e um número inteiro indicando a quantidade de cidades. A função deve calcular
e retornar a distância total percorrida. Por exemplo, se um viajante passou pelas
cidades: 1 → 2 → 3 → 2 → 5 → 1 → 4, a distância total percorrida foi de 80 Km (15 + 10
+ 10 + 28 + 12 + 5). No programa principal, o usuário deve informar as cidades pelas
quais o viajante passou (a quantidade de cidades pode variar entre 1 e 10).*/
/* 1  2  3  4  5
1 00 15 30 05 12
2 15 00 10 17 28
3 30 10 00 03 11
4 05 17 03 00 80
5 12 28 11 80 00*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int Distanciacia(int *cidades,int qtCia,int matriz[5][5]){
	int i,j,k,indice=0,distancia=0;
	for(i=0;i<qtCia;i++){//0 ate a quantidade de cidade
		indice=cidades[i+1];//indece vai ser igual a posicao da proxima cidade
		for(j=0;j<5;j++){//pecorer a matriz 5x5
			for(k=0;k<5;k++){//pecorer a matriz 5x5
				if((cidades[i]-1)==j && k==(indice-1)){//compara as posicoes do vetor com os indices da matriz,que no caso sao as cidades
					distancia=distancia+matriz[j][k];
				}
			}
		}
	}
	return distancia;
}

int main()
{
 FILE *arq;
 int matriz[5][5],i,j,qtcia = 0,total = 0, *cidades;
 arq = fopen("arquivo.txt","rb");//abrind o aquivo do programa 4,deixei o 4 e o 5 n mesma pasta
    if(arq==NULL)//se nao exixte
    {   printf("===================================================================\n");
        printf("Erro no arquivo\n");
        printf("===================================================================\n");
        return 0;
    }
     int resultado =  fread(matriz,sizeof(int),25,arq);//copiando a matriz do outro arquivo em inteiro,porque no exercio 4 estava em binario,ai utilizamos fread
     printf("\t\t==Matriz==\n\n");
     for(i = 0;i < 5;i++){//printando a matriz
        for(j = 0;j < 5;j++)
         if(matriz[i][j] > 9)//formatacao da matriz
          {
          printf(" |%d| \t",matriz[i] [j]);
          }else
          {
          printf(" | %d| \t",matriz[i] [j]);
          }
          printf("\n");

     }
     printf("===================================================================\n");
     printf("Digite quantas cidades passou: ");
     scanf("%d",&qtcia);
     if(qtcia > 10){//no maximo 10 cidades
        printf("Tente novamente(Maximo de cidades 10)\n");
        printf("===================================================================\n");
        return 0;
     }
     cidades=(int*)malloc(qtcia*sizeof(int));
     printf("\tDigite as cidades:\n");
       for(i=0;i<qtcia;i++){
        scanf("%d",&cidades[i]);
      }
      total = Distanciacia(cidades,qtcia,matriz);//procedimento das somas das distancias
      printf("\tTotal da distancia pecorrida:| %d|\n",total);//chamando o total
      printf("===================================================================\n");
      fclose(arq);//fechando o arquivo
return 0;
}
