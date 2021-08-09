#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
  
    int matriz[5][5],i,j,jogador,pontos=0;
  
    scanf("%d",&jogador);
  
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            scanf("%d",&matriz[i][j]);
        }
    }
 
    for (i=4;i>=2;i--){
        for (j=0;j<5;j++){
            if (matriz[i][j]==jogador && matriz[i-1][j]==jogador && matriz[i-2][j]==0){
                pontos+=50;
            }
            if (matriz[i][j] == jogador && matriz[i-1][j] == 0 && matriz[i-2][j]==0){
                pontos+=+10;
            }
        }
    }
    
    printf("%d",pontos);
  

    return 0;
} 