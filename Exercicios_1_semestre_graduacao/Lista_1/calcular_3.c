#include <stdio.h>
#include <stdlib.h>
int main()
{
    float a,b,r;
    
    scanf("%f",&a);
    scanf("%f",&b);
    
    if ((a+b)<10){
        r=(a+b)*(a+b);
        printf("%.2f, %.2f: %.2f",a,b,r);
    }
    else {
        r=((a+b)*(a+b))/(a+b);
        printf("%.2f, %.2f: %.2f",a,b,r);
    }
    
    return 0;
}
