#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void esparsa();
void identidade();
void simetrica();

int main(){
    
    int n,op,i,j;
    
    scanf("%d",&n);
    
    int matriz[n][n];
    
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            scanf("%d",&matriz[i][j]);
        }
    }
    
    scanf("%d",&op);
    
    if (op==1){
        esparsa(n,matriz);
    }
    if (op==2){
        identidade(n,matriz);
    }
    if (op==3){
        simetrica(n,matriz);
    }

    return 0;
}

void esparsa(int n,int matriz[][n]){
    
    int zero=0,naoZero=0,i,j;
    
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if(matriz[i][j]==0){
                zero++;
            }
            else{
                naoZero++;
            }
        }
    }
    if (zero>(pow(n,2)/2)){
       printf("SIM"); 
    }
    else{
     printf("NAO");   
    }
}

void identidade(int n,int matriz[][n]){
    
    int lin,col,flag=1;
    
    for (lin=0;lin<n;lin++){
        for (col=0;col<n;col++){
            if ((lin != col && matriz[lin][col] != 0) || (lin==col && matriz[lin][col]!=1)){
                printf("NAO");
                flag=0;
                break;
            }
        }
    }
    
    if (flag==1){
        printf("SIM");
    }
}

void simetrica(int n,int matriz[][n]){
    
    int matrizTransposta[n][n],i,j,igual=1;
    
    for (j=0;j<n;j++){
        for(i=0;i<n;i++){
       matrizTransposta[j][i]=matriz[i][j];
        }
    }
     
    for (j=0;j<n;j++){
        for(i=0;i<n;i++){
            if (matriz[i][j] != matrizTransposta[i][j]){
                igual=0;
            }
        }
    }
    if (igual==1){
        printf("SIM");
    }
    else{
        printf("NAO");
    }
    
}