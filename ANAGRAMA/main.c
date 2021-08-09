// Nome: Pedro Fernando Christofoletti dos Santos
// NUSP: 11218560

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anagrama.h"

//FUNÇÃO DE COMPARAÇÃO QUE SERVE DE PARÂMETRO PARA A FUNÇÃO QSORT
int cmp(const void *a, const void *b){
  if (strcmp(*(char**)a,*(char**)b)>0) return 1;
  else if (strcmp(*(char**)a,*(char**)b)<0) return -1;
  else return 0;
}

int main(void) {
  char *nome_arq,*aux;
  FILE *dicionario;
  int i=0,j,k=0,numPalavras=0,flag=0,maior=0;
  int primos[26] = {2, 3, 5, 7, 11, 13,
                    17, 19, 23, 29, 31,
                    37, 41, 43, 47, 53,
                    59, 61, 67, 71, 73,
                    79, 83, 89, 97, 101}; //VETOR DE PRIMOS PARA FORMAR ID UNICO
  PALAVRA *palavras = (PALAVRA*) malloc(sizeof(PALAVRA));

  scanf("%ms",&nome_arq);
  dicionario = fopen(nome_arq, "r");
  if(dicionario==NULL){
    printf("Arquivo não foi aberto");
    return 0;
  }

  i=0;

  while(fscanf(dicionario,"%ms",&aux) != EOF){
    palavras[i].palavra = aux;
    palavras[i].id = 1;
    palavras[i].qtd = 0;
    for(j=0;j<(strlen(aux));j++) palavras[i].id = palavras[i].id * primos[(int)aux[j]-97]; //TRANSFORMA PALAVRA EM ID UNICO PELO PRODUTO DOS PRIMOS CORRESPONDENTES DE CADA CHAR DA PALAVRA
    for(j=0;j<numPalavras;j++){
      if(palavras[i].id == palavras[j].id){ //CONFERE SE É ANAGRAMA DENTRE AS PALAVRAS ANTERIORES
        flag=1;
        palavras[j].qtd++;
        if(palavras[j].qtd==1)palavras[j].anagrama = (char**) malloc(sizeof(char*));
        else palavras[j].anagrama = (char**) realloc(palavras[j].anagrama, (palavras[j].qtd) * sizeof(char*));
        palavras[j].anagrama[palavras[j].qtd-1]=palavras[i].palavra;
        if(maior<palavras[j].qtd) maior = palavras[j].qtd; // PEGA MAIOR CONJUNTO DE ANAGRAMAS
      }
    }
    if(!flag){ //NÃO É ANAGAMA
      i++;
      palavras = (PALAVRA*) realloc(palavras, (i+1) * sizeof(PALAVRA));
      numPalavras++;
    }
    flag=0;
  }
  fclose(dicionario);

  for(i=0;i<numPalavras;i++){ //ORDENAÇÃO DOS ANAGRAMAS
    if(palavras[i].qtd == maior){
      palavras[j].anagrama = (char**) realloc(palavras[j].anagrama, (palavras[j].qtd+1) * sizeof(char*));
      k++;
      palavras[i].anagrama[palavras[i].qtd] = palavras[i].palavra;
      qsort(palavras[i].anagrama, palavras[i].qtd+1, sizeof(char*), cmp);
    }
  }
  printf("%d\n",k); //NUMERO DE CONJUNTOS DE ANAGRAMAS
  print_palavras(palavras, numPalavras, maior);
  free_palavras(palavras, numPalavras);

  return 0;
}