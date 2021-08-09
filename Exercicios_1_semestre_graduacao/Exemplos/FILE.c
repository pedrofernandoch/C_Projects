#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int id=0;

typedef struct{
  int id;
  char nome[100];
  int idade;
  float salario;
} dados;

void cadastroDados(char *);
void retornaDados(char *);
void removeDados(char *);
//void alteraDados(char *);
int menu();

int main() {

  int op;

  //cadastroDados("cadastro.txt");

  op=menu();
  while(op){
    switch(op){
      case 0: printf("TCHAU!");
        break;
      case 1: cadastroDados("cadastro.txt");
        break;
      case 2: retornaDados("cadastro.txt");
        break;
      case 3: removeDados("cadastro.txt");
        break;
      //case 4: alteraDados("cadastro.txt");
        //break;
      dafault: printf("Opção Inválida");
    }
    op=menu();
  }

  return 0;
}

void cadastroDados(char *str){
  FILE *arq;
  int sair=1;
  dados usr;

  arq=fopen(str,"ab+");
  assert(arq);
  
  do{

    printf("Nome: ");scanf(" %[^\n]s",usr.nome);
    printf("Idade: ");scanf("%d",&usr.idade);
    printf("Salário: ");scanf("%f",&usr.salario);
    //fprintf(arq,"%d %s\n",++id,usr.nome);
    fwrite(&usr,sizeof(dados),1,arq);
    fwrite(&usr,sizeof(dados),1,arq);
    //fprintf(arq,"%d %.2f\n",usr.idade,usr.salario);
    fwrite(&usr,sizeof(dados),1,arq);
    fwrite(&usr,sizeof(dados),1,arq);
    printf("Digite 0 para sair: ");scanf("%d",&sair);
  }while (sair);

  fclose(arq);

}
int menu(){
  int op;
  printf("\n0-Sair\n1-Insere dados\n2-Retorna dados");
  printf("\n3-Remove dados\n4-Altera dados\nOpção:");
  scanf("%d",&op);

  return op;
}
void retornaDados(char *str){
  FILE *arq;
  dados usr;
  arq = fopen(str,"rb");
  int id;

  printf("Digite ID:");scanf("%d",&id);

  //while(fscanf(arq,"%d %[^\n]s",&usr.id,usr.nome)!=EOF){
  while(fread(&usr,sizeof(dados),1,arq)){
      //fscanf(arq,"%d %f",&usr.idade,&usr.salario);
      fread(&usr,sizeof(dados),1,arq);
      if (usr.id==id){
        printf("\nNome: %s R$%.2f",usr.nome,usr.salario);
        break;
      }   
  }
}
void removeDados(char *str){
    
    FILE *arq = fopen(str,"rb+");
    dados usr;
    int id, aux=-1;;
    long int tam;
    printf("Id a ser removido:");scanf("%d",&id);
    //while(fscanf(arq,"%d %[^\n]s\n",&usr.id,usr.nome)!=EOF){
    while(fread(&usr,sizeof(dados),1,arq)){
        if(usr.id==id){
            tam = strlen(usr.nome)+2;
            fseek(arq,aux*tam,SEEK_CUR);
            fprintf(arq,"%d %s\n",aux,usr.nome);
            fseek(arq, 0, SEEK_END);
             continue;
        }
        
        fscanf(arq,"%d %f",&usr.idade,&usr.salario);
    }
    fclose(arq);
}