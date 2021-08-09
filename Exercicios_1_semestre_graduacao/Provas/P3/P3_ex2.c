#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct{ 
int dia; 
int mes; 
int ano; 
char sexo; 
float altura; 
float peso; 
char nome[50]; 
}bebe;

int main(){
    
  FILE *arq1, *arq2;
  bebe *bb1,*bb2;
  int i,totalM=0,totalF=0;
  float mediaAlturaM=0,mediaPesoM=0,mediaAlturaF=0,mediaPesoF=0;


  arq1 = fopen("dados-bebes.bin","rb");
  assert(arq1);
  arq2 = fopen("dados-bebes.txt","r");
  assert(arq2);

  bb1 = (bebe *) malloc (6 * sizeof(bebe));
  assert(bb1);
  bb2 = (bebe *) malloc (6 * sizeof(bebe));
  assert(bb2);

  for (i=0;i< 6 ;i++){
      fread(&bb1[i], sizeof(bebe),1, arq1);
  }

  fclose(arq1);

  i=0;
  
  while(fscanf(arq2,"%d %d %d %c %f %f %[^\n]s",&bb2[i].dia,&bb2[i].mes,&bb2[i].ano,&bb2[i].sexo,&bb2[i].altura,&bb2[i].peso,bb2[i].nome)!=EOF){
    i++;
  }

  fclose(arq2);

  for (i=0;i<6;i++){
    if (bb1[i].sexo=='m'){
      totalM++;
      mediaPesoM+=bb1[i].peso;
      mediaAlturaM+= bb1[i].altura;
    }
    else{
      totalF++;
      mediaPesoF+=bb1[i].peso;
      mediaAlturaF+= bb1[i].altura;
    }
    if (bb2[i].sexo=='m'){
      totalM++;
      mediaPesoM+=bb2[i].peso;
      mediaAlturaM+= bb2[i].altura;
    }
    else{
      totalF++;
      mediaPesoF+=bb2[i].peso;
      mediaAlturaF+= bb2[i].altura;
    }
  }

  free(bb1);
  free(bb2);

  printf("Dados dos Bebes Homens: \n"); 
  printf("Total: %d\n", totalM); 
  printf("Media da Altura: %.2f metros\n", (float) mediaAlturaM/totalM); 
  printf("Media do Peso: %.2f kg\n", (float) mediaPesoM/totalM); 
  printf("\n");
  printf("Dados dos Bebes Mulheres: \n"); 
  printf("Total: %d\n", totalF); 
  printf("Media da Altura: %.2f metros\n", (float) mediaAlturaF/totalF); 
  printf("Media do Peso: %.2f kg\n", (float) mediaPesoF/totalF); 

 return 0;
}