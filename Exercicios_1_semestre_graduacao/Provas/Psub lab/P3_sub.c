#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct{ 
int dia; 
int mes; 
int ano; 
char sexo; 
float altura; 
float peso; 
char nome[50]; 
}tBebe;

typedef struct { 
int topo; 
tBebe bb; 
}pilha;

void push(pilha *,int *,tBebe); 
void pop(int *);
void imprimi(pilha *, int);

int main(){
    
  FILE *arq;
  pilha *bebes;
  tBebe bbs; 
  int i=0,topo=6,op,tam=6;

  arq = fopen("dados-bebes.txt","r");
  assert(arq);

  bebes= (pilha *)malloc(6*sizeof(pilha));
  assert(bebes);

  while(fscanf(arq,"%d %d %d %c %f %f %[^\n]s\n",&bebes[i].bb.dia,&bebes[i].bb.mes,&bebes[i].bb.ano,&bebes[i].bb.sexo,&bebes[i].bb.altura,&bebes[i].bb.peso,bebes[i].bb.nome)!=EOF){
    i++;
  }
  fclose(arq);

  scanf("%d",&op);

  while(op!=0){
    if(op==1){
        scanf("%d %d %d %c %f %f %[^\n]s",&bbs.dia,&bbs.mes,&bbs.ano,&bbs.sexo,&bbs.altura,&bbs.peso,bbs.nome);
        bebes = realloc(bebes,(tam+1)*sizeof(pilha));     
        push(&bebes[topo],&topo,bbs);
        tam++;
      }
    if(op==2){
        pop(&topo);
        tam--;
    }
    if(op==3){
      if (topo==0){
        printf("Pilha vazia\n\n");
      }
        imprimi(bebes,tam);
    }
    scanf("%d",&op);
  }

  free(bebes);

 return 0;
}

void push(pilha *bebes, int *topo, tBebe bbs){

  bebes++->bb=bbs;
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

void imprimi(pilha *bebes, int tam){
  
  for (int i=0;i<tam;i++){
    printf("%d %d %d %c %.2f %.2f %s\n",bebes[i].bb.dia,bebes[i].bb.mes,bebes[i].bb.ano,bebes[i].bb.sexo,bebes[i].bb.altura,bebes[i].bb.peso,bebes[i].bb.nome);
  }
}