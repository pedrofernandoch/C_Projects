#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
   int linhas,colunas,i,j;

   scanf("%d",&linhas);
   scanf("%d",&colunas);

   float matriz[MAX][MAX],matrizTransposta[MAX][MAX];

   for (i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
        scanf("%f",&matriz[i][j]);
        }
    }

    for (j=0;j<colunas;j++){
        for(i=0;i<linhas;i++){
       matrizTransposta[j][i]=matriz[i][j];
        }
    }

    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
        printf("%f ",matriz[i][j]);
        }
    printf("\n");
    }

    printf("\n");

    for(i=0;i<colunas;i++){
        for(j=0;j<linhas;j++){
        printf("%f ",matrizTransposta[i][j]);
        }
    printf("\n");
    }

    return 0;
}
