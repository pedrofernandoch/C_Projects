//Nome: Pedro Fernando Christofoletti dos Santos
//NUSP: 11218560

#ifndef _COMPLEX_SPARSE_H_
#define _COMPLEX_SPARSE_H_

#define SUCCESS			0
#define INVALID_COMPLEX_SPARSE	-1
#define INVALID_POS		-2
#define NOT_FOUND		-3

struct complex_sparse_elem {
	int row, col;
	double elem;
	struct complex_sparse_elem *right, *bottom;
};

struct complex_sparse {
	int nrows, ncols;
	double constant;
	struct complex_sparse_elem **row_index, **col_index;
};

typedef struct complex_sparse COMPLEX_SPARSE;
typedef struct complex_sparse_elem COMPLEX_SPARSE_ELEM;

void complex_sparse_read(COMPLEX_SPARSE**, COMPLEX_SPARSE**);
COMPLEX_SPARSE* complex_sparse_sum(COMPLEX_SPARSE*, COMPLEX_SPARSE*);
int complex_sparse_product(COMPLEX_SPARSE*, COMPLEX_SPARSE*, COMPLEX_SPARSE*);
int complex_sparse_print(COMPLEX_SPARSE*);
COMPLEX_SPARSE* complex_sparse_create(int, int, double);
int complex_sparse_free(COMPLEX_SPARSE *);

#endif
