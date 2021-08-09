#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n1,n2,i,count=0;
   int vetor[10];
   
    scanf("%d",&n1);
    scanf("%d",&n2);

    for (i=0;i<10;i++){
        scanf("%d",&vetor[i]);
    }
    
    for (i=0;i<10;i++){
        if ((vetor[i]>=n1)&&(vetor[i]<=n2)){
            count++;
        }
    }
    printf("%d",count);
    
    return 0;
}
