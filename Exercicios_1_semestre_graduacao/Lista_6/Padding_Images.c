#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p, linha, coluna, /***matriz, **borda,*/ linha2, coluna2,i,j;

    scanf("%d",&coluna);
    scanf("%d",&linha);

  /*matriz = (int **) malloc(linha * sizeof(int*));

  if (matriz==NULL){
      printf("Não foi possível alocar matriz 1");
      exit(1);
  }

  for (i=0;i<linha;i++){
    matriz[i]= (int *) malloc(coluna * sizeof(char));
    if (matriz[i] == NULL) {
         printf ("Não foi possível alocar matriz 2");
         exit(1);
         }
  }*/

  int matriz[linha][coluna];

  for (i=0;i<linha;i++){
      for (j=0;j<coluna;j++){
        scanf("%d",&matriz[i][j]);
      }
  }

  scanf("%d",&p);
  linha2= linha+ (2*p);
  coluna2= coluna+ (2*p);

int borda[linha2][coluna2];

   /*borda = (int **) calloc(linha2,sizeof(int*));

   if (borda==NULL){
      printf("Não foi possível alocar borda 1");
      exit(1);
  }

  for (i=0;i<linha2;i++){
    borda[i]= (int *) calloc(coluna2,sizeof(char));
    if (borda[i] == NULL) {
         printf ("Não foi possível alocar borda 2");
         exit(1);
         }
  }*/

  for (i=0;i<linha2;i++){
      for (j=0;j<coluna2;j++){
        borda[i][j]=0;
      }
  }

  for (i=p;i<(linha+p);i++){
      for (j=p;j<(coluna+p);j++){
        borda[i][j]= matriz[i-p][j-p];
      }
  }
  
  for (i=0;i<linha2;i++){
      for (j=0;j<coluna2;j++){
        printf("%d ",borda[i][j]);
      }
      printf("\n");
  }
  printf("\n");
  for (i=0;i<linha;i++){
      for (j=0;j<coluna;j++){
        printf("%d ",matriz[i][j]);
      }
      printf("\n");
  }

  //free(matriz);
  //free(borda);

    return 0;
}