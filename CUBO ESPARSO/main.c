// Nome: Pedro Fernando Christofoletti dos Santos
// NUSP: 11218560

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "complex_sparse.h"

int main(void) {
  
  COMPLEX_SPARSE *mycube;
  float d1,d2,d3;
  int error;
  char *op;
  int constant = -1;

  op = (char *) calloc(7,sizeof(char));
  scanf("%f",&d1);
  scanf("%f",&d2);
  scanf("%f",&d3);

  mycube = complex_sparse_create(d1, d2, d3, constant);

  while(scanf("%s",op)!=EOF){
    if (strcmp(op,"put")==0){
      float x,y,z;
      double valor;
      scanf("%f %f %f %lf",&x,&y,&z,&valor);
      complex_sparse_put(mycube, x, y, z, valor);
    }
    else if (strcmp(op,"get")==0){ 
      float x,y,z;
      scanf("%f %f %f",&x,&y,&z);
      printf("%lf\n",complex_sparse_get(mycube, x, y, z, &error));
    }
    else if (strcmp(op,"remove")==0){
      float x,y,z;
      scanf("%f %f %f",&x,&y,&z);
      complex_sparse_remove(mycube,x, y, z);
    }
    else printf("Invalid operation\n");
  }

  complex_sparse_free(mycube);
  
  return 0;
}