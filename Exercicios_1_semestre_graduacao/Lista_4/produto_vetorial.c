#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
    int matriz[2][3],i=0,j,k,matrizAUX[3][3];
    
    for (j=0;j<3;j++){
        matrizAUX[i][j]=1;
    }
    
    for (i=0;i<2;i++){
        for (j=0;j<3;j++){
            scanf("%d",&matriz[i][j]);
            matrizAUX[i+1][j]=matriz[i][j];
        }
    }
    
    i=(matrizAUX[0][0]*matrizAUX[1][1]*matrizAUX[2][2]) - (matrizAUX[0][0]*matrizAUX[1][2]*matrizAUX[2][1]);
    j=(matrizAUX[0][1]*matrizAUX[1][2]*matrizAUX[2][0]) - (matrizAUX[0][1]*matrizAUX[1][0]*matrizAUX[2][2]);
    k=(matrizAUX[0][2]*matrizAUX[1][0]*matrizAUX[2][1]) - (matrizAUX[0][2]*matrizAUX[1][1]*matrizAUX[2][0]);
     
    printf("%d %d %d",i,j,k);
    return 0;
}