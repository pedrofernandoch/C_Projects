#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 200

void particionar(char *string, char matriz[][MAX]);
void imprimir(char *string, char matriz[][MAX]);
void ordenar(char *string, char matriz[][MAX]);

int main(void) {

char frase[MAX], matriz[MAX][MAX];
int op;

fgets(frase,MAX,stdin);
scanf("%d",&op);

particionar(frase,matriz);

if (op==1){
    imprimir(frase, matriz);
}
else{
  ordenar(frase,matriz);
  imprimir(frase, matriz);
}

  return 0;
}

void particionar(char *frase, char matriz[][MAX]){

  int tam,i,count=1,j=0,k=0;

  tam=strlen(frase);

for (i=0;i<tam;i++){
    if (frase[i]==' '){
        count++;
    }
}

for (i=0;i<count;i++){
    while(frase[k]!=' '){
      matriz[i][j]=frase[k];
      j++;
      k++;
    }
    matriz[i][j]='\0';
    j=0;
    k++;
}

}

void ordenar(char *frase, char matriz[][MAX]){

  int tam,i=0,count=1,j=0;
  char aux[MAX];

  tam=strlen(frase);

  for (i=0;i<tam;i++){
      if (frase[i]==' '){
          count++;
      }
  }

for (i=0;i<count;i++){
    for (j=0;j<strlen(matriz[i]);j++){
        matriz[i][j]= tolower(matriz[i][j]);
    }
}

for (i = 1; i < count-1; i++) {
   for (j = 1; j < count-1; j++) {
      if (strncmp(matriz[j - 1], matriz[j], 4) > 0) {
         strcpy(aux, matriz[j - 1]);
         strcpy(matriz[j - 1], matriz[j]);
         strcpy(matriz[j], aux);
      }
   }
}

}

void imprimir(char *frase, char matriz[][MAX]){

  int tam,i,count=1;

  tam=strlen(frase);

  for (i=0;i<tam;i++){
      if (frase[i]==' '){
          count++;
      }
  }

  for (i=0;i<count-1;i++){
    printf("%s\n",matriz[i]);
  }
  printf("%s",matriz[i]);
  }


