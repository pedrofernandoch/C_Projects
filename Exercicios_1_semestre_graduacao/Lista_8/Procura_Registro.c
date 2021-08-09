#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct{ 
    char nome[40]; 
    int idade; 
    char sexo; 
    int matricula; 
}aluno;

int main(){
    
    int i=0,matricula,*size;
    FILE *arq;
    aluno *usr;
    
    arq = fopen("dados-alunos.bin","rb");
    assert(arq);
    
    size = (int *) malloc (1 * sizeof(int));
    assert(size);
    fread(size,sizeof(int),1,arq);
    usr = (aluno *) malloc (6 * sizeof(aluno));
    assert(usr);
    for (i=0;i< *size ;i++){
        fread(&usr[i], sizeof(aluno),1, arq);
    }
    
    fclose(arq);
	
	scanf("%d",&matricula);
	
	for (i=0;i< *size ;i++){
	    if (usr[i].matricula == matricula){
	        printf("Nome: %s\n", usr[i].nome);
            printf("Idade: %d\n", usr[i].idade);
            printf("Sexo: %c\n", usr[i].sexo);
            printf("Matricula: %d\n", usr[i].matricula);
	    }
	}
	
    free(usr);
    
 return 0;
}