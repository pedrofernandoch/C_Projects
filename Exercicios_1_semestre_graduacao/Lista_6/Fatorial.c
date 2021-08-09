#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *getConjuntoFatorial(int, int);

int main()
{
    int n0, size, *vetor, i;

    scanf("%d",&n0);
    scanf("%d",&size);
    
    vetor = getConjuntoFatorial(n0, size);

    for(i=0;i<size;i++){
        printf("%d ",vetor[i]);
    }
    
    return 0;
}

int  *getConjuntoFatorial(int n0, int size){

    int fat=1,*vetor,i,aux=n0;
    
    vetor= (int*) malloc(size * sizeof(int));
    assert(vetor);

    while(n0>1){
    fat= fat*n0;
    n0--;
    }

    vetor[0]=fat;
    
    for (i=1;i<size;i++){
      vetor[i]=vetor[i-1]*(aux+1);
      aux++;
    }

    return vetor;
}
