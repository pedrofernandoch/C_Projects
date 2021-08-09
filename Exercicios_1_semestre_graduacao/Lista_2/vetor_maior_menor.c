#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int *vetor,n,menor=2147483647,maior= -2147483648,i;

    scanf("%d",&n);
    vetor = (int *) malloc(n * sizeof(int));

    for (i=0;i<n;i++){
    scanf("%d",&vetor[i]);
    if (vetor[i]>maior){
    maior=vetor[i];
    }
    if (vetor[i]<menor){
    menor=vetor[i];
    }
    }

    printf("%d %d",maior,menor);

    return 0;
}
