#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int main(){

    int i;
    char frase[MAX];
    
    scanf("%[^\n]s",frase);
    
    for (i=0;i<strlen(frase);i++){
        if (frase[i]=='a'|| frase[i]=='A'|| frase[i]=='e'|| frase[i]=='E'|| frase[i]=='i'|| frase[i]=='I'|| frase[i]=='o'|| frase[i]=='O'|| frase[i]=='u'|| frase[i]=='U'){
            frase[i]='*';
        }
    }
    
    for (i=0;i<strlen(frase);i++){
        printf("%c",frase[i]);
    }
    
    return 0;

}
