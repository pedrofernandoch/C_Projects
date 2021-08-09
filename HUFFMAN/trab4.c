//Nome: Pedro Fernando Christofoletti dos Santos
//NUSP: 11218560

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "huffman.h"

int main(int argc, char *argv[]){
	
	int i;
	char *text, *textCompac, *textDescompac;
	text = (char *)malloc(10001 * sizeof(char));
	TABELA_HUFFMAN *tabela = criarTabelaHuffman();//cria a tabela de huffman

	//le o texto que sera compactado
	for(i = 0; (text[i] = getchar()) != '\n' && i < 10000; ++i);
	text[i] = '\0';
				
	//compacta o texto e modifica a tabela
	int sizeCompac = compactarHuffman(text, &textCompac, &tabela);
	//descompacta o texto baseado na tabela criada
	textDescompac = descompactarHuffman(textCompac, sizeCompac, tabela);

	//imprime o tamanho do texto original
	printf("%d\n",(int)strlen(text));
	//imprime o tamanho do texto compactado
	printf("%d\n",sizeCompac);
	//imprime o texto descompactado
	printf("%s\n",textDescompac);

	//libera a memoria alocada para a tabela de Huffman
	liberarTabelaHuffman(&tabela);
	free(text);
	free(textCompac);
	free(textDescompac);

  	return 0;
}