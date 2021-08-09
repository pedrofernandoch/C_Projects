#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

void criar_vet(int *, int);
int * criar_vet2(int);
void imprimir_vet(int *, int);

int main(void) {
  
int v[MAX], n, *u;
srand(time(NULL));
scanf("%d",&n);

criar_vet(v, n);
u = criar_vet2(n);
imprimir_vet(v, n);
imprimir_vet(u, n);

  return 0;
}

void criar_vet (int *p, int dim){

  int i;//vet2[MAX];

  for (i=0;i<dim;i++){
    p[i]= 10 + rand()%21;
    //vet2[i]=p[i];
  }

  //imprimir_vet(vet2,dim);
}

int * criar_vet2 (int dim){

  int i,*vet2;

  for (i=0;i<dim;i++){
    vet2[i]= 10 + rand()%21;
  }

  return &vet2[0];
}

void imprimir_vet (int *p, int dim){

  int i;

  printf("\n[");
  for (i=0;i<dim;i++){
    printf(" (%d,%p) ",p[i],&p[i]);
  }
  printf("]\n");
}