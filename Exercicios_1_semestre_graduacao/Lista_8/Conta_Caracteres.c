#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
char letra;
int freq;
}FQL[26];

void cpc(int,int);

int main(){
  int j=0,parametro=0;

  while(j<=25||parametro<27){
   cpc(j,parametro);
   j++;
   parametro++;
  }

	return 0;
}

void cpc(int j,int p){

  FQL a;
  FILE*arq=fopen("texto.txt","r");
  int x=97+p,count=0,i;
  char c;

  while((c=fgetc(arq))!=EOF){
      c=tolower(c);
      a[j].letra=x;
      if(c==a[j].letra){
        count++;
      }
    }
    a[j].freq=count;
    count=0;
    j++;

  fclose(arq);

  if(p==26){
    for(i=0;i<26;i++){
      printf("%c = %d\n",a[i].letra,a[i].freq);
    }
  }

}
