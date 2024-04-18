/*Implemente um programa que conta quantas vezes uma certa palavra aparece em um
arquivo texto. O nome do arquivo texto deve ser informado pelo usuário.*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
void contarpalavra(char palavra[1000], char pesquisa[20])
{
    char contadorpalavra[50][20], aux[100];
    int i, j = 0, k = 0, contado = 0;
    for(i = 0; i < strlen(palavra); i++) //percoreendo o texto
    {
        if(palavra[i] != ' ' && palavra[i+1] != '\0')//quanoo encontra um espaço e uma palavra formada
        {
            aux[k] = palavra[i];
            k++;//acrescentando em k
        }
        else //Adicionando palavra
        {
            strcpy(contadorpalavra[j],aux);
            j++;//Tem que passar para o proxima palavra (j++) e zerar as letras (k=0)
            k = 0;//zerando os caracter
        }
    }
    for(i = 0; i < j; i++)
    {
        if(strcmp(contadorpalavra[i],pesquisa) == 0)//Comparar as string em cada linha da matriz
            contado++;
    }
    printf("\nPalavra pequisada: %s  \nQuantas vezes ela apareceu: %d\n",pesquisa,contado);//mostradno a palavra e a contidade de vezes
    printf("===================================================================\n");
}
int main()
{
    int contador = 0,Linha=1;
    char palavra[1000], nome[50], pesquisa[20];
    FILE *fp;
    printf("===================================================================\n");
    printf("Digite o nome de arquivo texto: ");
    scanf("%s",&nome);//pegando o nome do arquivo
    printf("Digite a palavra que deseja pesquisa: ");
    scanf("%s",&pesquisa);//palavra pesquisada
    fp = fopen(nome, "r");
    if (!fp)  //Nao achou o texto
    {
        printf("\nNao encontrado o arquivo\n");
        printf("===================================================================\n");
        return 0;
    }
    fgets(palavra, 1000, (FILE*)fp);
    printf("\nTexto do arquivo: %s\n",palavra);
    contarpalavra(palavra,pesquisa);//chamando a funcao
    fclose (fp);
    return 0;
}
