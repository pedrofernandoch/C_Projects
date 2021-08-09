#include <stdio.h>
#include <stdlib.h>


int main()
{
float *vetora;
float *vetorb;
float produto,resultado;
int n,i;

    scanf("%d",&n);
    
     vetora = (float *) malloc(n * sizeof(float));
     vetorb = (float *) malloc(n * sizeof(float));
     
     for (i = 0; i < n; i++){
     scanf("%f",&vetora[i]);
     }
     for (i = 0; i < n; i++){
     scanf("%f",&vetorb[i]);
     }
     for (i = 0; i < n; i++){
        resultado= vetorb[i]*vetora[i];
        produto= produto + resultado;
     }
    printf("%.2f",produto); 
    return 0;
}
