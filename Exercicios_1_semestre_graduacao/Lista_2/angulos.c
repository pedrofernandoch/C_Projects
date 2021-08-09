#include <stdio.h>
#include <stdlib.h>

int main(){

int a1,a2,a3;

scanf("%d\n",&a1);
scanf("%d\n",&a2);
scanf("%d",&a3);

if ((a1+a2+a3)>180||(a1+a2+a3)!=180){
    printf ("Valores nao formam um triangulo\n");
}
else if ((a1==90) || (a2==90) || (a3==90)){
printf ("Triangulo retangulo");	
}
else if ((a1>90) || (a2>90) || (a3>90)){
    printf("Triangulo obtuso");
}
else if ((a1<90) && (a2<90) && (a3<90)){
    printf("Triangulo agudo");
}
return 0;
}
