#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n1,n2,soma,sub,mult,mod;
    float divs;
    
    scanf("%d,",&n1);
    scanf("%d",&n2);
    
    soma=n1+n2;
    sub=n1-n2;
    mult=n1*n2;
    divs=(float)n1/n2;
    mod=n1%n2;
    
    printf("A soma dos números dados é : %d\n",soma);
    printf("A subtração dos números dados é : %d\n",sub);
    printf("O multiplicação dos números dados é : %d\n",mult);
    printf("A divisão dos números dados é : %f\n",divs);
    printf("O modulo é = %d",mod);
    return 0;
}