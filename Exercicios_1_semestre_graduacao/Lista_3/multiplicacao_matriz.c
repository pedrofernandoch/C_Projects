#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 20

void ler_matriz (int[][MAX],int,int);
void multiplica_matriz (int matrizA[][MAX], int matrizB[][MAX], int matrizResultante[][MAX], int linhaA, int colunaA, int colunaB);
void printa_matriz  (int[][MAX],int,int);

int main (){
  
  int linhaA,linhaB,colunaA,colunaB;
  int matrizA[MAX][MAX], matrizB[MAX][MAX], matrizResultante[MAX][MAX];

  scanf ("%d", &linhaA);
  scanf ("%d", &colunaA);

  ler_matriz (matrizA,linhaA,colunaA);

  scanf ("%d", &linhaB);
  scanf ("%d", &colunaB);

  ler_matriz(matrizB,linhaB,colunaB);

  multiplica_matriz(matrizA, matrizB, matrizResultante, linhaA, colunaA, colunaB);
    
  printa_matriz(matrizResultante,linhaA,colunaB);

  return 0;
}

void ler_matriz (int matriz[][MAX], int linha, int coluna){

  int i, j;

    for (i=0;i<linha;i++){
        for (j=0;j<coluna;j++){
	        scanf("%d",&matriz[i][j]);
	    }
    }
}

void multiplica_matriz (int matrizA[][MAX], int matrizB[][MAX], int matrizResultante[][MAX], int linhaA, int colunaA, int colunaB){
    
    int i,j,k;
    
    for (i=0;i<linhaA;i++){
      for (j=0;j<colunaB;j++){
         matrizResultante[i][j]=0;
            for (k=0;k<colunaA;k++){
            matrizResultante[i][j]= matrizA[i][k]*matrizB[k][j] + matrizResultante[i][j];
            
            }
        } 
    }
}

void printa_matriz (int matrizResultante[][MAX], int linhaA, int colunaA){
    
    int i,j;
    for (i=0;i<linhaA;i++){
        for (j=0;j<(colunaA);j++){
	        printf("%d ",matrizResultante[i][j]);
	    }
	    printf("\n");
    }
}