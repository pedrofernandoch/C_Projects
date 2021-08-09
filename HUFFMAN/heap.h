//Nome: Pedro Fernando Christofoletti dos Santos
//NUSP: 11218560

#ifndef HEAP_H
#define HEAP_H

#define TAM1 200

struct node {
  int simbolo, freq;
  struct node *filho_esq, *filho_dir, *pai;
};
typedef struct node NODE;

struct heap {
	NODE *vetor[TAM1];
	int fim;
};
typedef struct heap HEAP;

HEAP *criarHeap();
int cheia(HEAP *);
int vazia(HEAP *);
int enfileirar(HEAP *, NODE *);
NODE *desenfileirar(HEAP *);
int tamanho(HEAP *);

#endif
