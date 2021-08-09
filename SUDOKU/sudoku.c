//Nome: Pedro Fernando Christofoletti dos Santos
//NUSP: 11218560

#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

/*  Allocate a (rows,cols) 2D array. */
int** allocArray2D(size_t rows, size_t cols) {
  int **arr = (int**)malloc(rows * sizeof(int*)), i;
	for (i = 0; i < rows; i++) arr[i] = (int*) calloc(rows, sizeof(int));
	return arr;
}

/* Read and store a new sudoku. */
void readSudoku(int **sudoku) {

	int i, j;
  char **aux;
  aux = (char**) malloc(MAX * sizeof(char*));
  for(i=0;i<MAX;i++)aux[i] = (char*) malloc(MAX * sizeof(char));

	for (i = 0; i < MAX; i++)scanf("%s",aux[i]);
  for (i = 0; i < MAX; i++){
    for (j = 0; j < MAX; j++){
      if (aux[i][j] == '.') sudoku[i][j] = EMPTY;
      else if (aux[i][j] == '0') sudoku[i][j] = 0;
      else if (aux[i][j] == '1') sudoku[i][j] = 1;  
      else if (aux[i][j] == '2') sudoku[i][j] = 2;  
      else if (aux[i][j] == '3') sudoku[i][j] = 3;  
      else if (aux[i][j] == '4') sudoku[i][j] = 4;  
      else if (aux[i][j] == '5') sudoku[i][j] = 5;  
      else if (aux[i][j] == '6') sudoku[i][j] = 6;  
      else if (aux[i][j] == '7') sudoku[i][j] = 7;  
      else if (aux[i][j] == '8') sudoku[i][j] = 8;  
      else if (aux[i][j] == '9') sudoku[i][j] = 9;  
      else if (aux[i][j] == 'A') sudoku[i][j] = 10;  
      else if (aux[i][j] == 'B') sudoku[i][j] = 11; 
      else if (aux[i][j] == 'C') sudoku[i][j] = 12; 
      else if (aux[i][j] == 'D') sudoku[i][j] = 13; 
      else if (aux[i][j] == 'E') sudoku[i][j] = 14; 
      else if (aux[i][j] == 'F') sudoku[i][j] = 15; 
    }
  }
  free(aux);    
}


int __checkOnlyPossible(int **sudoku, int row, int col, int *num){

  int rowStart = (row / Square_MAX) * Square_MAX;
  int colStart = (col / Square_MAX) * Square_MAX;
  int rowVector[MAX], colVector[MAX], boxVector[MAX];
  int flag = 0, count = 0;
  int i, j;

  for(i=0;i<MAX;i++){ //Store all number from row/col/box
    colVector[i] = sudoku[i][col]; 
		rowVector[i] = sudoku[row][i];  
		boxVector[i] = sudoku[rowStart + (i % Square_MAX)][colStart + (i / Square_MAX)];
  }

  for(i=0;i<MAX;i++){ //For each row/col/box try each possible digit 
    for(j=0;j<MAX;j++) if((i == rowVector[j]) || (i == colVector[j]) || (i == boxVector[j])) flag = 1; 
    if(!flag){ //if the digit isnt in the array
      *num = i;
      count++;
    }
    flag = 0;
  }

  if(count == 1) return 1;  //Only one possibility
  else return 0;

}

/* Try filling the gaps with one possibility until there is no more spaces left */
int solveSudoku(int **sudoku, int flag){  

  int i,j,num;

  for(int k=0;k<100;k++){
    for(i=0;i<MAX;i++){
      for(j=0;j<MAX;j++){
        if (sudoku[i][j] == EMPTY){
          if(__checkOnlyPossible(sudoku,i,j,&num)){
            sudoku[i][j] = num; 
          }
        }
      } 
    }
  }

  return 1;
	
}

/*  Prints sudoku matrix. */
void __printSudoku(int **sudoku) {
	int i, j;
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) 
		printf("%X", sudoku[i][j]);	
		printf("\n");
	}
}

int printMsg(int **sudoku,int solved) {
	if (solved) __printSudoku(sudoku);
	else printf("\nCannot solve sudoku.\n");
	return solved;
}