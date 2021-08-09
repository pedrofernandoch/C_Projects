#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

int main()
{
    char palavra[MAX],c,aux[MAX];
    int i,j=0;
    
    scanf("%s",palavra);
    scanf("%s",&c);
    c=tolower(c);
    
    for (i=0;i<strlen(palavra);i++){
        if (tolower(palavra[i])!=c){
            aux[j]=palavra[i];
            j++;
        }
        
    }
    aux[j]='\n';
    aux[j + 1] = '\0';
    printf("%s",aux);

        
    return 0;
}
