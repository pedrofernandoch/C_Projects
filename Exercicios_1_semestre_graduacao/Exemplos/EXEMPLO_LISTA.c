#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no{
    int value;
    struct no *prox;
};

typedef struct no celula;

void insere_no (celula *, int);
void imprimi(celula *);

int main(){
  
  int i;
  celula head;
  //INICIAR LISTA

  head.prox=NULL;

  for (i=0;i<5;i++){
  insere_no(&head,i+1);
  }

  imprimi(head.prox);

 return 0;
 
}

void insere_no (celula *plist, int value){

  celula *paux;

  paux= (celula *) malloc (sizeof(celula));
  paux->value = value;
  paux->prox = plist-> prox;
  plist-> prox = paux;

}

void imprimi(celula *plist){

  if (plist->prox==NULL){
    printf("%d Tchau!",plist->value);
  }
  else{
    printf("%d ",plist->value);
    imprimi(plist->prox);
  }
}