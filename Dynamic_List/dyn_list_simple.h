// Nome: Pedro Fernando Christofoletti dos Santos
// NUSP: 11218560  
// Estou aproveitando o codigo feito em aula para realizacao do trabalho

#ifndef _DYN_LIST_SIMPLE_
#define _DYN_LIST_SIMPLE_

#define SUCCESS 	0
#define INVALID_LIST 	-1
#define EMPTY_LIST 	-2
#define CPF_NOT_FOUND	-3

// Elemento da lista
struct dyn_list_simple_elem {
  char *pNome;
  char *uNome;
  char *cpf;
  char *tel;
	struct dyn_list_simple_elem* next;
};
typedef struct dyn_list_simple_elem DYN_LIST_SIMPLE_ELEM;

// Descritor da lista
struct dyn_list_simple {
	DYN_LIST_SIMPLE_ELEM *first;
	DYN_LIST_SIMPLE_ELEM *last;
	int (*cmp)(void *, void *);
	int counter;
};
typedef struct dyn_list_simple DYN_LIST_SIMPLE;

// Funcoes
DYN_LIST_SIMPLE *dyn_list_simple_create(int (*)(void *, void *));
int dyn_list_simple_add(DYN_LIST_SIMPLE *, int, char [], char [], char [], char []);
int dyn_list_simple_dump(DYN_LIST_SIMPLE *);
int dyn_list_simple_free(DYN_LIST_SIMPLE *);
int dyn_list_simple_remove(DYN_LIST_SIMPLE *, char *);
int dyn_list_simple_sequential_search(DYN_LIST_SIMPLE *, char *);
int dyn_list_simple_size(DYN_LIST_SIMPLE *);

#endif

