#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
   int vet[30],i,pares,resto,impares,qtdpares=0,qtdimpares=0;
   
   for (i=0;i<30;i++){
       scanf("%d",&vet[i]);
}
printf("Pares:");
   for (i=0;i<30;i++){
       resto=vet[i]%2;
   if (resto==0){
   printf("%d ",vet[i]);
   qtdpares+= +1;
   }
   }
   printf("\nÍmpares:");
   for (i=0;i<30;i++){
       resto=vet[i]%2;
   if (resto!=0){
   printf("%d ",vet[i]);
   qtdimpares+= +1;
   }
   }
   printf("\nQuantidade de pares: %d\n",qtdpares);
   printf("Quantidade de impares: %d",qtdimpares);
   
    return 0;
}
