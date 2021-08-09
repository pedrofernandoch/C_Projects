#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct{
    int hora;
    int minuto;
    int segundo;
}hora;

typedef struct{
    int ano;
    int mes;
    int dia;
}data;

typedef struct{
    char atividade[100];
    hora hora;
    data data;
}agenda;

int main(){

  int qtd,i;
  agenda *a1;

  scanf("%d",&qtd);

  a1= (agenda*) malloc(qtd*sizeof(agenda));
  assert(a1);

  for (i=0;i<qtd;i++){
    scanf("%d",&a1[i].data.dia);
    scanf("%d",&a1[i].data.mes);
    scanf("%d",&a1[i].data.ano);
    scanf("%d",&a1[i].hora.hora);
    scanf("%d",&a1[i].hora.minuto);
    scanf("%d\n",&a1[i].hora.segundo);
    fgets(a1[i].atividade,100,stdin);
  }
  for (i=0;i<qtd;i++){
      printf("%02d/%02d/%d - %02d:%02d:%02d\n",a1[i].data.dia,a1[i].data.mes,a1[i].data.ano,a1[i].hora.hora,a1[i].hora.minuto,a1[i].hora.segundo);
      printf("%s",a1[i].atividade);
    }

  free(a1);

  return 0;
}
