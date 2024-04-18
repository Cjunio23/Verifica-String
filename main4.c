/*Implemente um programa que grave a seguinte matriz em um arquivo
binario.
  1  2  3  4  5
1 00 15 30 05 12
2 15 00 10 17 28
3 30 10 00 03 11
4 05 17 03 00 80
5 12 28 11 80 00
Cada celula da matriz representa a distancia entre duas cidades, por exemplo:
distancia entre as cidades 2 e 4 → 17 Km; entre as cidades 4 e 5 → 80 Km. O
programa deve apenas gravar a matriz em um arquivo binario.*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int main()
{
    FILE *arq;//passando o arquivo
    int matriz[5][5];
    matriz[0][0] = 0;  matriz[0][1] = 15; matriz[0][2] = 30; matriz[0][3] = 5;  matriz[0][4] = 12;//Escrevendo a matriz linha por linha e coluna por coluna
    matriz[1][0] = 15; matriz[1][1] = 0;  matriz[1][2] = 10; matriz[1][3] = 17; matriz[1][4] = 28;
    matriz[2][0] = 30; matriz[2][1] = 10; matriz[2][2] = 0;  matriz[2][3] = 3;  matriz[2][4] = 11;
    matriz[3][0] = 5;  matriz[3][1] = 17; matriz[3][2] = 3;  matriz[3][3] = 0;  matriz[3][4] = 80;
    matriz[4][0] = 12; matriz[4][1] = 28; matriz[4][2] = 11; matriz[4][3] = 80; matriz[4][4] = 0;
    arq = fopen("arquivo.txt","wb");//abrind o aquivo por isso wb
    if(arq==NULL)//se nao exixte
    {   printf("===================================================================\n");
        printf("Erro no arquivo\n");
        printf("===================================================================\n");
        return 0;
    }
       printf("===================================================================\n");
       printf("\n\t===Matriz copiada para binario===");//pritando falando que a matriz deu certo
       fwrite(matriz,sizeof(int),25,arq);//para gravar a matriz em binario,utilizamos essa funcao ja fwrite,e colocamos o tamanho da matriz
       fclose (arq);//fechando o arquivo
       printf("\nPressione enter para abrir o arquivo...\n\n");
       printf("===================================================================\n");
       getchar();
       system("call arquivo.txt");//abrindo o arquivo
return 0;
}

