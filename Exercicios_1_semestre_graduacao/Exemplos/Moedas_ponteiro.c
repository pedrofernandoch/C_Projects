#include <stdio.h>
#include <stdlib.h>

void calcula_troco (int *, int *, int *, int *, int *, int *, int);

int main(void) {
  
int centavos,r1,c50,c25,c10,c5,c1;

scanf("%d",&centavos);

calcula_troco(&r1,&c50,&c25,&c10,&c5,&c1,centavos);

printf("O valor consiste em %d moedas de 1 real\n",r1);
printf("O valor consiste em %d moedas de 50 centavos\n",c50);
printf("O valor consiste em %d moedas de 25 centavos\n",c25);
printf("O valor consiste em %d moedas de 10 centavos\n",c10);
printf("O valor consiste em %d moedas de 5 centavos\n",c5);
printf("O valor consiste em %d moedas de 1 centavo",c1);

  return 0;
}

void calcula_troco (int *r1, int *c50, int *c25, int *c10, int *c5, int *c1, int centavos){

  int resto;

  *r1 = centavos / 100;
  resto = centavos % 100;

  *c50 = resto / 50;
  resto = resto % 50;

  *c25 = resto / 25;
  resto = resto % 25;

  *c10 = resto / 10;
  resto = resto % 10;

  *c5 = resto / 5;
  resto = resto % 5;

  *c1 = resto / 1;
  resto = resto % 1;

}