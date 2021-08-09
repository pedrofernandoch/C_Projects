#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){

    int i,aux,x=0,j,tamP,tamS;
    char palavra[50],sub[30];

    scanf("%s",palavra);
    scanf("%s",sub);

    tamP = strlen(palavra);
    tamS = strlen(sub);

    for (i=0;i<tamP;i++){
        if (sub[0]==palavra[i]){
            aux=i;
            for(j=0;j<tamS;j++){
                if(sub[j]==palavra[aux]){
					x++;
				}
	        	aux++;
			}
        }
        if (x==tamS){
	        printf("A frase contem a substring %s\n",sub);
	        return 0;
	    }
    }

    if (x!=tamS){
        printf("A frase nao contem a substring %s\n",sub);
	}

    return 0;

}
