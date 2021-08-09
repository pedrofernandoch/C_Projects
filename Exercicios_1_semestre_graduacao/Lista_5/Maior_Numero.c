#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void maior(int *, int *, int n);
void imprime(int *, int n);  

int main(void) {
  
  int n,fs[9],i;
  
  scanf("%d",&n);
  
  int num[n];
  char aux[n];

  scanf("%s",aux);

  for (i=0;i<n;i++){
  num[i]=aux[i] - '0';
  }

  for (i=0;i<9;i++){
  scanf("%d",&fs[i]);
  }

  maior(num,fs,n);
  imprime(num,n);

  return 0;
}

void maior(int *numero, int*fs, int n){

  int i;

  for (i=0;i<n;i++){
      if (numero[i]<fs[numero[i]-1])
          numero[i]=fs[numero[i]-1];
  } 

}

void imprime (int *numero, int n){  

  int i;

  for (i=0;i<n;i++){
      printf("%d",numero[i]);
  }

}
