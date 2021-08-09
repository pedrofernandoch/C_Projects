#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int soma(int);
int fatorial(int);
int fibonacci(int);
int resultado(int, int (*)(int));
//################################# Main ###################################
int main(){

int x;
char op;
int (*psoma)(int),(*pfatorial)(int),(*pfibonacci)(int);

psoma=soma;
pfatorial=fatorial;
pfibonacci=fibonacci;

scanf("%d %c",&x,&op);

if (op=='+'){
  //printf("%d",resultado(x,soma));
  printf("%d",psoma(x));
}
if (op=='!'){
  //printf("%d",resultado(x,fatorial));
  printf("%d",pfatorial(x));
}
if (op=='f'){
  //printf("%d",resultado(x,fibonacci));
  printf("%d",pfibonacci(x));
}

    return 0;
}
//######################### Soma #############################
int soma(int a){
  if (a==1){
    return a;
  }
  return a+soma(a-1);
}
//######################### Fatorial #########################
int fatorial(int a){
  if (a==1){
        return a;
    }
    return a*fatorial(a-1);
}
//######################### Fibonacci ########################
int fibonacci(int a){
  if(a==1 || a==2)
       return 1;
   else
       return fibonacci(a-1) + fibonacci(a-2); 
}
//######################### Resultado ########################
int resultado(int a, int (*p)(int)){

  return p(a);

}