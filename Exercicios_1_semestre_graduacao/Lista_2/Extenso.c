#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100


int main(){

int n,r,i=0,vet[MAX],count=-1;

scanf("%d",&n);
r=pow(n,2);

while (r >0){
    vet[i]=r%10;
    i++;
    r=r/10;
    count++;
}
for (i=count;i>=0;i--){
    if (vet[i]==0){
        printf("Zero ");
    }
    if (vet[i]==1){
        printf("Um ");
    }
    if (vet[i]==2){
        printf("Dois ");
    }
    if (vet[i]==3){
        printf("Três ");
    }
    if (vet[i]==4){
        printf("Quatro ");
    }
    if (vet[i]==5){
        printf("Cinco ");
    }
    if (vet[i]==6){
        printf("Seis ");
    }
    if (vet[i]==7){
        printf("Sete ");
    }
    if (vet[i]==8){
        printf("Oito ");
    }
    if (vet[i]==9){
        printf("Nove ");
    }
    
}
  
return 0;
}