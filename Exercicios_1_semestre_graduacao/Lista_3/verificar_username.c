#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    char username[30];
    int flag=1,i,min=0,max=0,alg=0;
    
    scanf("%s",username);
    
    for (i=0;i<strlen(username);i++){
        if (username[i]<48 || (username[i]>57&&username[i]<65) || (username[i]>90&&username[i]<97) || username[i]>122){
            flag=0;
        }
        if ((username[i]>96)&&(username[i]<123)){
            min=1;
        }
        if ((username[i]>64)&&(username[i]<91)){
            max=1;
        }
        if ((username[i]>47)&&(username[i]<58)){
            alg=1;
        }
    }
    
    if ((flag==0 && min==0) || (flag==0 && max==0) || (flag==0 && alg==0)){
        printf("Username invalido\nPossui caracter especial\nNao possui os tres tipos de caracteres\n");
        return 0;
    }
    if ((flag==0 && min==1 && max==1 && alg==1)){
        printf("Username invalido\nPossui caracter especial\n");
        return 0;
    }
    if ((min==0)||(max==0)||(alg==0)){
        printf("Username invalido\nNao possui os tres tipos de caracteres\n");
        return 0;
    }
    if (flag==1 && alg==1 && min==1 && max==1){
        printf("Username OK\n");
    }
    return 0;
}
