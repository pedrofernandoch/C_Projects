//Nome: Pedro Fernando Christofoletti dos Santos
//NUSP: 11218560

#include <stdlib.h>
#include <stdio.h>
#include "complex_sparse.h"

//=================================================================================//
//                                    CREATE                                       //
//=================================================================================//
COMPLEX_SPARSE *complex_sparse_create(int nrows, int ncols, double constant) {

	COMPLEX_SPARSE *sparse = (COMPLEX_SPARSE *) malloc(sizeof(COMPLEX_SPARSE));
	sparse->nrows = nrows;
	sparse->ncols = ncols;
	sparse->constant = constant;

	// malloc for indices
	sparse->row_index = (COMPLEX_SPARSE_ELEM **) calloc(nrows, sizeof(COMPLEX_SPARSE_ELEM *));
	sparse->col_index = (COMPLEX_SPARSE_ELEM **) calloc(ncols, sizeof(COMPLEX_SPARSE_ELEM *));

	return sparse;
}

//=================================================================================//
//                                      GET                                        //
//=================================================================================//
double __complex_sparse_get(COMPLEX_SPARSE *sparse, int row, int col, int *error) {
	if (!sparse) {
		*error = INVALID_COMPLEX_SPARSE;
		return -1;
	}
	if (row < 0 || col < 0 || row >= sparse->nrows || col >= sparse->ncols) {
		*error = INVALID_POS;
		return -1;
	}

	COMPLEX_SPARSE_ELEM **rp = &sparse->row_index[row];
	COMPLEX_SPARSE_ELEM **cp = &sparse->col_index[col];

	while (*rp && ((*rp)->col < col)) rp = &(*rp)->right;
	while (*cp && ((*cp)->row < row)) cp = &(*cp)->bottom;

	if (*rp && *cp && (*rp)->col == col && (*cp)->row == row) {
		*error = SUCCESS;
		return (*rp)->elem;
	}

	*error = NOT_FOUND;
	return sparse->constant;
}

//=================================================================================//
//                                      PUT                                        //
//=================================================================================//
int __complex_sparse_put(COMPLEX_SPARSE *sparse, int row, int col, double elem) {

	if (!sparse) return INVALID_COMPLEX_SPARSE;
	if (row < 0 || col < 0 || row >= sparse->nrows || col >= sparse->ncols) return INVALID_POS;

	COMPLEX_SPARSE_ELEM **rp = &sparse->row_index[row];
	COMPLEX_SPARSE_ELEM **cp = &sparse->col_index[col];

	while (*rp && ((*rp)->col < col)) rp = &(*rp)->right;
	while (*cp && ((*cp)->row < row)) cp = &(*cp)->bottom;

	if (*rp && *cp && (*rp)->col == col && (*cp)->row == row) {
		(*rp)->elem = elem;
	} else {
		COMPLEX_SPARSE_ELEM *new = (COMPLEX_SPARSE_ELEM *) malloc(sizeof(COMPLEX_SPARSE_ELEM));
		new->row = row;
		new->col = col;
		new->elem = elem;
		new->right = *rp;
		new->bottom = *cp;
		*rp = *cp = new;
	}

	return SUCCESS;
}

//=================================================================================//
//                                     READ                                        //
//=================================================================================//
void complex_sparse_read(COMPLEX_SPARSE **sparse1, COMPLEX_SPARSE **sparse2){

  int flag,n_rows,n_cols,x=0;
  int row,col,value;

  scanf("%d %d %d",&flag,&n_rows,&n_cols);
  *sparse1 = complex_sparse_create(n_rows, n_cols, 0);
  while(1){
    scanf("%d",&row);
    if(row==-1)break;
      scanf("%d %d",&col,&value);
      __complex_sparse_put(*sparse1, row, col, value);
  }
  scanf("%d %d",&n_rows,&n_cols);
  *sparse2 = complex_sparse_create(n_rows, n_cols, 0);
  while(scanf("%d",&row)!=EOF){
    //x++;
    //scanf("%d",&row);
    scanf("%d %d",&col,&value);
    __complex_sparse_put(*sparse2, row, col, value);
  } 

}

//=================================================================================//
//                                      SUM                                        //
//=================================================================================//
COMPLEX_SPARSE* complex_sparse_sum(COMPLEX_SPARSE *sparse1, COMPLEX_SPARSE *sparse2){

  if (!sparse1 || !sparse2) return NULL;

  int i=0,error;
  double elem;
  COMPLEX_SPARSE *result_sparse = sparse1;
  COMPLEX_SPARSE_ELEM **rp2 = &sparse2->row_index[i];
  
  if(!*rp2){
      while(*rp2==NULL && (i < sparse2->nrows)){
        i++;
        rp2 = &sparse2->row_index[i];
      }
    }
  while(*rp2 && ((*rp2)->row < sparse2->nrows)){
    while (*rp2 && ((*rp2)->col < sparse2->ncols)){
      elem = (*rp2)->elem + __complex_sparse_get(result_sparse, i, (*rp2)->col, &error);
	if(elem != result_sparse->constant || elem != 0)__complex_sparse_put(result_sparse, i, (*rp2)->col, elem);
      rp2 = &(*rp2)->right;
    }
    i++;
    rp2 = &sparse2->row_index[i];
    if(!*rp2){
      while(*rp2==NULL && (i < sparse2->nrows)){
        i++;
        rp2 = &sparse2->row_index[i];
      }
    }
  }

	return result_sparse;
}

//=================================================================================//
//                                    PRODUCT                                      //
//=================================================================================//
int complex_sparse_product(COMPLEX_SPARSE *sparse1, COMPLEX_SPARSE *sparse2, COMPLEX_SPARSE *result_sparse){

  if (!sparse1 || !sparse2 || !result_sparse) return INVALID_COMPLEX_SPARSE;

  int i=0,j=0,error;
  double elem=0;
  COMPLEX_SPARSE_ELEM *paux;

  for(i=0;i<result_sparse->nrows;i++){
    for(j=0;j<result_sparse->ncols;j++){
      elem=0;
      paux = sparse2->col_index[j];
      while(paux){
        elem += paux->elem * __complex_sparse_get(sparse1,i,paux->row,&error);
        paux = paux->bottom;
      }
      if (elem!=0){
        __complex_sparse_put(result_sparse, i, j, elem);
      }
    }
  }

  return SUCCESS;
}

//=================================================================================//
//                                     PRINT                                       //
//=================================================================================//
int complex_sparse_print(COMPLEX_SPARSE* sparse){

  if (!sparse) return INVALID_COMPLEX_SPARSE;

  int i,j;
  COMPLEX_SPARSE_ELEM *paux;

  printf("-1 %d %d\n",sparse->nrows,sparse->ncols);
  for(i=0;i<sparse->nrows;i++){
    for (paux = sparse->row_index[i]; paux != NULL; paux = paux->right) {
      printf("%d %d %d\n", paux->row, paux->col, (int)paux->elem);
    }
  }

  return SUCCESS;
}

//=================================================================================//
//                                      FREE                                       //
//=================================================================================//
int complex_sparse_free(COMPLEX_SPARSE *sparse) {

	if (!sparse) return INVALID_COMPLEX_SPARSE;

	int i;
	COMPLEX_SPARSE_ELEM *p;

	for (i = 0; i < sparse->nrows; i++) {
		while ((p = sparse->row_index[i])) {
			sparse->row_index[i] = p->right;
			free(p);
		}
	}
	free(sparse->row_index);
	free(sparse->col_index);
	free(sparse);

  return SUCCESS;
}