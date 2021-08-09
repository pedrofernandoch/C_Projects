// Nome: Pedro Fernando Christofoletti dos Santos
// NUSP: 11218560

#ifndef _ANAGRAMA_H_
#define _ANAGRAMA_H_

#define SUCCESS 0;
#define INVALID_WORDS -1;

typedef struct{
  char *palavra,**anagrama;
  unsigned long long int id;
  int qtd;
}PALAVRA;

int calcula_moda(PALAVRA *, int);
int print_palavras(PALAVRA *, int, int);
int free_palavras(PALAVRA *, int);

#endif
