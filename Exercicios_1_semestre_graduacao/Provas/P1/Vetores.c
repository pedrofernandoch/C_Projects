#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int k;

void maior_elemento(int,int,int[],int[]);
void menor(int,int,int[],int[]);
void intersecao(int,int,int[],int[],int[]);
void imprimi_vetor(int,int[]);

int main(){

  int n1,n2,i,vetor3[MAX];

  scanf("%d",&n1);
  scanf("%d",&n2);

  int vetor1[n1],vetor2[n2];

  for (i=0;i<n1;i++){
    scanf("%d",&vetor1[i]);
  }
  for (i=0;i<n2;i++){
    scanf("%d",&vetor2[i]);
  }

  intersecao(n1,n2,vetor1,vetor2,vetor3);

  imprimi_vetor(n1,vetor3);
  printf("\n");

  menor(n1,n2,vetor1,vetor2);
  printf("\n");

  maior_elemento(n1,n2,vetor1,vetor2);

  return 0;
}

void maior_elemento(int n1, int n2, int vetor1[],int vetor2[]){

  int i,maior=0;

  for (i=0;i<n1;i++){
      if (vetor1[i]>maior){
      maior=vetor1[i];
      }
  }

  for (i=0;i<n2;i++){
      if (vetor2[i]>maior){
        maior=vetor2[i];
      }
  }

  printf("Maior:\n%d",maior);

}

void menor(int n1, int n2, int vetor1[],int vetor2[]){

  int i,menor=10000;

  for (i=0;i<n1;i++){
      if (vetor1[i]<menor){
      menor=vetor1[i];
      }
  }

  for (i=0;i<n2;i++){
      if (vetor2[i]<menor){
        menor=vetor2[i];
      }
  }

  printf("Menor:\n%d",menor);

}

void intersecao(int n1, int n2,int vetor1[], int vetor2[],int vetor3[]){

  int i,j,l=0;

  for (i=0;i<n1;i++){
      for (j=0;j<n2;j++){
        if (vetor1[i]==vetor2[j]){
          vetor3[l]=vetor1[i];
          l++;
        }
      }
  }
  k=l;
}

void imprimi_vetor(int n1,int vetor3[]){

  int i;

  printf("Intersecao:\n");
  for (i=0;i<k;i++){
    printf("%d ",vetor3[i]);

  }
}
