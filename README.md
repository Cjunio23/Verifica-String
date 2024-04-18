# Verifica-String
1- Implemente um programa que conta quantas vezes uma certa palavra aparece em 
um arquivo texto. O nome do arquivo texto deve ser informado pelo usuário.
Nesse eu utilizei uma matriz de vetores para pegar ao caracter das frases do texto do 
arquivo,verificando os espaços nas strings para forma uma palavra.
2:Implemente um programa que apaga todas as ocorrências de uma certa palavra em 
um arquivo texto. O nome do arquivo texto deve ser informado pelo usuário.
Nesse utilizei uma matriz de vetor também,a mesma logica da 1 pegando os espaços 
e formando uma palvra,fiz um procedimento para limpar o lixo de palavras,e utilizei 2 
arquivos para apagar a palvra,usei a função rename e remove.
3-Implemente um programa que grave um vetor de 100 números inteiros em dois 
arquivos, um no formato texto e o outro binário. Use ftell para descobrir o tamanho dos 
dois arquivos e explique a diferença observada. Faça os seguintes testes: 1. insira no 
vetor apenas números inteiros entre 0 e 9. 2. insira no vetor apenas números inteiros 
entre 1000 e 9999. 3. insira no vetor apenas números inteiros entre 10000 e 99999.
Nesse tinha que abri 2 arquivos e printar o vetor de 100 inteiros,um normal e outro em 
binariol,o nomal utilizei o fprintf e em binário utilizei o fwrite para printar a matriz em 
binário,e utlizei a função ftell para comparar os tamanhos dos arquivos.
4-Implemente um programa que grave a seguinte matriz em um arquivo binário. 
Cada célula da matriz representa a distância entre duas cidades, por exemplo: 
distância entre as cidades 2 e 4 → 17 Km; entre as cidades 4 e 5 → 80 Km. O 
programa deve apenas gravar a matriz em um arquivo binário.Primeiro eu escrevi a 
matriz linha por linha,depois abrir o arquivo e utilizei a função fwrite novamente para 
printar em binário no arquivo.
5-Implemente um programa que carregue para a memória a matriz distâncias 
gravada no arquivo do exercício anterior. Implemente uma função que recebe como 
parâmetro um vetor de número inteiros contendo as cidades nas quais um viajante 
passou e um número inteiro indicando a quantidade de cidades. A função deve 
calcular e retornar a distância total percorrida. Por exemplo, se um viajante passou 
pelas cidades: 1 → 2 → 3 → 2 → 5 → 1 → 4, a distância total percorrida foi de 80 Km 
(15 + 10 + 10 + 28 + 12 + 5). No programa principal, o usuário deve informar as 
cidades pelas quais o viajante passou (a quantidade de cidades pode variar entre 1 e 
10).Neste implementei um procedimento para calcular a soma das distancias pegando 
o índice,e 2 fora para pecorre a matriz 5x5 e os índices são as cidades e cada posiçai 
e marcada,e printei o arquivo do programa anterior que estava em binário para 
inteiros,utilizando fread para printar a matriz.
