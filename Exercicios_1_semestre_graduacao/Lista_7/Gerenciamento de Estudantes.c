#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct{
    long int nusp;
    char nome[50];
    char curso[50];
    int idade;
}registro;

registro * cadastro(int *);
void imprimiDados(registro *);
void lerOP(registro*,int);

//################################# Main ###################################

int main(){

  registro *alunos;
  int size;
  
  alunos= cadastro(&size);

  lerOP(alunos,size);

  free(alunos);

system("pause");          
    return 0;
}

//############################### Cadastro #############################

registro * cadastro(int *size){

  registro *vReg;
  int aux;

  vReg=NULL;
  *size=0;

  scanf("%d",&aux);
  
  while(aux!=-1){
  *size +=1;
  vReg= (registro *) realloc(vReg,*size * sizeof(registro));
  assert(vReg);
  vReg[*size-1].nusp = aux;
  scanf(" %[a-z A-Z]s",vReg[*size-1].nome);
  scanf(" %[a-z A-Z]s",vReg[*size-1].curso);
  scanf("%d",&vReg[*size-1].idade);
  scanf("%d",&aux);
  }

  return vReg;

}

//############################ Imprimir Dados ##########################

void imprimiDados(registro *prg){

  printf("Nome: %s\n",prg->nome);
  printf("Curso: %s\n",prg->curso);
  printf("N USP: %ld\n",prg->nusp);
  printf("IDADE: %d\n",prg->idade);
  printf("\n");

}
//############################ Ler Operador ##########################
void lerOP(registro *alunos,int size){

  int aux,i;
  int indicador;
  char curso[30];

  scanf("%d",&aux);
  while (aux!=-1){
    switch(aux){
    case 1: scanf("%d",&indicador);
    for (i=0;i<size;i++){
      if (alunos[i].nusp==indicador)
      imprimiDados(&alunos[i]);
    }
    break;
    case 2: scanf("%[^\n]s",curso);
    for (i=0;i<size;i++){
      if (strcmp(alunos[i].curso,curso)==0)
          imprimiDados(&alunos[i]);
    }
    break;
    case 3: 
    for (i=0;i<size;i++){
      imprimiDados(&alunos[i]);
    }
    break;
  }
  scanf("%d",&aux);
  }
}
