#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double fat(int);
long double soma_parcela(long double,int);
 
int main()
{
    
    int n;
    long double x;
    
    scanf("%Lf",&x);
    scanf("%d",&n);
   
    printf("%.6Lf",soma_parcela(x,n));

    return 0;
}

long double fat (int d){
 int i;
 long double f=1;
 for(i=d;i>1;i--){
 f=f*i;
 }
 return f;
}

long double soma_parcela(long double x, int n){
    
    int e=3,d=3,i;
    double soma;
    soma=x;
    
    for (i=0;i<n;i++){
        if ((i%2)==0){
            soma-= (pow(x,e))/fat(d);
        }
        else{
            soma+= (pow(x,e))/fat(d);
        }
        e+=2;
        d+=2;
    }
    return soma;
}