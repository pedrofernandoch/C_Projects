#include <stdio.h>
#include <stdlib.h>

int soma_divisores(int);

int main() {

  int n1,n2,i,aux;

  scanf("%d",&n1);
  scanf("%d",&n2);

  for(i=n1;i<=n2;i++){
      aux=soma_divisores(i); 
      if((aux<=n2)&&(n1<=aux)&&(aux!=i)&&(aux>i)){
          if((soma_divisores(aux))==i){
              printf("%d %d\n",i,aux); 
          }  
      }
      aux=0;
  }

  return 0;
}

int soma_divisores(int num){

  int i,soma=0;
  
  for(i=1;i<=(num/2);i++){
      if((num%i)==0){
          soma+=i;
      }
  }

return soma;
}