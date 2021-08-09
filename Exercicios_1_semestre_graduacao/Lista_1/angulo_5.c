#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

int main(){
    int a,b,c;
    
    scanf("%d",&a);
    scanf("%d",&b);
    c=180-(a+b);
    if ((a+b)>=180){
    printf("%d, %d: erro",a,b);
    }
    else{
        printf("%d, %d: %d",a,b,c);
    }
    getch();
    return 0;
}
