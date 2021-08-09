#include <stdio.h>
#include <stdlib.h>


typedef struct{
  char nome[10];
  int ano;
  float valor;
}carro;

int main(){
  int tam,i,j,count=0;
  scanf("%d",&tam);
  carro var[tam];
  char op;
  for(i=0;i<tam;i++){
    scanf(" %c %s %d %f",&op,var[i].nome,&var[i].ano, &var[i].valor);
    if(op=='i'){
      count++;
    }else if(op=='r'){
      for(j=0;j<count;j++){
        var[j]=var[j+1];
      }
      if(j==count){
        var[j].ano=0;
      }
      count--;
      i--;
      tam--;
    }
  }
  for(i=0;i<tam;i++){
    if(var[i].ano){
     printf("%s %d %.2f\t",var[i].nome,var[i].ano,var[i].valor);
    }
  }


 return 0;
}

