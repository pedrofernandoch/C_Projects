#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void trocaLetra(char*, char *, char, int*);

int main(void) {

char letra, palavra[30], palavraTrocada[30];
int nTrocas=0;

scanf("%c",&letra);
scanf("%s",palavra);

trocaLetra(palavra, palavraTrocada, letra, &nTrocas);

printf("Numero de trocas: %d\n",nTrocas);
printf("Nova palavra: %s\n",palavraTrocada);
printf("Palavra original: %s",palavra);
 
  return 0;
}

void trocaLetra(char* palavra, char* palavraTrocada, char letra, int* nTrocas){

  int tam,i;

  tam= strlen(palavra);

  for (i=0;i<tam;i++){
      palavraTrocada[i]= palavra[i];
    
  }

  for (i=0;i<tam;i++){
    if (palavra[i]==letra){
      palavraTrocada[i]= letra + i;
      *nTrocas= *nTrocas + 1;
    }
  }

}