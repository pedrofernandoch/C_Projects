// Nome: Pedro Fernando Christofoletti dos Santos
// NUSP: 11218560

#include <stdio.h>
#include <stdlib.h>
#include "anagrama.h"

//=====================================================================================//
//                                      PRINT                                          //
//=====================================================================================//
int print_palavras(PALAVRA *palavras, int numPalavras, int maior){
  if(!palavras) return INVALID_WORDS;

  int i,j;
  for(i=0;i<numPalavras;i++){
    if(palavras[i].qtd == maior){
      for(j=0;j<palavras[i].qtd+1;j++){
        printf("%s%s",palavras[i].anagrama[j],(j == palavras[i].qtd)? "\n" :", ");
      }
    }
  }

  return SUCCESS;
}

//=====================================================================================//
//                                      FREE                                           //
//=====================================================================================//
int free_palavras(PALAVRA *palavras, int numPalavras){
  if(!palavras) return INVALID_WORDS;

  int i,j;
  for(i=0;i<numPalavras;i++){
    if(palavras[i].qtd>1){
      for(j=0;j<palavras[i].qtd-1;j++){
        free(palavras[i].anagrama[j]);
      }
    }
  }
  free(palavras);

  return SUCCESS;
}