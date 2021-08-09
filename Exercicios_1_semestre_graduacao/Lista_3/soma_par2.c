#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int soma_par(int[],int);

int main(){
    
    int vetor[MAX],n=0,i;
    
    for (i=0;i<MAX;i++){
        scanf("%d",&vetor[i]);
        n++;
        if (vetor[i]==-1){
            break;
        }
    }
    
    printf("%d",soma_par(vetor,n));
   
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