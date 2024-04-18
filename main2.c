/*Implemente um programa que apaga todas as ocorrências de uma certa palavra em um
arquivo texto. O nome do arquivo texto deve ser informado pelo usuário.*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
void limpaPalavra(char palavra[],int tamanho){
	int i;
	for(i=0;i<tamanho;i++){//Para limpar a variavel,e pegar o resto
		palavra[i]=' ';
	}
	palavra[tamanho]=' ';
}

int excluir(char palavra[1000], char pesquisa[20], FILE *arq, char nome[20],FILE *arq2)//procedimento para excluir
{
    char contadorpalavra[50][20], aux[100];
    int i, j = 0, k = 0, encontrado = 0, renomeio;

    arq2 = fopen("arquivoAUX.txt", "a");//criando outro arquivo para mannda as palavras para ele,e apagar o outro
    for(i = 0; i < strlen(palavra); i++){//pecorrendo a string
      if(palavra[i] != ' ' && palavra[i+1] != '\0')//Verificando os espacos
       {
        aux[k] = palavra[i];
        k++;//acresentando em k
        }else{//Adicionando palavra
        if(palavra[i+1]=='\0'){
        	aux[k]=palavra[i];
        	k++;//acresentando em k
		}
		aux[k]='\0';
         strcpy(contadorpalavra[j],aux);
         limpaPalavra(aux,k);//chmando o procedimento para limpar as variveis,para nao pegar lixo
         j++;//Tem que passar para o proxima palavra (j++) e zerar as letras (k=0)
         k = 0;
        }
      }
    for(i = 0;i< j;i++){//percorreno a palavra ate o final da outra,para pegar ela inteira
       if(strcmp(contadorpalavra[i],pesquisa) != 0){//Comparar as string em cada linha da matriz
          fprintf(arq2,"%s ",contadorpalavra[i]);//printando no segundo arquivo
      }
	}
	fprintf(arq2,"\n");//printando o arquivo 2
    fclose(arq2);//fechando o arquivo 2
return encontrado;
}

int main(){
    int contador = 0,Linha=1,encontrada=0;
    char palavra[1000], nome[50], pesquisa[20];
    FILE *fp,*arq2;
    printf("===================================================================\n");
    printf("Digite o nome de arquivo texto: ");
    gets(nome);//Pegar o nome do arquivo que deseja selecionar
    fp = fopen(nome, "r");
    if (!fp)  //Nao achou o texto
    {
        printf("Nao encontrado o arquivo\n");
        printf("===================================================================\n");
        return 0;
    }
    printf("Digite a palavra que deseja excluir: ");
    gets(pesquisa);//palavra que deseja excluir
    while(fgets(palavra, 1000, fp)!=NULL){
    	  encontrada = excluir(palavra,pesquisa,fp,nome,arq2);//chamndo o procedimento
	}
    printf("Palavra excluida do arquivo\n");
    printf("===================================================================\n");
	fclose(fp);//para funciona o remove e rename o arquivo tem que estar fechado
	remove(nome);//removendo o arquivo que foi aberto
	rename("arquivoAUX.txt",nome);//renomenado comm o nome do outro arquivo

    return 0;
}
