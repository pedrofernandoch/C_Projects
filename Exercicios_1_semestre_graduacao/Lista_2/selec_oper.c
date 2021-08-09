#include <stdio.h>
#include <stdlib.h>

int main(){

int n1,n2,op;

scanf("%d",&n1);
scanf("%d\n",&n2);
scanf("%d",&op);

if (op==1){
    printf("%d",n1+n2);
}
else if (op==2){
    printf("%d",n1-n2);
}
else if (op==3){
    printf("%d",n1*n2);
}
else{
    printf("opcao invalida");
}
    
    
return 0;
}
