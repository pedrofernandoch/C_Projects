// Nome: Pedro Fernando Christofoletti dos Santos
// NUSP: 11218560

#ifndef _COMPLEX_SPARSE_H_
#define _COMPLEX_SPARSE_H_

#define SUCCESS 1;
#define INVALID_COMPLEX_SPARSE 0;
#define INVALID_POS -1;
#define NOT_FOUND -2;

typedef struct{
  double elem;
  float id;
}ELEM;

struct complex_sparse_elem {
	float row, col;
	ELEM *deep;
  	float size;
	struct complex_sparse_elem *right, *bottom;
};

struct complex_sparse {
	float nrows, ncols, size;
	int constant;
	struct complex_sparse_elem **row_index, **col_index;
};

typedef struct complex_sparse COMPLEX_SPARSE;
typedef struct complex_sparse_elem COMPLEX_SPARSE_ELEM;

COMPLEX_SPARSE *complex_sparse_create(float, float, float, int);
int complex_sparse_put(COMPLEX_SPARSE *, float, float, float, double);
double complex_sparse_get(COMPLEX_SPARSE *, float, float, float, int *);
int complex_sparse_remove(COMPLEX_SPARSE *, float, float, float);
int complex_sparse_free(COMPLEX_SPARSE *);

#endif
