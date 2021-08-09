#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct{
  char nome[50];
  char autor[100];
  int paginas;
} pilha;

void empilhar(pilha *,int *); 
void desempilhar(pilha *,int *);
void mostrar(pilha *);

int main() {

  int tam,op,topo=0;
  pilha *livros;

  scanf("%d",&tam);

  livros= (pilha *) malloc(tam * sizeof(pilha));
  assert(livros);

  scanf("%d" , &op);
  while(op!=0){
    if(op==1){     
        empilhar(&livros[topo],&topo);
        if (tam<topo){
          printf("Pilha cheia\n\n");
          topo--;
        }
      }
    if(op==2){
      if (topo==0){
          printf("Pilha vazia\n\n");
      }
      else{
        desempilhar(&livros[topo-1],&topo);
      }
    }
    if(op==3){
      if (topo==0){
        printf("Pilha vazia\n\n");
      }
      else{
        mostrar(&livros[topo-1]);
      }
    }
    scanf("%d" , &op);
  }

  free(livros);
  
  return 0;
}
void empilhar(pilha *livros, int *topo){

  scanf(" %s",livros->nome);
  scanf(" %s",livros->autor);
  scanf("%d",&livros->paginas);
  *topo= *topo + 1;
}
void desempilhar (pilha *livros, int *topo){

  printf("Nome: %s\n",livros->nome);
  printf("Autor: %s\n",livros->autor);
  printf("Nro Paginas: %d\n\n",livros->paginas);
  *topo= *topo - 1;
}
void mostrar (pilha *livros){
  printf("Nome: %s\n",livros->nome);
  printf("Autor: %s\n",livros->autor);
  printf("Nro Paginas: %d\n\n",livros->paginas);
}
