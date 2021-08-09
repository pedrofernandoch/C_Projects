#include <stdio.h>
int soma(int,int);
int max(int,int);
int executa(int (*pt)(int,int),int,int);

int main()
{
    int a,b;
    int *p1;
    p1=&a;
    scanf("%d",&a);
    scanf("%d",&b);

    int (*p2)(int,int);
    p2=soma;
    int (*pt)(int,int);
    
    pt=soma;
    
    printf("Soma igual = %d\n",pt(a,b));
    
    pt=max;
    
    printf("Max igual = %d\n",pt(a,b));
    
    printf("soma=%d\n",executa(soma,a,b));
    printf("max=%d\n",executa(max,a,b));
    printf("soma=%d",p2(*p1,b));
    
    return 0;
}

int soma(int a, int b){

    return a+b;
    
}

int max(int a, int b){

    return a>b ? a:b;
    
}

int executa(int (*pt)(int,int),int a, int b){
    
    return pt(a,b);
}