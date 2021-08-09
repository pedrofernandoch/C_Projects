#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int vetor[16],i,j,aux[16];
    
    for (i=0;i<16;i++){
        scanf("%d",&vetor[i]);
        if (vetor[i]<0){
            vetor[i]=0;
        }
        aux[i]=vetor[i];
    }
    for (i=0,j=8;i<8;i++,j++){
        aux[j]=vetor[i];
    }
    for (i=8,j=0;i<16;i++,j++){
        aux[j]=vetor[i];
    }
    for (i=0;i<16;i++){
        printf("%d ",aux[i]);
    }

    return 0;
}
