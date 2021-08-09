#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
    int matriz[3][3],i,j,determinante;
    
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            scanf("%d",&matriz[i][j]);
        }
    }
    
    determinante=(matriz[0][0]*matriz[1][1]*matriz[2][2]) + (matriz[0][1]*matriz[1][2]*matriz[2][0]) + (matriz[0][2]*matriz[1][0]*matriz[2][1]);
    determinante= determinante - (matriz[0][2]*matriz[1][1]*matriz[2][0]) - (matriz[0][0]*matriz[1][2]*matriz[2][1]) - (matriz[0][1]*matriz[1][0]*matriz[2][2]);
    
    printf("%d",determinante);
    
    return 0;
}