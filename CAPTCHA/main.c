/*
ABORDAGEM USADA NO ALGORITMO:
  Nota-se que a somatoria dos elementos das colunas de um numero na imagem resulta em uma sequencia,
  cuja frequencia dos numeros resultantes da somatoria identifica unicamente a maioria dos algarismos do captcha.
  Essenialmente o metodo se baseia nessa logica com rotinas para eliminar a influencia do ruido e
  diferenciar numeros cuja somatoria dos elementos das colunas seja igual, a saber: 2 e 5; 6 e 9.
  Cada passo do metodo sera comentado inline dentro do codigo.
*/
#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

int main(int argc,char*argv[]){

 FILE *file;
 char nomeArq[30],tipo[2];
 int linha, coluna, escala;
 int i, j, k, l;
 int *identificadores_de_numeros, *coluna_final_dos_numeros,**vet,**freq_identificadores_de_numeros, **identificadores_de_numerosSeparados;
 int maior=0, soma=0;

 scanf("%s",nomeArq);

// #LENDO ARQUIVO //
 file = fopen(nomeArq, "r");
 fscanf(file,"%s\n %d %d\n %d\n",tipo,&coluna,&linha,&escala);
 // Alocando vetor para receber imagem //
 vet = (int**)malloc(linha * sizeof(int*));
 for (i=0;i<linha;i++){
   vet[i]= (int*)malloc(coluna *sizeof(int));
 }
 // Vetor recebendo imagem //
 while(!feof(file)){
   for (i=0;i<linha;i++){
      for(j=0;j<coluna;j++){
        fscanf(file,"%d",&vet[i][j]);
      }
    }
 }
// #FIM DA LEITURA//

// Alocando vetores para aplicacao do metodo //
identificadores_de_numeros = (int*)malloc(coluna * sizeof(int));
coluna_final_dos_numeros = (int*)malloc(100 * sizeof(int));
identificadores_de_numerosSeparados = (int**) calloc(100,sizeof(int*));
for (i=0;i<100;i++){
   identificadores_de_numerosSeparados[i]= (int*)calloc(1000, sizeof(int));
}

// Tornando imagem branco e preto caso eseteja em tons de cinza//
homogenizar(vet, linha, coluna);
// Eliminando ruidos com uma tolerancia arbitrada em grupos de 3 pixels //
eliminaRuido(vet,linha,coluna);

// Recebendo soma dos valores de cada coluna //
for (i=0;i<coluna;i++){
  for(j=0;j<linha;j++){
    soma+= + vet[j][i];
  }
  identificadores_de_numeros[i]=soma;
  soma=0;
}
// Dividindo por 10 e arredondando para o inteiro mais proximo para transformar em identificadores homogenios de numeros //
for (i=0;i<coluna;i++){
  identificadores_de_numeros[i] = (identificadores_de_numeros[i] + 5) /10;
}

// Colocando os identificadores_de_numeros de cada numero em uma linha da matriz e armazenando a coluna final de cada numero//
j=0;
k=0;
for(i=0;i<coluna;i++){
    if (identificadores_de_numeros[i]!=0){
        identificadores_de_numerosSeparados[k][j] = identificadores_de_numeros[i];
        j++;
        if(identificadores_de_numeros[i+1]==0){
            coluna_final_dos_numeros[k]=i;
            k++;
            if ((j-1)>maior){
              maior=(j-1);
            }
            j=0;
        }
    }
}

// Alocando vetor de frequencia para aplicacao do metodo //
freq_identificadores_de_numeros = (int**)malloc(k * sizeof(int*));
 for (i=0;i<k;i++){
   freq_identificadores_de_numeros[i]= (int*)malloc(5 *sizeof(int));
 }

// Recebendo frequencia dos identificadores_de_numeros //
frequencia_dos_identificadores_de_numeros(k,maior,identificadores_de_numerosSeparados,freq_identificadores_de_numeros);

// Identificando os numeros da imagem por comparacao com os identificadores_de_numeros das Mascaras //
for (i=0;i<k;i++){
  j = descobre_numero(freq_identificadores_de_numeros[i][0],freq_identificadores_de_numeros[i][1],freq_identificadores_de_numeros[i][2],freq_identificadores_de_numeros[i][3],freq_identificadores_de_numeros[i][4],i,linha,coluna_final_dos_numeros[i],identificadores_de_numerosSeparados,vet);
  if (j>=0)
  printf("%d",j);
}

free(vet);
free(identificadores_de_numeros);
free(identificadores_de_numerosSeparados);
free(freq_identificadores_de_numeros);
fclose(file);

 return 0;
}
