#include <stdio.h>
#include <stdlib.h>

void ler_matriz(int [][3]);
void mistura(int, int, int, int [][3], int[][3]);
void imprimir_matriz(int [][3], int[][3]);

int main(void) {

  int matriz[6][3],matriz_cor[6][3],p1,p2,p3;
  int i,j;

  scanf("%d",&p1);
  scanf("%d",&p2);
  scanf("%d",&p3);

  ler_matriz(matriz);

  for (i=0;i<6;i++){
    for (j=0;j<3;j++){
      matriz_cor[i][j]=matriz[i][j];
    }
  }

  mistura(p1,p2,p3,matriz,matriz_cor);
  imprimir_matriz(matriz,matriz_cor);
  
  return 0;
}

void ler_matriz(int matriz[][3]){

  int i,j;

  for (i=0;i<6;i++){
    for (j=0;j<3;j++){
      scanf("%d",&matriz[i][j]);
    }
  }

}

void mistura(int p1, int p2, int p3, int matriz[][3], int matriz_cor[][3]){

  int j;

  for (j=0;j<3;j++){
  matriz_cor[p3][j]=matriz[p1][j]/2 + matriz[p2][j]/2 + matriz_cor[p3][j];
  }

}

void imprimir_matriz(int matriz[][3], int matriz_cor[][3]){

  int i,j=0;

  printf("Start:\n");
  for (i=0;i<6;i++){
      printf("Color(%d): [\t%d\t%d\t%d\t]\n",i,matriz[i][j],matriz[i][j+1],matriz[i][j+2]);
  }
  j=0;
  printf("\n");
  printf("Result:\n");
  for (i=0;i<6;i++){
      printf("Color(%d): [\t%d\t%d\t%d\t]\n",i,matriz_cor[i][j],matriz_cor[i][j+1],matriz_cor[i][j+2]);
  }

}
  
