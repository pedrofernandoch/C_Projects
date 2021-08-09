#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000

int main(void) {
  
int i=0,qtdPalavra=1,count=0,j;
char frase[MAX];
char letra;
float porcentagem;
  
  scanf("%c\n",&letra);
  scanf("%[^\n]s",frase);

  letra=tolower(letra);
  for (i=0;i<strlen(frase);i++){
    frase[i]=tolower(frase[i]);
  }

  for (i=0;i<strlen(frase);i++){
      if (frase[i]==' '){
        qtdPalavra++;
      }
  }

i=0;
for (j=0;j<qtdPalavra;j++){
  while(frase[i]!='\0'){
        if (frase[i]==letra){
        count++;
        }
        i++;
  }
}

porcentagem = (float) (count*100) / qtdPalavra;

printf("%.1f",porcentagem);

   return 0;
}

