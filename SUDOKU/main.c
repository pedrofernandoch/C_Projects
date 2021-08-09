//Nome: Pedro Fernando Christofoletti dos Santos
//NUSP: 11218560

#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

int main(int argc, char *argv[]) {
	
  int solved;

	int **sudoku = allocArray2D(MAX, MAX);
	readSudoku(sudoku);
	solved = solveSudoku(sudoku,0);
	printMsg(sudoku,solved);
  free(sudoku);

	return 0;
}