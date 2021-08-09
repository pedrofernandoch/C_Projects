#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct{
  char nome[30];
  char sexo;
  int idade;
} pessoas;

int main() {

  int i=0,j,qtdM=0,qtdF=0,somaM=0,somaF=0;
  float mediaM,mediaF,mediaTotal;
  FILE *dados;
  pessoas *usr;
  
    dados = fopen("dados.txt","r");
    assert(dados);
    usr= (pessoas *) malloc(1*sizeof(pessoas));
    assert(usr);
    
    while (fscanf(dados, "%s %c %d\n",usr[i].nome,&usr[i].sexo,&usr[i].idade)!=EOF){
            i++;
            usr= (pessoas *) realloc(usr,(i+1) * sizeof(pessoas));
    }
    
    for (j=0;j<i;j++){
        if (usr[j].sexo=='m'){
            somaM+=usr[j].idade;
            qtdM++;
        }
        else{
            somaF+=usr[j].idade;
            qtdF++;
        }
    }
    mediaM= (float) somaM/qtdM;
    mediaF= (float) somaF/qtdF;
    mediaTotal= (float) (somaM+somaF)/i;
    printf("%d %d %d %.2f %.2f %.2f",i,qtdM,qtdF,mediaTotal,mediaM,mediaF);


fclose(dados);

  return 0;
}