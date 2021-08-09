#include <stdio.h>
#include <math.h>

int main()
{
    double massa, altura, imc;
    
    scanf("%lf %lf", &altura, &massa);
    imc = massa/pow(altura,2);
    printf("%lf", imc);
    
    return 0;
}
