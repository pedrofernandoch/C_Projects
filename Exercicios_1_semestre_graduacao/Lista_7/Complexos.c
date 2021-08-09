#include <stdio.h>
#include <stdlib.h>

int main(){

 float x1,x2,i1,i2;
 int op;

 scanf("%f",&x1);
 scanf("%f",&i1);
 scanf("%f",&x2);
 scanf("%f",&i2);
 scanf("%d",&op);

if (op==1){
  printf("%.2f + %.2fi",(x1+x2),(i1+i2));
}
else if (op==2){
  printf("%.2f + %.2fi",(x1-x2),(i1-i2));  
}
else if (op==3){
  printf("%.2f + %.2fi",((x1*x2) - (i1*i2)),((x1*i2)+ (i1*x2))); 
}

  return 0;

}
