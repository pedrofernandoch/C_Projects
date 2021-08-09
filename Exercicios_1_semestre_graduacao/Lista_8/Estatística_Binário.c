#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct{
char nome[50];
int idade;
char sefo;
float salario;
}funcionario;

int main(){
  FILE *arq;
  funcionario f;
  int qtdH=0,qtdM=0;
  float salarioMulher=0,salarioHomem=0,salarioTotal=0;

  arq= fopen("dados-funcionario.bin","rb");
  assert(arq);

  while(fread(&f,sizeof(f),1,arq)){
    salarioTotal+=f.salario;
    if(f.sefo=='m'){
      salarioHomem+=f.salario;
      qtdH++;
    }
    if(f.sefo=='f'){
      salarioMulher+=f.salario;
      qtdM++;
    }
  }

  fclose(arq);

  printf("%d %d %d %.2f %.2f %.2f ",qtdM+qtdH,qtdH,qtdM,salarioTotal/(qtdM+qtdH),salarioHomem/qtdH,salarioMulher/qtdM);

	return 0;
}
