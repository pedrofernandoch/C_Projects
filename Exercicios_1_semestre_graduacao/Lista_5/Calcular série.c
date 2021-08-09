#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10000
int k;

void primes(int *, int);
void calculateSeries(int[], double *);

int main(void) {
  
  int n,vetor[MAX];
  double series=0;
  
  scanf("%d",&n);

  primes(vetor,n);
  calculateSeries(vetor, &series);

  printf("%lf",series);

  return 0;
}

void primes(int *vetor, int n){

  int i,j,flag;
  k=0;

  for (i=2;i<n;i++){
    flag = 0;
    for (j=2;j<i;j++){
      if (i%j==0){
        flag = 1;
        break;
      }
    }
    if(flag == 0){
      vetor[k] = i;
      k++;
    }
  }

}

void calculateSeries(int vetor[], double *series){
      
    int i;

    for (i=0;i<k;i++){
        if (i%2==0){
          *series+=(double)1/vetor[i];
        }
        else{
          *series-=(double)1/vetor[i];
        }
    }

}