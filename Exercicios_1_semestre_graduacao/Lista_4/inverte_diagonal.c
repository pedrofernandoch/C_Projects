#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
    int matriz[5][5],i,j,aux;
    
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            scanf("%d",&matriz[i][j]);
        }
    } 
    for (i=0; i<5; i++){
        aux = matriz[i][(int)sqrt(pow(5-(i+1),2))];
        matriz[i][(int)sqrt(pow(5-(i+1),2))] = matriz[i][i];
        matriz[i][i] = aux;
    }
  
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){            
          printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }

    
    return 0;
}