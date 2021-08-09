#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i,n,fat=6,e=2,infat=3;
    float x,soma;
    
    scanf("%f %d",&x,&n);
    soma=x;
    
    for (i=1;i<n;i++){
        if ((i%2)==0){
            soma+= pow(x,e)/fat;
        }
        else{
            soma-= pow(x,e)/fat;
        }
        e=e+2;
        fat=fat*(infat+1)*(infat+2);
        infat=infat+2;
    }
    printf("%f",soma);
    
    return 0;
}