#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4

void dardo(char [MAX], int*);

int main(void) {

  int pontos1=301,pontos2=301,qtdJogadas,jogador=1;
  char tacada[MAX];

  while(pontos1!=0 && pontos2!=0){
    for (qtdJogadas=0;qtdJogadas<3;qtdJogadas++){
        if (pontos1 == 0 || pontos2 == 0)
        break;

        scanf("%s",tacada);

        if (jogador == 1){
          dardo(tacada, &pontos1);
        }
        else {
            dardo(tacada, &pontos2);
        }
    }

    if (jogador == 1)
    jogador = 2;
    else 
    jogador = 1;
  }  

  if (pontos1 == 0){
    printf("1 %d",pontos2);
  }
  else {
    printf("2 %d",pontos1);
  }

  return 0;
}

void dardo(char position[MAX], int *ponto){

  char secao = position[0],set[3];
  int setor, pontoAtual = 0;

  set[0] = position[1];
  set[1] = position[2];
  set[2] = '\0';

  if (secao != 'X'){
      setor = atoi(set);
      if(secao == 'S')
      pontoAtual = setor;
      else if(secao == 'D')
      pontoAtual = setor*2;
      else if(secao == 'T')
      pontoAtual = setor*3;
      else if(secao == 'M')
      pontoAtual = setor*25;
  }

  if (*ponto - pontoAtual >= 0)
      *ponto -= pontoAtual;

}