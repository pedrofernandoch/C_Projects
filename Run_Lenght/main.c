// Name: Pedro Fernando Christofoletti dos Santos
// NUSP: 11218560

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <funcoes.h>

int main(){
	int rows, columns, shades_of_gray, **image;
	char *type;
  type = (char*) calloc (2,sizeof(char));

  //READINGS
	scanf("%s", type);
	scanf("%d %d", &columns, &rows);
	scanf("%d", &shades_of_gray);

	image = allocate_imageMatrix(rows, columns);

	if(strcmp(type,"P2") == 0) compress(image, rows, columns, shades_of_gray,type);// IF NOT COMPRESSED
  else decompress(image,rows,columns,shades_of_gray,type); // IF COMPRESSED

	free_imageMatrix(image, rows);

	return 0;
}