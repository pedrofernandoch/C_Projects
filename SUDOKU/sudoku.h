//Nome: Pedro Fernando Christofoletti dos Santos
//NUSP: 11218560

#ifndef _SUDOKU_H_
#define _SUDOKU_H_

#define MAX	16
#define Square_MAX 4
#define EMPTY -1
#define TOTAL 120

int** allocArray2D(size_t rows, size_t cols);
void readSudoku(int **sudoku);
int solveSudoku(int **sudoku, int flag);
int printMsg(int **sudoku,int solved);

#endif