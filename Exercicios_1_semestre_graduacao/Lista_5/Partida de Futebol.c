#include <stdio.h>

void calcula_pontos(int *, int *, char []);

int main(void) {

  int p1,p2;
  char placar[3];

  scanf("%d",&p1);
  scanf("%d",&p2);
  scanf("%s",placar);

  calcula_pontos(&p1, &p2, placar);

  printf("%d %d",p1,p2);

  return 0;
}

void calcula_pontos(int *pontos1, int *pontos2, char placar[]){

    if (placar[0]==placar[2]){ //Empate
      *pontos1=*pontos1 + 1;
      *pontos2=*pontos2 + 1;
    }
    else if (placar[0]>placar[2]){ //Time 1 ganha
      *pontos1= *pontos1 +3;
    }
    else {
      *pontos2= *pontos2 +3;    //Time 2 ganha
    }

}