#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 200
 
int main(){
    
    char matrizMenor[30][MAX];
    char matrizMaior[30][MAX];
    char frase[MAX];
    char palavra[MAX];
    int tamMaior = 0;
    int tamMenor = 10000;
    int contMaior=0,contMenor=0;
    int i = 0;
    
    fgets(frase,MAX,stdin);

    while(i < strlen(frase)){
        
        int tam = 0;
        while(!isspace(frase[i])){
            palavra[tam] = frase[i];
            tam++;
            i++;
        }
        palavra[tam] = '\0';
        
        
        if (tam>tamMaior){
            tamMaior=tam;
            contMaior=1;
            strcpy(matrizMaior[0],palavra);
        }
        else if (tam==tamMaior){
            strcpy(matrizMaior[contMaior],palavra);
            contMaior++;
        }
        
        
        if (tam<tamMenor){
            tamMenor=tam;
            contMenor=1;
            strcpy(matrizMenor[0],palavra);
        }
        else if (tam==tamMenor){
            strcpy(matrizMenor[contMenor],palavra);
            contMenor++;
        }
        
        i++;
    }
    
    for (i=0;i<contMenor;i++){
        printf("%s ",matrizMenor[i]);
    }
    printf("\n");
    for (i=0;i<contMaior;i++){
        printf("%s ",matrizMaior[i]);
    }
    
    return 0;
}
