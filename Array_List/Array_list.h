// Nome: Pedro Fernando Christofoletti dos Santos
// NUSP: 11218560

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

struct ITEM{
  int chave;
  int valor;
};

typedef struct ITEM ITEM;
typedef struct ArrayList ArrayList;

//Cria a ArrayList e aloca toda mem�oria necessaria
ArrayList *new_arrayList();
//Adiciona elemento ao arraylist
int add_arrayList(ArrayList *arrayList, ITEM *element);
//Verifica no arraylist se existe um elemento com a chave informada
int contains_arrayList(ArrayList *arrayList, int chave);
//Recupera um ITEM na posicao informada
ITEM *get_arrayList(ArrayList *arrayList, int pos);
//Retorna qual a posicao do primeiro elemento com a chave informada
int indexOf_arrayList(ArrayList *arrayList, int chave);
//Verifica se o arraylist esta vazio
int isEmpty_arrayList(ArrayList *arrayList);
//Remove um elemento do arraylist
int remove_arrayList(ArrayList **arrayList, int pos);
//Modifica um elemento do arraylist
int set_arrayList(ArrayList *arrayList, int pos, ITEM *element);
//Retorna o tamanho total do arraylist
int size_arrayList(ArrayList *arrayList);
//Recupera um novo subarray no intervalo [beginIndex, endIndex[
ArrayList *subArray_arrayList(ArrayList *arrayList, int beginIndex, int endIndex);
//Desaloca memoria alocada pelo arraylist
int destruct_arrayList(ArrayList **arrayList);
//Imprime toda a lista
void print_arrayList(ArrayList *arrayList, int *error);
//Ordena
void sort(ArrayList *arrayList);

#endif
