#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calcula_media(int[],int);
void desvio(float,int[],int);

int main()
{
    int valor[10],i,n=10;
    float media;
    
    for (i=0;i<10;i++){
        scanf("%d",&valor[i]);
    }
    media=calcula_media(valor,n);
    desvio(media,valor,n);
 
    return 0;
}

float  calcula_media (int valor[],int n){
    
    int i,soma=0;
    float media;
    
    for (i=0;i<n;i++){
        soma+=valor[i]; 
    }
    media = (float)soma/10;
    
    return media;
}

void desvio(float media,int valor[],int n){
    
    int i;
    float desvio,soma=0,aux;
    
    for (i=0;i<n;i++){
        aux= valor[i] - media;
        if (aux<0){
            aux=aux*-1;
        }
        soma+=aux;
    }
    desvio=soma/n;
    
    printf("%.2f",desvio);
}