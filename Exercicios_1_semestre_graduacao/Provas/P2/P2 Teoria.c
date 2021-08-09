#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int calculaPonto(int *);

int main(void) {

  char time1[MAX],time2[MAX],time3[MAX],time4[MAX];
  int table1[3],table2[3],table3[3],table4[3];
  int i,ponto1,ponto2,ponto3,ponto4;

  scanf("%s",time1);
  for (i=0;i<3;i++){
  		scanf("%d",&table1[i]);
  }
  scanf("%s",time2);
  for (i=0;i<3;i++){
  		scanf("%d",&table2[i]);
  }
  scanf("%s",time3);
  for (i=0;i<3;i++){
  		scanf("%d",&table3[i]);
  }
  scanf("%s",time4);
  for (i=0;i<3;i++){
  		scanf("%d",&table4[i]);
  }

  ponto1= calculaPonto(table1);
  ponto2= calculaPonto(table2);
  ponto3= calculaPonto(table3);
  ponto4= calculaPonto(table4);
 
  if (ponto1!=ponto2 && ponto1!=ponto3 && ponto1!=ponto4 && ponto2!=ponto3 && ponto2!=ponto4 && ponto3!=ponto4){
    if (ponto1>ponto2 && ponto1>ponto3 && ponto1>ponto4){
      printf("%s ",time1);
      printf("%d",ponto1);
    }
    else if (ponto2>ponto1 && ponto2>ponto3 && ponto2>ponto4){
      printf("%s ",time2);
      printf("%d",ponto2);
    }
    else if (ponto3>ponto2 && ponto3>ponto1 && ponto3>ponto4){
      printf("%s ",time3);
      printf("%d",ponto3);
    }
    else if (ponto4>ponto2 && ponto4>ponto3 && ponto4>ponto1){
      printf("%s ",time4);
      printf("%d",ponto4);
    }
  }
 else{
  if (ponto1==ponto2){
    if (table1[1]>table2[1]){
      printf("%s ",time2);
      printf("%d",ponto2);
    }
    else{
      printf("%s ",time1);
      printf("%d",ponto1);
    }
  }

  if (ponto1==ponto3){
    if (table1[1]>table3[1]){
      printf("%s ",time3);
      printf("%d",ponto3);
    }
    else{
      printf("%s ",time1);
      printf("%d",ponto1);
    }
  }

  if (ponto1==ponto4){
    if (table1[1]>table4[1]){
      printf("%s ",time4);
      printf("%d",ponto4);
    }
    else{
      printf("%s ",time1);
      printf("%d",ponto1);
    }
  }

  if (ponto2==ponto3){
    if (table2[1]>table3[1]){
      printf("%s ",time3);
      printf("%d",ponto3);
    }
    else{
      printf("%s ",time2);
      printf("%d",ponto2);
    }
  }
  if (ponto2==ponto4){
    if (table2[1]>table4[1]){
      printf("%s ",time4);
      printf("%d",ponto4);
    }
    else{
      printf("%s ",time2);
      printf("%d",ponto2);
    }
  }
  if (ponto3==ponto4){
    if (table3[1]>table4[1]){
      printf("%s ",time4);
      printf("%d",ponto4);
    }
    else{
      printf("%s ",time3);
      printf("%d",ponto3);
    }
  }
 }
  return 0;
}
int calculaPonto(int *table){

	int ponto;

	ponto = (table[0] * 3) + table[2];

	return ponto;
}