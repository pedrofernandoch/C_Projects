#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

int main()
{
    char frase[MAX],fraseInversa[MAX],aux[MAX];
    int i=0,j=0;

    fgets(frase,MAX,stdin);

    while(frase[i]!='\0'){
        if(!isspace(frase[i])){
            aux[j]=toupper(frase[i]);
            j++;
        }
        i++;
    }

    aux[j]='\0';

    for(i=0;i<j;i++){
        fraseInversa[i]=aux[(j-1)-i];
    }

    fraseInversa[j] = '\0';

    if(strcmp(fraseInversa,aux)==0){
       printf("SIM") ;
    }
    else{
        printf("NAO");
    }

    return 0;
}
