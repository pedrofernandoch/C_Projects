#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 12

int main(){

  int n,i,j,soma=0,tamChave;
  float p=0;

  scanf("%d",&n);

  char palavras[n][MAX],chave[MAX];

  for(i=0;i<n;i++){
    scanf("%s",palavras[i]);
  } 

  scanf("%s",chave);

  tamChave=strlen(chave);

   for (i=0;i<n;i++){
        if (tamChave==strlen(palavras[i])){
            for (j=0;j<tamChave;j++){
                if (chave[j]==palavras[i][j]){        
                    soma++;
                }
            }
            p=(float)soma/tamChave;
            if (p>=0.7){
                printf("%s\n",palavras[i]);
            } 
        }
      soma=0;
  }

  return 0;
}