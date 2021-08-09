#include <stdio.h>
#include <stdlib.h>

int main()
{
    float media, soma;
    int min, max, n, i;
    float vetor[100];
    
    soma=0; 
    max=0;
    min=1000000000;
    
scanf("%d",&n);
  for (i = 0; i < n; i++){
      scanf("%f",&vetor[i]);
  }
  for ( i = 0; i < n; i++ ){
      soma = soma + vetor[i];
  }
  
  media=soma/n;
  
   for(i = 0; i < n; i++){
            if(vetor[i]>max){
                max=vetor[i];
            }
   }
    for(i = 0; i < n; i++){
            if(vetor[i]<min){
                min=vetor[i];
            }
    }     
    
  printf("minimo: %d \n", min);
  printf("maximo: %d \n", max);
  printf("media: %.2f", media);
    return 0;
}