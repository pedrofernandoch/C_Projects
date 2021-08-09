#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct complexo{ 
    double re; 
    double im;
};
typedef struct complexo tComplexo;

tComplexo soma(tComplexo c1, tComplexo c2); 
tComplexo div1(tComplexo c1, tComplexo c2);
void mult(tComplexo c1, tComplexo c2, tComplexo *c3);
void printComplexo(tComplexo c);

int main(){

  tComplexo x1,x2,x3,res;

  int op;

  scanf("%d",&op);
  while(op!=0){
    switch(op){
      case 1:  //SOMAR
      scanf("%lf %lf",&x1.re,&x1.im);
      scanf("%lf %lf",&x2.re,&x2.im);
      res= soma(x1, x2);
      break;
      case 2:  //DIVIDIR
      scanf("%lf %lf",&x1.re,&x1.im);
      scanf("%lf %lf",&x2.re,&x2.im);
      res= div1(x1, x2);
      break;
      case 3:  //MULTIPLICAR
      scanf("%lf %lf",&x1.re,&x1.im);
      scanf("%lf %lf",&x2.re,&x2.im);
      mult(x1,x2,&x3);
      res = x3;
      break;
      case 4: //IMPRIMIR
      printComplexo(res);
      break;
      }
    scanf("%d",&op);
  }

 return 0;
}
void printComplexo(tComplexo c){
    printf("%.2f", c.re); 
    if (c.im >= 0){ 
        printf("+"); 
    }
    printf("%.2fi\n", c.im);
} 

tComplexo soma(tComplexo x1, tComplexo x2) {
	tComplexo res = {x1.re + x2.re, x1.im + x2.im};
	return res;
}

tComplexo div1(tComplexo x1, tComplexo x2) {
	tComplexo res = {(x1.re*x2.re + x1.im*x2.im) / (x2.re*x2.re + x2.im*x2.im),(x1.im*x2.re - x1.re*x2.im) / (x2.re*x2.re + x2.im*x2.im)};
	return res;
}

void mult(tComplexo x1, tComplexo x2, tComplexo *x3){

   x3->re = ((x1.re*x2.re) - (x1.im*x2.im));
   x3->im = ((x1.re*x2.im)+ (x1.im*x2.re));
}