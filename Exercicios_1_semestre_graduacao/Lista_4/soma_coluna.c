#include <stdio.h>
#include <stdlib.h>

int main(){

int matriz[4][5], vetor[5], i,j;

for (i=0;i<4;i++){
    for (j=0;j<5;j++){
        scanf("%d",&matriz[i][j]);
    }
}
for (j=0;j<5;j++){
    vetor[j]=0;
    for (i=0;i<4;i++){
        vetor[j]=vetor[j]+matriz[i][j];
    }
}
for (i=0;i<5;i++){
printf("%d ",vetor[i]);
}

return 0;

}
