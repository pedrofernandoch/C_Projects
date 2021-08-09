#include <stdio.h>
#include <stdlib.h>

int soma_par(int[],int);

int main()
{
    
    int vetor[4],i,n;
    n=4;
    
    for (i=0;i<n;i++){
        scanf("%d",&vetor[i]);
    }
    printf("A soma dos numeros pares = %d\n",soma_par(vetor,n));
    

    return 0;
}

int soma_par(int vetor[], int n){
    
    int resto,i,soma=0;
    
    for (i=0;i<n;i++){
        resto=vetor[i]%2;
        if (resto==0){
            soma+=vetor[i];
        }
    }
    return soma;
}