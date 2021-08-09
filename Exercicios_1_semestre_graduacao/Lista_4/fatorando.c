#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,d=2,count=0;
    
    scanf("%d",&n);

    while (n!=1){
        if (n%d==0){
          n/=d; 
          count++;
        }
        if (n%d!=0){
            if (count==0){
                d++;
            }
            else{
            printf("%d ",d);
            printf("%d",count);
            printf("\n");
            count=0;
            d++;
            }
        }
    }

    return 0;
}