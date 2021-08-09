#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
    char matriz[3][3];
    int i,j,count=0;
    
//LENDO MATRIZ    
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            scanf("%s",&matriz[i][j]);
        }
    }
    
//X GANHOU HORIZONTAL    
    for (i=0;i<3;i++){
            j=0;
            if (matriz[i][j]=='x' && matriz[i][j+1]=='x' && matriz[i][j+2]=='x'){
                printf("x ganhou");
                return 0;
            }
    }
    
//X GANHOU VERTICAL    
    for (j=0;j<3;j++){
            i=0;
            if (matriz[i][j]=='x' && matriz[i+1][j]=='x' && matriz[i+2][j]=='x'){
                printf("x ganhou");
                return 0;
            }
    }
    
//X GANHOU DIAGONAL    
    if ((matriz[0][0]=='x' && matriz[1][1]=='x' && matriz[2][2]=='x') || (matriz[0][2]=='x' && matriz[1][1]=='x' && matriz[2][0]=='x')){
                printf("x ganhou");
                return 0;
    }
    
//O GANHOU HORIZONTAL    
    for (i=0;i<3;i++){
            j=0;
            if (matriz[i][j]=='o' && matriz[i][j+1]=='o' && matriz[i][j+2]=='o'){
                printf("o ganhou");
                return 0;
            }
    }
    
//O GANHOU VERTICAL    
    for (j=0;j<3;j++){
            i=0;
            if (matriz[i][j]=='o' && matriz[i+1][j]=='o' && matriz[i+2][j]=='o'){
                printf("o ganhou");
                return 0;
            }
    }
    
//O GANHOU DIAGONAL    
    if ((matriz[0][0]=='o' && matriz[1][1]=='o' && matriz[2][2]=='o') || (matriz[0][2]=='o' && matriz[1][1]=='o' && matriz[2][0]=='o')){
                printf("o ganhou");
                return 0;
    }

//EMPATE && EM JOGO
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            if (matriz[i][j]=='x' || matriz[i][j]=='o'){
                count++;
            }
        }
    }

    if (count==9){
        printf("empate");
    }
    else{
        printf("em jogo");
    }

    return 0;
}