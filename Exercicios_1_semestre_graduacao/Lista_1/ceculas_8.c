#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int valor,r,q;
    char x;
    scanf("%d",&valor);
    if (valor<100){
        printf("000 notas de 100.00\n");
    }
    else{
    q=valor/100;
    if (q!=0){
        printf("%03d notas de 100.00\n",q);
    }
    }
    r=valor%100;
    if (r<50){
        printf("000 notas de 50.00\n");
    }
    else{
    if(r!=0)
    q=r/50;
    if (q!=0){
        printf("%03d notas de 50.00\n",q);
    }
    }
    r=r%50;
     if (r<10){
        printf("000 notas de 10.00\n");
    }
    else{
    if(r!=0)
    q=r/10;
    if (q!=0){
        printf("%03d notas de 10.00\n",q);
    }
    }
    r=r%10;
     if (r<5){
        printf("000 notas de 5.00\n");
    }
    else{
    if(r!=0)
    q=r/5;
    if (q!=0){
        printf("%03d notas de 5.00\n",q);
    }
    }
    r=r%5;
     if (r<1){
        printf("000 notas de 1.00\n");
    }
    else{
    if(r!=0)
    q=r/1;
    if (q!=0){
        printf("%03d notas de 1.00\n",q);
    }
    }
	scanf("%c",&x);
    return 0;
}
