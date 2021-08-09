// Nome: Pedro Fernando Christofoletti dos Santos
// NUSP: 11218560

#include <stdio.h>
#include <stdlib.h>
#include "complex_sparse.h"

//================================================================================================//
//                                            CREATE                                              //
//================================================================================================//
COMPLEX_SPARSE *complex_sparse_create(float nrows, float ncols, float size, int constant) {

	COMPLEX_SPARSE *sparse = (COMPLEX_SPARSE *) malloc(sizeof(COMPLEX_SPARSE));
	sparse->nrows = nrows;
	sparse->ncols = ncols;
  sparse->size = size;
	sparse->constant = constant;

	sparse->row_index = (COMPLEX_SPARSE_ELEM **) calloc(nrows, sizeof(COMPLEX_SPARSE_ELEM *));
	sparse->col_index = (COMPLEX_SPARSE_ELEM **) calloc(ncols, sizeof(COMPLEX_SPARSE_ELEM *));

	return sparse;
}

//================================================================================================//
//                                            PUT                                                 //
//================================================================================================//
int complex_sparse_put(COMPLEX_SPARSE *sparse, float row, float col, float pos, double elem) {

	if (!sparse) return INVALID_COMPLEX_SPARSE;
	if (row < 0 || col < 0 || pos < 0 || row >= sparse->nrows || col >= sparse->ncols || pos >=sparse->size) return INVALID_POS;
  
	COMPLEX_SPARSE_ELEM **rp = &sparse->row_index[(unsigned long int)row];
	COMPLEX_SPARSE_ELEM **cp = &sparse->col_index[(unsigned long int)col];

	while (*rp && ((*rp)->col < col)) rp = &(*rp)->right;
	while (*cp && ((*cp)->row < row)) cp = &(*cp)->bottom;

	if (*rp && *cp && (*rp)->col == col && (*cp)->row == row) {
    if (pos == (*rp)->deep[(unsigned long int)(*rp)->size-1].id){
      (*rp)->deep[(unsigned long int)(*rp)->size-1].elem = elem;
    }else{
      (*rp)->deep = (ELEM *) realloc((*rp)->deep,(*rp)->size+1);
      (*rp)->deep[(unsigned long int)(*rp)->size].elem = elem;
      (*rp)->deep[(unsigned long int)(*rp)->size].id = pos;
      (*rp)->size++;
    }
	} else {
		COMPLEX_SPARSE_ELEM *new = (COMPLEX_SPARSE_ELEM *) malloc(sizeof(COMPLEX_SPARSE_ELEM));
    new->deep = (ELEM *) malloc(sizeof(ELEM));       
		new->row = row;
		new->col = col;
    new->size = 0;
		new->deep[0].elem = elem;
    new->deep[0].id = pos;
		new->right = *rp;
		new->bottom = *cp;
		*rp = *cp = new;
    new->size++;
	}

	return SUCCESS;
}


//================================================================================================//
//                                            GET                                                 //
//================================================================================================//
double complex_sparse_get(COMPLEX_SPARSE *sparse, float row, float col, float pos, int *error) {

	if (!sparse) {
		*error = INVALID_COMPLEX_SPARSE;
		return -1;
	}
	if (row < 0 || col < 0 ||	pos < 0 || row >= sparse->nrows || col >= sparse->ncols || pos >=sparse->size) {
		*error = INVALID_POS;
    printf("LALALAL");
		return -1;
	}

	COMPLEX_SPARSE_ELEM **rp = &sparse->row_index[(unsigned long int)row];
	COMPLEX_SPARSE_ELEM **cp = &sparse->col_index[(unsigned long int)col];

	while (*rp && ((*rp)->col < col)) rp = &(*rp)->right;
	while (*cp && ((*cp)->row < row)) cp = &(*cp)->bottom;

	if (*rp && *cp && (*rp)->col == col && (*cp)->row == row) {
    for (int i=0;i<(*rp)->size;i++){
      if((*rp)->deep[i].id == pos){
        *error = SUCCESS;
		    return (*rp)->deep[i].elem;    
      }
    }
	}

	*error = NOT_FOUND;
	return sparse->constant;
}

//================================================================================================//
//                                            REMOVE                                              //
//================================================================================================//
int complex_sparse_remove(COMPLEX_SPARSE *sparse, float row, float col, float pos) {

  if (!sparse) return INVALID_COMPLEX_SPARSE;
	if (row < 0 || col < 0 || pos < 0 || row >= sparse->nrows || col >= sparse->ncols || pos >=sparse->size) return INVALID_POS;


	COMPLEX_SPARSE_ELEM **rp = &sparse->row_index[(unsigned long int)row];
	COMPLEX_SPARSE_ELEM **cp = &sparse->col_index[(unsigned long int)col];

	while (*rp && ((*rp)->col < col)) rp = &(*rp)->right;
	while (*cp && ((*cp)->row < row)) cp = &(*cp)->bottom;

	if (*rp && *cp && (*rp)->col == col && (*cp)->row == row) {
   for (int i=0;i<(*rp)->size;i++){
      if((*rp)->deep[i].id == pos){
        while(i<(*rp)->size-1){
          (*rp)->deep[i] = (*rp)->deep[i+1];
          i++;
        }
        (*rp)->deep = (ELEM *) realloc((*rp)->deep,(*rp)->size-1);
        (*rp)->size--;      
        break;
      }
   }  
	} else return NOT_FOUND;

	return SUCCESS;
}

//================================================================================================//
//                                            FREE                                                //
//================================================================================================//
int complex_sparse_free(COMPLEX_SPARSE *sparse) {

  if (!sparse) return INVALID_COMPLEX_SPARSE;

  COMPLEX_SPARSE_ELEM **rp = &sparse->row_index[0],*aux;
	COMPLEX_SPARSE_ELEM **cp = &sparse->col_index[0];

  while(*cp && (cp = &(*cp)->bottom)){
    while (*rp && (rp = &(*rp)->right)){
      free((*rp)->deep);
    }
    while (*rp){
      aux = *rp;
      rp = &(*rp)->right;
      free(aux);      
    }
  }
  while (*cp){
    aux = *cp;
     cp = &(*cp)->right;
     free(aux);      
  }

  free(sparse);

  return SUCCESS; 
}

