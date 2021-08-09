#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
   int colunas,linhas,i,j;
   float multi=0;
   
   scanf("%d",&linhas);
   scanf("%d",&colunas);
   
   int matriz[linhas][colunas],vetor[colunas];
   float vetor2[linhas];
   
   for (i=0;i<linhas;i++){
       for (j=0;j<colunas;j++){
           scanf("%d",&matriz[i][j]);
       }
   }
   for (i=0;i<(colunas);i++){
       scanf("\n%d",&vetor[i]);
   }
  
   for (i=0;i<linhas;i++){
       multi=0;
       for (j=0;j<colunas;j++){
           multi = multi + (float)matriz[i][j]*vetor[j];
       }
       vetor2[i]=multi;
   }
   for (i=0;i<linhas;i++){
       printf("%f\n",vetor2[i]);
   }
   
    return 0;
}
