#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calcula_vetor(float *, float *, float, float);

int main(){
    
    float magnitude,angulo,x1,x2=0,y1=0,y2;
    
    scanf("%f",&magnitude);
    scanf("%f",&angulo);
    
    calcula_vetor(&x1, &y2, magnitude, angulo);
    
    printf("%.2f %.2f\n",x1,y1);
    printf("%.2f %.2f",x2,y2);
    
    return 0;
}
void calcula_vetor(float *x1, float *y2, float magnitude, float angulo){

    *x1=magnitude*cos(angulo);
    *y2=magnitude*sin(angulo);

}