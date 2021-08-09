#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <stdlib.h>

int *criaVetor(int);
void imprimiVetor(int[],int);
int maxVetor(int *,int);

int main()
{
    int tam;
    int *v;
    
    scanf("%d",&tam);
    
    srand(time(NULL));
    
    v = criaVetor(tam);
    
    imprimiVetor(v,tam);
    
    return 0;
}

int *criaVetor(int tam){
    
    int *vet,i;
    
    vet= (int*) calloc(tam,sizeof(int));
    assert(vet);
    
    for (i=0; i<tam; i++){
        vet[i]=10+rand()%21;
    }
    
    return vet;
}

void imprimiVetor(int vet[],int tam){
    
    int i;
    
    printf("\n[");
    
    for (i=0; i<tam; i++){
        printf(" %d",vet[i]);
    }
    printf(" ]");
}

int maxVetor(int *vet,int tam){
    
    int aux;
    
    if (n==1){
        return vet[0];
    }
    aux=maxVetor(vet+1,n-1);
    if (aux>vet[0]) return aux;
    return vet[0];
    
    
}