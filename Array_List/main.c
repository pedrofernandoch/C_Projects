// Nome: Pedro Fernando Christofoletti dos Santos
// NUSP: 11218560

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Array_list.h>

int main(){

  ArrayList *mylist;
  int error;
  char *op;

  op = (char *) calloc(10,sizeof(char));
  mylist = new_arrayList();

  while(1){
    scanf("%s",op);
    if (strcmp(op,"add")==0){
      ITEM *element;
      element = (ITEM *) malloc(1 * sizeof(ITEM));
      scanf("%d",&element->chave);
      scanf("%d",&element->valor);
      add_arrayList(mylist,element);
    }
    else if (strcmp(op,"tamanho")==0){
      printf("%d\n",size_arrayList(mylist));
    }
    else if (strcmp(op,"sub")==0){
      int pos1,pos2;
      scanf("%d %d",&pos1,&pos2);
      print_arrayList(subArray_arrayList(mylist, pos1, pos2),&error);
    }
    else if (strcmp(op,"set")==0){
      int pos1,pos2;
      ITEM *element;
      element = (ITEM *) malloc(1 * sizeof(ITEM));
      scanf("%d",&pos1);
      scanf("%d",&element->chave);
      scanf("%d",&element->valor);
      set_arrayList(mylist, pos1,element);
    }
    else if (strcmp(op,"print")==0){
      print_arrayList(mylist,&error);
    }
    else if (strcmp(op,"contem")==0){
      int chave;
      scanf("%d",&chave);
      printf("%d\n",contains_arrayList(mylist,chave));
    }
    else if (strcmp(op,"indice")==0){
      int chave;
      scanf("%d",&chave);
      indexOf_arrayList(mylist,chave);
    }
    else if (strcmp(op,"vazia")==0){
      printf("%d\n",isEmpty_arrayList(mylist));
    }
    else if (strcmp(op,"remover")==0){
      int pos;
      scanf("%d",&pos);
      remove_arrayList(&mylist,pos);
    }
    else if (strcmp(op,"get")==0){
      int pos;
      scanf("%d",&pos);
      ITEM *item = get_arrayList(mylist,pos);
      if (item)printf("%d/%d\n", item->chave, item->valor);
    }
    else if (strcmp(op,"sair")==0){
      destruct_arrayList(&mylist);
      free(op);
      break;
    }
    else printf("Invalid operation\n");
  }

  return 0;

}
