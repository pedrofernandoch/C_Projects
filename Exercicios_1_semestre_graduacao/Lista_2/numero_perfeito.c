#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,j,soma=0;

    scanf("%d",&n);

    for ( i=1; i< n; i++)
    {
        soma=0;
        for (j=1; j < i; j++)
        {
            if ((i%j)==0){
            soma = soma + j;
            }
        }
             if (i == soma){
             printf("%d\n",i);
             }

    }
return 0;
}


