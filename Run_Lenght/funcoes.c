// Name: Pedro Fernando Christofoletti dos Santos
// NUSP: 11218560

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <funcoes.h>

//============================================================================//
//                                  ALLOCATE                                  //
//============================================================================//
int** allocate_imageMatrix(int rows, int columns){

	int **image;

	image = (int **) malloc(rows * sizeof(int*));

	for (int i = 0; i < rows; i++) image[i] = malloc(columns * sizeof(int));
			
	return image;
}

//============================================================================//
//                                  COMPRESS                                  //
//============================================================================//
void compress(int **image, int rows, int columns, int shades_of_gray, char *type){

	int i, j, counter;

  for(i = 0; i < rows; i++){
		for(j = 0; j < columns; j++){
		  scanf("%d", &image[i][j]);
		}
	}

	printf("P8\n");
	printf("%d %d\n", columns, rows);
	printf("%d\n", shades_of_gray);

	// Checks if there are 3 or more equal numbers in a row, if any, will be printed compressed // 
	for(i = 0; i < rows; i++){
		for(j = 0; j < columns; j++){
			counter = 0;
			while(image[i][j] == image[i][j + counter] && (counter + j) < columns) counter++;
			if(counter > 3){
				printf("@ %d %d ", image[i][j], counter);
				j += counter - 1;
			}
			else printf("%d ", image[i][j]);
		}
		printf("\n");
	}

}

//============================================================================//
//                                  DECOMPRESS                                //
//============================================================================//
void decompress(int **image, int rows, int columns, int shades_of_gray, char *type){

  int i,j,k,number,multiplier;
  char *valor;
  valor = (char*) calloc (2,sizeof(char));
  i = j = 0;

  // If an @ is identified, the matrix receive the following number <multiplier> times. Case not, just receive the number as an integer //
	while(i < rows){
		while(j < columns){
			scanf("%s", valor);
			if(strcmp(valor, "@") == 0){
				scanf("%d", &number);
				scanf("%d", &multiplier);
				for(k = 0; k < multiplier; k++){
					image[i][j] = number;
					j++;
				}
			}
			else{
				image[i][j] = atoi(valor);
				j++;
			}
		}
		j = 0;
		i++;
	}
  printf("P2\n");
	printf("%d %d\n", columns, rows);
	printf("%d\n", shades_of_gray);
	print_imageMatrix(image,rows,columns);  
}

//============================================================================//
//                                    PRINT                                   //
//============================================================================//
void print_imageMatrix(int **image, int rows, int columns){

  int i,j;

	for(i = 0; i < rows; i++){
		for (j = 0; j < columns; j++){
			printf("%d ", image[i][j]);
		}
		printf("\n");
	}

}

//============================================================================//
//                                    FREE                                    //
//============================================================================//
void free_imageMatrix(int **image, int rows){

	for(int i = 0; i < rows; i++) free(image[i]);

	free(image);

}