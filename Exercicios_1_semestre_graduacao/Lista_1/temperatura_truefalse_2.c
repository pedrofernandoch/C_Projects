#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b;
    
    scanf("%d",&a);
    scanf("%d",&b);
    
    if ((a<0&&b>100)||(b<0&&a>100)){
        printf("%d, %d: 1",a,b);
    }
    else {
        printf("%d, %d: 0",a,b);
    }
    
    return 0;
}
