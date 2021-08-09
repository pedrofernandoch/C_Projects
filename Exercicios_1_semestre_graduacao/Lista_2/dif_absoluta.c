#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i,maiorDif=0,dif;
   int vetor[10];

    for (i=0;i<10;i++){
        scanf("%d",&vetor[i]);
    }
    for (i=0;i<9;i++){
        if (vetor[i]>=vetor[i+1]){
            dif=vetor[i]-vetor[i+1];
        }
        else {
            dif=vetor[i+1]-vetor[i];
        }
        if(dif>maiorDif){
            maiorDif=dif;
        }
        
    }

    printf("%d",maiorDif);
    
    return 0;
}