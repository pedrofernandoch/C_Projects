#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct{
    int filhos;
    float salario;
}dados;

typedef struct{
    char nome[100];
    int idade;
    dados outros;
}reg;

void cadastro(reg *, int *);
reg pDados();
void imprimiDados(reg *);
int main(){

  reg *cadReg;
  int size;

  cadastro(cadReg,&size);

    return 0;
}

void cadastro(reg *vReg, int *size){

  int flag=1,i;

  vReg=NULL;
  *size=0;
  while(flag){
  *size +=1;
  vReg= (reg *) realloc(vReg,*size * sizeof(reg));
  assert(vReg);
  vReg[*size-1]=pDados();
  printf("\nDeseja continuar cadastrando?\n");
  scanf("%d",&flag);
  }
  for (i=0;i<*size;i++){
    printf("\n");
    imprimiDados(&vReg[i]);
  }
}

reg pDados(){

  reg cadTemp;

  printf("Nome = ");scanf(" %[a-z A-Z]s",cadTemp.nome);
  printf("Idade = ");scanf(" %d",&cadTemp.idade);
  printf("Num filhos = ");scanf("%d",&cadTemp.outros.filhos);
  printf("Salário = ");scanf("%f",&cadTemp.outros.salario);

  return cadTemp; 
}

void imprimiDados(reg *prg){

  printf("\nNome: %s",prg->nome);
  printf("\nIdade: %d",prg->idade);
  printf("\nNum Filhos: %d",prg->outros.filhos);
  printf("\nSalário: R$ %.2f",prg->outros.salario);

}