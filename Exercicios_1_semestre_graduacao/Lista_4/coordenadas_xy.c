#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
    float magnitude,angulo,x1,x2=0,y1=0,y2;
    
    scanf("%f",&magnitude);
    scanf("%f",&angulo);
    
    x1=magnitude*cos(angulo);
    y2=magnitude*sin(angulo);
    
    printf("%.2f %.2f\n",x1,y1);
    printf("%.2f %.2f",x2,y2);
    
    return 0;
}