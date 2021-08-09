// Nome: Pedro Fernando Christofoletti dos Santos
// NUSP: 11218560

#include <stdlib.h>
#include <stdio.h>
#include <Array_list.h>

typedef struct NO{
  ITEM **list;
  int fimvet;
  int tamanho;
  struct NO *proximo;
} NO;

struct ArrayList{
  NO *inicio;
  int counter;
  int size;
};

#define SUCCESS 1;
#define INVALID_LIST -1;
#define INVALID_ELEM -2;
#define INVALID_POS -3;
#define INDEX_NOT_FOUND -4;

//==========================================================================================//
//                                   NEW ARRAY LIST                                         //
//==========================================================================================//
ArrayList *new_arrayList(){
  ArrayList *list;
  list = (ArrayList *) calloc(1,sizeof(ArrayList));
  return list;
}

//==========================================================================================//
//                                        ADD                                               //
//==========================================================================================//
int add_arrayList(ArrayList *arrayList, ITEM *element){
  if (!arrayList) return INVALID_LIST;
  if (!element) return INVALID_ELEM;

  //Se lista estiver vazia
  if (!arrayList->inicio){
    NO *vet;
    vet = (NO *) calloc(1,sizeof(NO));
    vet->tamanho = 10;
    vet->list = (ITEM **) calloc(vet->tamanho,sizeof(ITEM *));
    for (int i = 0; i < vet->tamanho; i++){
      vet->list[i] = (ITEM*) calloc(1,sizeof(ITEM));
    }
    vet->list[vet->fimvet]->chave = element->chave;
    vet->list[vet->fimvet]->valor = element->valor;
    arrayList->inicio = vet;
    arrayList->size++;
    arrayList->counter++;
  }
  else{//Se lista não estiver vazia
    NO *aux = arrayList->inicio;
    int counter = arrayList->counter;
    while(counter > 1 && (aux = aux->proximo) && counter--);
    if ((aux->fimvet+1) == aux->tamanho){// Se estiver no tamanho máximo, cria novo nó
      NO *newNO;
      newNO = (NO *) calloc(1,sizeof(NO));
      newNO->tamanho = aux->tamanho * 2;
      newNO->list = (ITEM **) calloc(newNO->tamanho,sizeof(ITEM*));
      for (int i = 0; i < newNO->tamanho; i++){
        newNO->list[i] = (ITEM*) calloc(1,sizeof(ITEM));
      }
      newNO->list[newNO->fimvet]->chave = element->chave;
      newNO->list[newNO->fimvet]->valor = element->valor;
      aux->proximo = newNO;
      arrayList->counter++;
      arrayList->size++;
    }else{// Se ainda existe espaço para novos ITEMS
      aux->list[aux->fimvet+1]->chave = element->chave;
      aux->list[aux->fimvet+1]->valor = element->valor;
      aux->fimvet++;
      arrayList->size++;
    }
  }

  return SUCCESS;
}

//==========================================================================================//
//                                        SIZE                                              //
//==========================================================================================//
int size_arrayList(ArrayList *arrayList){
  if (!arrayList) return INVALID_LIST;
  return arrayList->size;
}

//==========================================================================================//
//                                        PRINT                                             //
//==========================================================================================//
void print_arrayList(ArrayList *arrayList, int *error){
  if (!arrayList || !arrayList->inicio){
    *error= INVALID_LIST;
  }else{
    sort(arrayList);
    NO *aux = arrayList->inicio;
    int counter = 0, global=0;
    while(counter < arrayList->counter){
      for (int i = 0; i <= aux->fimvet; i++){
        printf("%d: ",global);
        printf( "%d/%d\n", aux->list[i]->chave, aux->list[i]->valor);
        global++;
      }
      printf("\n\n");
      counter++;
      aux = aux->proximo;
    }
  }
}

//==========================================================================================//
//                                        SUB                                               //
//==========================================================================================//
ArrayList *subArray_arrayList(ArrayList *arrayList, int beginIndex,int endIndex){
  if (!arrayList || !arrayList->inicio) return NULL;
  ArrayList *list;
  list = new_arrayList();
  NO *aux = arrayList->inicio;
  int counter = 0,global=0;
  while(counter < arrayList->counter){
    for (int i = 0; i <= aux->fimvet; i++){
      if (global >= beginIndex && global < endIndex)add_arrayList(list, aux->list[i]);
      global++;
    }
    counter++;
    aux = aux->proximo;
  }
  return list;

}

//==========================================================================================//
//                                         SET                                              //
//==========================================================================================//
int set_arrayList(ArrayList *arrayList, int pos, ITEM *element){
  if (!arrayList || !arrayList->inicio) return INVALID_LIST;
  if (pos<0 || pos>=arrayList->size)return INVALID_POS;

  NO *aux = arrayList->inicio;
  int counter = 0,global=0;
  while(counter < arrayList->counter){
    for (int i = 0; i < aux->tamanho; i++){
      if (global==pos){
        aux->list[i]=element;
      }
      global++;
    }
    counter++;
    aux = aux->proximo;
  }
  sort(arrayList);
  
  return SUCCESS;

}

//==========================================================================================//
//                                       CONTAINS                                           //
//==========================================================================================//
int contains_arrayList(ArrayList *arrayList, int chave){
  if (!arrayList || !arrayList->inicio) return INVALID_LIST;

  NO *aux = arrayList->inicio;
  int counter = 0;
  while(counter < arrayList->counter){
    for (int i = 0; i <= aux->fimvet; i++){
      if (chave == aux->list[i]->chave)return 1;
    }
    counter++;
    aux = aux->proximo;
  }
  return 0;
}

//==========================================================================================//
//                                         INDEX                                            //
//==========================================================================================//
int indexOf_arrayList(ArrayList *arrayList, int chave){
  if (!arrayList || !arrayList->inicio) return INVALID_LIST;

  NO *aux = arrayList->inicio;
  int counter = 0, add=0;
  while(counter < arrayList->counter){
    for (int i = 0; i <= aux->fimvet; i++){
      if (chave == aux->list[i]->chave){
        printf("%d\n", i+add);
        return SUCCESS
      }
    }
    counter++;
    add = add + aux->fimvet +1;
    aux = aux->proximo;
  }
  return INDEX_NOT_FOUND;
}

//==========================================================================================//
//                                         EMPTY                                            //
//==========================================================================================//
int isEmpty_arrayList(ArrayList *arrayList){
  if(!arrayList)return INVALID_LIST;
  if(!arrayList->inicio)return 1;
  else return 0;
}

//==========================================================================================//
//                                         REMOVE                                           //
//==========================================================================================//
int remove_arrayList(ArrayList **arrayList, int pos){
  if (!*arrayList || !(*arrayList)->inicio) return INVALID_LIST;
  if (pos<0 || pos>=(*arrayList)->size)return INVALID_POS;

  int i,add=0;
  NO *no = (*arrayList)->inicio;
  while(no){
    if(pos>no->fimvet+add){
      add += no->tamanho;
      no = no->proximo;
    }
    else break;
  }

  no->list[pos-add]->chave = -2147483647; //Garante que será a menor chave possível para que na ordenação fique em primeiro

  sort(*arrayList);

  ArrayList **list = arrayList;

//Cria uma nova lista sem o primeiro item e atribui para a lista original
  if((*arrayList)->size==0){
      (*arrayList)->size++;
      *list = subArray_arrayList(*arrayList,0,(*arrayList)->size);
  }else{
    *list = subArray_arrayList(*arrayList,1,(*arrayList)->size);
  }


  return SUCCESS
}

//==========================================================================================//
//                                           GET                                            //
//==========================================================================================//
ITEM *get_arrayList(ArrayList *arrayList, int pos){
  if (!arrayList || !arrayList->inicio) return NULL;
  if (pos<0 || pos>=arrayList->size)return NULL;

  int i,add=0;
  NO *no = arrayList->inicio;
  while(no){
    if(pos>no->fimvet+add){
      add += no->tamanho;
      no = no->proximo;
    }
    else break;
  }

  return no->list[pos-add];
}

//==========================================================================================//
//                                         DESTRUCT                                         //
//==========================================================================================//
int destruct_arrayList(ArrayList **arrayList){
  if (!*arrayList || !(*arrayList)->inicio) return INVALID_LIST;
  if(!(*arrayList)->counter){
    free(*arrayList);
    return SUCCESS;
  }

  ArrayList **list = arrayList;
  NO *no,*aux;
  no = (*list)->inicio;
  int counter=0;
  while(no){
    aux = no->proximo;
    while(counter < no->tamanho){
      free(no->list[counter]);
      counter++;
    }
    free(no);
    no = aux;
    counter=0;
  }
  free(*list);

  return SUCCESS;
}

//==========================================================================================//
//                                         SORT                                             //
//==========================================================================================//

void sort(ArrayList *arrayList){

  //Uso do InsertionSort pois apesar de possuir complexidade O(N²), em casos onde os elementos estão quase ordenados ele se torna um dos melores algoritmos de ordenação

    NO *no = arrayList->inicio;
    ITEM **vet;
    int counter = 0,global=0,j=0;
    vet = (ITEM **) calloc(arrayList->size,sizeof(ITEM *));
      for (int i = 0; i < arrayList->size; i++){
        vet[i] = (ITEM*) calloc(1,sizeof(ITEM));
      }

    while(counter < arrayList->counter){
      for (int i = 0; i <= no->fimvet; i++,j++){
        vet[j]= no->list[i];
      }
      counter++;
      no = no->proximo;
    }

      int i, key, valor, k;
      for (i = 1; i < arrayList->size; i++) {
          key = vet[i]->chave;
          valor = vet[i]->valor;
          k = i - 1;
          while (k >= 0 && vet[k]->chave > key) {
              vet[k+1]->chave = vet[k]->chave;
              vet[k+1]->valor = vet[k]->valor;
              k = k - 1;
          }
          vet[k+1]->chave = key;
          vet[k+1]->valor = valor;
      }

      counter = j = 0;
      no= arrayList->inicio;

    while(counter < arrayList->counter){
      for (int i = 0; i <= no->fimvet; i++,j++){
        no->list[i]= vet[j];
      }
      counter++;
      no = no->proximo;
    }

}
