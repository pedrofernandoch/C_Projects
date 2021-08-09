#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

int n1,n2,n3,resto,aux,resto2;

while(scanf("%d %d %d", &n1, &n2, &n3) == 3){ 
if (n1>n2){
aux=n1;
n1=n2;
n2=aux;
}
if (n2>n3){
aux=n2;
n2=n3;
n3=aux;
}
resto=n2%n1;
while(resto!=0) {
 n2 = n1;
 n1 = resto;
resto = n2%n1;         
}
resto2=n3%n1;
while(resto2!=0) {
 n3 = n1;
 n1 = resto2;
resto2 = n3%n1;         
}
printf("%d\n",n1);
}
return 0;
}

