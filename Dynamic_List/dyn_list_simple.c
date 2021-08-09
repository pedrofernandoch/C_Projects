// Nome: Pedro Fernando Christofoletti dos Santos
// NUSP: 11218560
// Estou aproveitando o codigo feito em aula para realizacao do trabalho

#include <stdlib.h>
#include <stdio.h>
#include <dyn_list_simple.h>

//===============================================================================================================//
//                                                 CREATE                                                        //
//===============================================================================================================//
DYN_LIST_SIMPLE *dyn_list_simple_create(int (*cmp)(void *, void *)) {

	DYN_LIST_SIMPLE *list;
	list = (DYN_LIST_SIMPLE *) calloc(1, sizeof(DYN_LIST_SIMPLE));
	list->cmp = cmp;

	return list;
}

//===============================================================================================================//
//                                                   ADD                                                         //
//===============================================================================================================//
int dyn_list_simple_add(DYN_LIST_SIMPLE *list, int pos, char *pNome, char *uNome, char *cpf, char *tel) {

	if (!list) return INVALID_LIST;

  DYN_LIST_SIMPLE_ELEM **p;

	DYN_LIST_SIMPLE_ELEM *new_elem;
	new_elem = (DYN_LIST_SIMPLE_ELEM *) calloc(1,sizeof(DYN_LIST_SIMPLE_ELEM));
	new_elem->pNome = pNome;
  new_elem->uNome = uNome;
  new_elem->cpf = cpf;
  new_elem->tel = tel;

  if (!list->counter) list->first = list->last = new_elem;
  else{
    p = &list->last;
    (*p)->next = new_elem;
    list->last = new_elem;
  }

  list->counter++;

	return SUCCESS;
}

//===============================================================================================================//
//                                                   DUMP                                                        //
//===============================================================================================================//
int dyn_list_simple_dump(DYN_LIST_SIMPLE *list) {

	if (!list) return INVALID_LIST;
  if (!list->counter) return EMPTY_LIST;

  DYN_LIST_SIMPLE_ELEM *p = list->first;

	while (p){
    printf("Primeiro Nome: %s\n", p->pNome);
    printf("Ultimo Nome: %s\n", p->uNome);
    printf("CPF: %s\n", p->cpf);
    printf("Telefone: %s\n", p->tel);
    printf("-----------------------------\n");
    p = p->next;
  }

  return SUCCESS;

}

//===============================================================================================================//
//                                                   FREE                                                        //
//===============================================================================================================//
int dyn_list_simple_free(DYN_LIST_SIMPLE *list) {

	if (!list) return INVALID_LIST;

	DYN_LIST_SIMPLE_ELEM *p, *aux;
	p = list->first;

	while (p) {
		aux = p->next;
		free(p);
		p = aux;
	}
	free(list);

	return SUCCESS;
}

//===============================================================================================================//
//                                                   REMOVE                                                      //
//===============================================================================================================//
int dyn_list_simple_remove(DYN_LIST_SIMPLE *list, char *cpf) {

	if (!list) return INVALID_LIST;
  if (!list->counter) return EMPTY_LIST;

	DYN_LIST_SIMPLE_ELEM *p, *prev;
  int counter = 0;

	p = list->first;
  prev = NULL;

	while (list->cmp(p->cpf, cpf) && p->next) {
    prev = p;
		p = p->next;
	}

  if (list->cmp(p->cpf, cpf) == 0 && prev) {
    prev->next = p->next;
		if (list->last == p) list->last = prev;
    list->counter--;
	} else if (list->cmp(p->cpf, cpf) == 0 && !prev)list->first = p->next;
  else return CPF_NOT_FOUND;

	return SUCCESS;
}

//===============================================================================================================//
//                                                   SEARCH                                                      //
//===============================================================================================================//
int dyn_list_simple_sequential_search(DYN_LIST_SIMPLE *list, char *cpf) {

	if (!list) return INVALID_LIST;
  if (!list->counter) return EMPTY_LIST;

	DYN_LIST_SIMPLE_ELEM *p = list->first;

	while (p){
    if (list->cmp(p->cpf, cpf) == 0) {
      printf("Primeiro Nome: %s\n", p->pNome);
      printf("Ultimo Nome: %s\n", p->uNome);
      printf("CPF: %s\n", p->cpf);
      printf("Telefone: %s\n", p->tel);
      printf("-----------------------------\n");
      return SUCCESS;
	  }
    p = p->next;
  }

  return CPF_NOT_FOUND;

}

//===============================================================================================================//
//                                                   SIZE                                                        //
//===============================================================================================================//
int dyn_list_simple_size(DYN_LIST_SIMPLE *list) {
	if (!list) return INVALID_LIST;
	return list->counter;
}
