#include <stdio.h>
#include <stdlib.h>
int main()
{
    float temp;
    
    scanf("%f",&temp);
    
    if (temp<0){
        printf("Tempo congelante.");
    }
    if ((temp>=0)&&(temp<=10)){
        printf("Tempo muito frio.");
    }
    if ((temp>=11)&&(temp<=23)){
        printf("Tempo frio.");
    }
    if ((temp>=24)&&(temp<=30)){
        printf("Tempo normal.");
    }
    if ((temp>=31)&&(temp<=40)){
        printf("Tempo quente.");
    }
    if (temp>41){
        printf("Tempo muito quente.");
    }

    return 0;
}
