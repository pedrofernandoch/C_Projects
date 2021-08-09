#include <stdio.h>
int fatIter(int);
int fatRec(int);
int executa(int (*pt)(int),int);

int main()
{
    int n;
    
    scanf("%d",&n);
    printf("Iter: !%d = %d\n",n,executa(fatIter,n));
    printf("Rec: !%d = %d",n,executa(fatRec,n));
    
    return 0;
}

int fatIter(int n){
    
    int fat=1;
    
    while(n>1){
    fat=fat*n;
    n--;
    }
    
    return fat;
}

int fatRec(int a){
    
    if (a==1){
        return a;
    }
    return a*fatRec(a-1);
    
}

int executa(int (*pt)(int),int a){
    
    return pt(a);
}