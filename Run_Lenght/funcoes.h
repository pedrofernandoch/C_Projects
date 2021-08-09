// Name: Pedro Fernando Christofoletti dos Santos
// NUSP: 11218560

#ifndef FUNCOES_H
#define FUNCOES_H

// Allocate a matrix with the size of the rows and columns of the image.
int** allocate_imageMatrix(int, int);
// Compact image
void compress(int **, int, int, int, char*);
// Decompact image
void decompress(int **, int, int, int, char*);
// Print image matrix
void print_imageMatrix(int **, int, int);
// Free image matrix
void free_imageMatrix(int **, int);

#endif
