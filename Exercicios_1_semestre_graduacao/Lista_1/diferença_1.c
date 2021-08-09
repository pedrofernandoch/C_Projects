#include <stdio.h>
#include <stdlib.h>

int main(){
    
 int n1,n2,n3,aux;

 scanf("%d",&n1);
 scanf("%d",&n2);
 scanf("%d",&n3);

 if (n1>n2){
aux=n1;
n1=n2;
n2=aux;
 }
if (n2>n3){
aux=n3;
n3=n2;
n2=aux;
} 

 if ((n1<n2)&&(n2<n3)){
 if ((n2-n1)==(n3-n2)){
    printf("resposta: 1");
 }
 else{
    printf("resposta: 0");
 }
 }
return 0;


}
