//Nome: Pedro Fernando Christofoletti dos Santos
//NUSP: 11218560

#include <stdio.h>
#include <stdlib.h>
#include "complex_sparse.h"

int main(void) {
  char op;
  COMPLEX_SPARSE *sparse1,*sparse2,*result_sparse;
  
  scanf("%c",&op);
  complex_sparse_read(&sparse1, &sparse2);
  if((int)op==65){ //SUM
    result_sparse = complex_sparse_sum(sparse1, sparse2);
  }else if((int)op==77){ //PRODUCT
    result_sparse = complex_sparse_create(sparse1->nrows, sparse2->ncols, 0);
    complex_sparse_product(sparse1, sparse2, result_sparse);
  }else printf("Invalid Opeeration\n");

  complex_sparse_print(result_sparse);

  complex_sparse_free(sparse1);
  complex_sparse_free(sparse2);
  if((int)op==77)complex_sparse_free(result_sparse);

  return 0;
}