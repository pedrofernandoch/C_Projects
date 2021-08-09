#include <stdio.h>
#include <stdlib.h>

float funcMaior(float[],int);
float funcMenor(float[],int);

int main(){
    
    int i,n=10;
    float vetor[10];
    
    for (i=0;i<10;i++){
        scanf("%f",&vetor[i]);
    }
    
    printf("%.2f\n",funcMenor(vetor,n));
    printf("%.2f",funcMaior(vetor,n));

    return 0;
}

float funcMaior(float vetor[],int n){
    
    int i;
    float maior=0;
    
     for (i=0;i<n;i++){
        if (vetor[i]>maior){
            maior=vetor[i];
        }
     }
    return maior;
}

float funcMenor(float vetor[], int n){
    
    int i;
    float menor=100000;
    
     for (i=0;i<n;i++){
        if (vetor[i]<menor){
            menor=vetor[i];
        }
     }
    return menor;
}






