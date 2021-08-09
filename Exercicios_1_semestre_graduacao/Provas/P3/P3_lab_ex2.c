#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct aluno{ 
int matricula; 
char nome[50]; 
int idade; 
char sexo; 
float notas[5][3]; 
};

typedef struct aluno tAluno;

void lerArqBin(tAluno alunos[]);
void lerArqTxt(tAluno alunos[]);
void processarNotas(tAluno alunos[]);

int main(){

  tAluno alunos[3];

  lerArqBin(alunos);
  lerArqTxt(alunos);
  processarNotas(alunos);

 return 0;
}

void lerArqBin(tAluno alunos[]){

  FILE *arq;
  int i;

  arq = fopen("alunos.bin","rb");
  assert(arq);

  for (i=0;i<3;i++){
      fread(&alunos[i], sizeof(tAluno),1, arq);
  }

  fclose(arq);
}

void lerArqTxt(tAluno alunos[]){
  
  FILE *arq;
  int i=0;

  arq = fopen("notas.txt","r");
  assert(arq);

  while(fscanf(arq,"%d\n%f %f %f\n%f %f %f\n%f %f %f\n%f %f %f\n%f %f %f",&alunos[i].matricula,&alunos[i].notas[0][0],&alunos[i].notas[0][1],&alunos[i].notas[0][2],&alunos[i].notas[1][0],&alunos[i].notas[1][1],&alunos[i].notas[1][2],&alunos[i].notas[2][0],&alunos[i].notas[2][1],&alunos[i].notas[2][2],&alunos[i].notas[3][0],&alunos[i].notas[3][1],&alunos[i].notas[3][2],&alunos[i].notas[4][0],&alunos[i].notas[4][1],&alunos[i].notas[4][2])!=EOF){
    i++;
  }

  fclose(arq);

}

void processarNotas(tAluno alunos[]){

float media;
int k=0;

  for (int i=0; i<3; i++){
    printf("%s\n",alunos[i].nome);
    while (k<5){
      for (int j=0; j<3; j++){
        media+=alunos[i].notas[k][j];
      }
      media= media/3;
      if (media>= 5){
        printf("aprovado\n");
      }
      else{
        printf("reprovado\n");
      }
      k++;
      media=0;
    }
    k=0;
  printf("\n");
  }

}