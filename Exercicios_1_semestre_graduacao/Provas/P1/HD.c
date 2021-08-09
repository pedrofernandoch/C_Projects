#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(){

  int Narq,bloco,vetor[MAX],i,Nblocos,soma=0,resto;

  scanf("%d",&Narq);
  scanf("%d",&bloco);

  for (i=0;i<Narq;i++){
    scanf("%d",&vetor[i]);
    soma+=vetor[i];
  }

  Nblocos=soma/bloco;
  resto=soma%bloco;
  if (resto>0){
    Nblocos+=1;
  }

  printf("Blocos ocupados: %d",Nblocos);
  return 0;
}

