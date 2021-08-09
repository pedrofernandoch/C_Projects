#include <stdio.h>
#include <stdlib.h>
#define LINHA 4
#define COLUNA 5
#define MAX 5

int main(){

int matriz[LINHA][COLUNA], vetor[MAX], i,j;

for (i=0;i<LINHA;i++){
    for (j=0;j<COLUNA;j++){
        scanf("%d ",&matriz[i][j]);
    }
}
for (j=0;j<COLUNA;j++){
    vetor[j]=0;
    for (i=0;i<LINHA;i++){
        vetor[j]=vetor[j]+matriz[i][j];
    }
}
for (i=0;i<MAX;i++){
printf("%d ",vetor[i]);
}

return 0;

}
