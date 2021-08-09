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

reg * cadastro(int *);
reg pDados();
void imprimiDados(reg *);

//################################# Main ###################################

int main(){

  reg *cadReg;
  int size,i;

  cadReg= cadastro(&size);

  for (i=0;i<size;i++){
    printf("\n");
    imprimiDados(&cadReg[i]);
  }

    return 0;
}

//############################### Cadastro #############################

reg * cadastro(int *size){

  int flag=1;
  reg *vReg;

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

  return vReg;
}

//############################# pdados ################################

reg pDados(){

  reg cadTemp;

  printf("Nome = ");scanf(" %[a-z A-Z]s",cadTemp.nome);
  printf("Idade = ");scanf(" %d",&cadTemp.idade);
  printf("Num filhos = ");scanf("%d",&cadTemp.outros.filhos);
  printf("Salário = ");scanf("%f",&cadTemp.outros.salario);

  return cadTemp; 
}

//############################ Imprimir Dados ##########################

void imprimiDados(reg *prg){

  printf("\nNome: %s",prg->nome);
  printf("\nIdade: %d",prg->idade);
  printf("\nNum Filhos: %d",prg->outros.filhos);
  printf("\nSalário: R$ %.2f",prg->outros.salario);

}