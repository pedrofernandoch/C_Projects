#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int vet[25],aux[5] = {0,0,0,0,0},i,maior=0,aux1;

    for (i=0;i<25;i++){
      scanf("%d",&vet[i]);
    }

    for (i=0;i<25;i++){
      if (vet[i]==0)
      aux[0]+=1;
      else if (vet[i]==1)
      aux[1]+=1;
      else if (vet[i]==2)
      aux[2]+=1;
      else if (vet[i]==3)
      aux[3]+=1;
      else if (vet[i]==4)
      aux[4]+=1;
    }

  for (i=0;i<5;i++){
    if (maior<aux[i]){
    maior=aux[i];
    aux1=i;
    }
  }

    printf("0: |");
    for (i=0;i<aux[0];i++){
      printf("#");
    }
    printf("\n");
    printf("1: |");
    for (i=0;i<aux[1];i++){
      printf("#");
    }
    printf("\n");
    printf("2: |");
    for (i=0;i<aux[2];i++){
      printf("#");
    }
    printf("\n");
    printf("3: |");
    for (i=0;i<aux[3];i++){
      printf("#");
    }
    printf("\n");
    printf("4: |");
    for (i=0;i<aux[4];i++){
      printf("#");
    }
    printf("\n");

  for (i=0;i<25;i++){
    if (vet[i]==aux1)
      printf("%d\n",i);
  }

 return 0;
}

