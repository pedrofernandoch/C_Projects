#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    char nome[15];
    int ano;
    float valor;
}carro;

typedef struct {
    int capacidade;
    int *dados;
    int primeiro;
    int ultimo;
    int nItens;
}Fila;

void criarFila(Fila *, int);
void enqueue(Fila *, char[],int,int);
int dequeue(Fila *f);
void mostrarFila(Fila *);
int isEmpty(Fila *);
int isFull(Fila *);

int main(){
    
    int c,i=0;
    char op, nome[15]
    int ano;
    float valor;
    Fila F;

    scanf("%d",&c);
    criarFila(&F, c);
    
    while(i<c){
    scanf(" %c %s %d %f", &op, nome, &ano, &valor);
    if(op=='i'){
      if (isFull(&F)){
          //CHEIA
        }     
        else{
          enqueue(&F,nome,ano,valor);
        }
      }
    if(op=='r'){
      if (isEmpty(&F)){
        //VAZIA
      }
      else{
      v = dequeue(&F);
      }
    }
    i++;
  }
  
  mostrarFila(&F);
  free(F.dados);

 return 0;
}

void criarFila(Fila *f, int c ) {
    f->capacidade = c;
    f->dados = (int*) malloc (f->capacidade * sizeof(float));
    assert(f->dados);
    f->primeiro = 0;
    f->ultimo = -1;
    f->nItens = 0;
}

void enqueue(Fila *f, char nome[], int ano, float valor) {
  carro c;
  c.nome = nome;
  c.ano = ano;
  c.valor = valor;

    if(f->ultimo == f->capacidade-1)
    f->ultimo = -1;
    f->ultimo++;
    f->dados[f->ultimo] = &c;
    f->nItens++;
}

int dequeue(Fila *f ){
    int temp = f->dados[f->primeiro++];
    if(f->primeiro == f->capacidade)
    f->primeiro = 0;
    f->nItens--; 
    
 return temp;
}

void mostrarFila(Fila *f){
    int cont, i;
    for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){
        printf("%s %d %.2f\t ",f->dados[i++].nome,f->daods[i++].ano,f->dados[i++].valor);
        if (i == f->capacidade)
            i=0;
    }
}

int isEmpty(Fila *f){
  return (f->nItens==0);
}

int isFull(Fila *f){
  return (f->nItens == f->capacidade);
}