// Nome: Pedro Fernando Christofoletti dos Santos
// NUSP: 11218560
// Estou aproveitando o codigo feito em aula para realizacao do trabalho

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dyn_list_simple.h>

int cmp(char *i, char *j) {
	return strcmp(i, j);
}

int main(){

  DYN_LIST_SIMPLE *mylist;
  char *op;


  op = (char *) calloc(10,sizeof(char));
  mylist = dyn_list_simple_create((int (*)(void *, void *))&cmp);

  while(1){
    scanf("%s",op);
    if (strcmp(op,"cadastrar")==0){
      char *pNome, *uNome, *cpf, *tel;
      pNome = (char *) calloc(15,sizeof(char));
      uNome = (char *) calloc(15,sizeof(char));
      cpf = (char *) calloc(11,sizeof(char));
      tel = (char *) calloc(20,sizeof(char));
      scanf("%s",pNome);
      scanf("%s",uNome);
      scanf("%s",cpf);
      scanf("%s",tel);
      dyn_list_simple_add(mylist, dyn_list_simple_size(mylist), pNome, uNome, cpf, tel);
    }
    else if (strcmp(op,"remover")==0){
      char *cpf;
      cpf = (char *) calloc(11,sizeof(char));
      scanf("%s",cpf);
      dyn_list_simple_remove(mylist, cpf);
    }
    else if (strcmp(op,"dump")==0){
      dyn_list_simple_dump(mylist);
    }
    else if (strcmp(op,"buscar")==0){
      char *cpf;
      cpf = (char *) calloc(11,sizeof(char));
      scanf("%s",cpf);
      dyn_list_simple_sequential_search(mylist, cpf);
    }
    else if (strcmp(op,"sair")==0){
      dyn_list_simple_free(mylist);
      free(op);
      break;
    }
    else printf("Invalid operation\n");
  }

  return 0;

}
