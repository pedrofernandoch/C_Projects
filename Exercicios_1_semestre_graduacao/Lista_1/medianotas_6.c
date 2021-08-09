#include <stdio.h>
#include <stdlib.h>

int main()
{
    float media, soma;
    int n, i;
    float vetor[100];
    
    soma=0; 
    
scanf("%d",&n);
  for (i = 0; i < n; i++){
      scanf("%f",&vetor[i]);
  }
  for ( i = 0; i < n; i++ ){
      soma = soma + vetor[i];
  }
  
  media=soma/n;
  
  if (media>=90){
  printf("media: %.2f (Excelente)", media);
  }
  if (media<=89&&media>80){
  printf("media: %.2f (Muito Bom)", media);
  }
  if (media<=79&&media>=70){
  printf("media: %.2f (Bom)", media);
  }
  if (media<=69&&media>=50){
  printf("media: %.2f (Regular)", media);
  }
  if (media<=49){
  printf("media: %.2f (Reprobado)", media);
  }
    return 0;
}