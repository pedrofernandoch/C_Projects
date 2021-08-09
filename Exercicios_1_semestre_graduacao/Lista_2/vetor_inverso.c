#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[20],i,j;
    
    for (i=0;i<20;i++){
        scanf("%d",&vetor[i]);
    }
    for (j=19;j>=0;j--){
        printf("%d ",vetor[j]);
    }
    return 0;
}
