#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

int num=1000,resto;

while (num <=1999){
++num;
resto=num%11;
if (resto==5){
printf("%d\n", num);
}
}
return 0;
}
