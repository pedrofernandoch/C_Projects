#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char nome[100];
    int idade;
    float salario;
}dados;

int id=3;
void cadastro_dados(char *);
void remove_dados(char *);
int menu();
int main()
{
   int op;
  // cadastro_dados("cadastro.bin");
   
   op=menu();
   while(op){
   switch (op){
       case 0: printf("Tchau!!!");
               break;
        case 1: cadastro_dados("cadastro.bin");
                break;
   //     case 2: retorna_dados();
                break;
        case 3: remove_dados("cadastro.bin");
                break;
/*        case 4: altera_dados();
                break;*/
        default: printf("Opção Inválida");
        
   }
   op=menu();
 }
 return 0;
}

int menu(){
    int op;
    printf("\n0-Sair\n1-Insere dados\n2-Retorna dados");
    printf("\n3-Remove dados\n4-Altera dados\nOpção:");
    scanf("%d",&op);
    return op;
}

void cadastro_dados(char *str){
    FILE *arq;
    int sair=1;
    dados usr;
    
    arq=fopen(str,"ab+");
    if(arq==NULL){
        printf("\nErro cadastro_dados");
        exit(0);
    }
    
    do{
        printf("Nome:"); scanf(" %[^\n]s",usr.nome);
        printf("Idade:"); scanf(" %d",&usr.idade);
        printf("Salario:"); scanf(" %f",&usr.salario);
        usr.id = ++id;
        fwrite(&usr,sizeof(dados),1,arq);
        printf("Digite 0 para sair:"); scanf("%d",&sair);
    }while(sair);
    
    fclose(arq);
    
}

void remove_dados(char *str){
    
    FILE *arq = fopen(str,"rb+");
    dados usr;
    int id, aux=-1;;
    long int tam;
    printf("Id a ser removido:");scanf("%d",&id);
    while(fread(&usr,sizeof(dados),1,arq)){
        if(usr.id==id){
            tam = sizeof(usr);
            fseek(arq,aux*tam,SEEK_CUR);
            usr.id = -1;
            fwrite(&usr,sizeof(dados),1,arq);
            fseek(arq, 0, SEEK_END);
             continue;
        }
    }
    fclose(arq);
}