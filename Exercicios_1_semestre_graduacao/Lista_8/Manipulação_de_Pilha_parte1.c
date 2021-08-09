#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct{
  int elemento;
} pilha;

void push(pilha *,int *,int); 
void pop(int *);

int main() {

  int tam,topo=0,i=0,valor,aux=0;
  char op;
  pilha *num;

  scanf("%d",&tam);

  num= (pilha *) malloc(tam * sizeof(pilha));
  assert(num);

  while(i<tam){
    scanf(" %c %d", &op, &valor);
    if(op=='i'){     
        push(&num[topo],&topo,valor);
      }
    if(op=='r'){
        pop(&topo);
        aux++;
    }
    i++;
  }

  tam=tam - (2*aux);
  if (tam==0){
    tam++;
  }

  for (i=(tam-1);i>=0;i--){
    printf("%d ",num[i].elemento);
  }

  free(num);
  
  return 0;
}
void push(pilha *num, int *topo, int valor){

  num->elemento=valor;
  *topo= *topo + 1;
}
void pop (int *topo){

  if (*topo>1){
  *topo= *topo - 1;
  }
  else{
    *topo = 0;
  }
}