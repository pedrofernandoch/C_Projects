#include <stdio.h>
#include <stdlib.h>

void media_aritimetica (float[],int);
void media_ponderada (float[],int[],int,int);
void media_harmonica (float[],int);

int main()
{
    int op,aux=5,i,ponderada[5],d=0;
    float nota[5];
    
    for (i=0;i<5;i++){
        scanf("%f",&nota[i]);    
    }
    
    scanf("%d",&op);
    
    if (op==1){
        media_aritimetica(nota,aux);
    }
    
    if (op==2){      
        for (i=0;i<5;i++){
            scanf("%d",&ponderada[i]);
            d+=ponderada[i];
        }    
        media_ponderada(nota,ponderada,aux,d);
    }
    
    if (op==3){
        media_harmonica(nota,aux);
    }

    return 0;
}

void media_aritimetica (float nota[],int aux){
    
    int i;
    float media=0;
    
    for (i=0;i<5;i++){
        media+=nota[i];    
    }
    media=media/5;
    if (media>=5){
    printf("%.2f\n",media);
    printf("APROVADO");
    }
    else if (media>=3&&media<5){
        printf("%.2f\n",media);
        printf("REC");
    }
    else{
        printf("%f\n",media);
        printf("REPROVADO");
    }
    

}

void media_ponderada (float nota[],int ponderada[], int aux, int d){
    
    int i;
    float media=0;
    
    for (i=0;i<5;i++){
        media+=nota[i]*ponderada[i];    
    }
    media=media/d;
    if (media>=5){
        printf("%.2f\n",media);
        printf("APROVADO");
    }
    else if (media>=3&&media<5){
        printf("%.2f\n",media);
        printf("REC");
    }
    else{
        printf("%.2f\n",media);
        printf("REPROVADO");
    }

}

void media_harmonica (float nota[],int aux){
    
    int i;
    float soma=0,media;

    for (i=0;i<5;i++){
      soma+= 1/nota[i];
    }
    media= 5/soma;

    if (media>=5){
        printf("%.2f\n",media);
        printf("APROVADO");
    }
    else if (media>=3&&media<5){
        printf("%.2f\n",media);
        printf("REC");
    }
    else{
        printf("%.2f\n",media);
        printf("REPROVADO");
    }

}