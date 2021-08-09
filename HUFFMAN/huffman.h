//Nome: Pedro Fernando Christofoletti dos Santos
//NUSP: 11218560

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "heap.h"
#define TAM2 400

struct arvore_binaria {
	NODE *raiz;
};
typedef struct arvore_binaria ARVORE_BINARIA;

struct tabela_huffman {
	ARVORE_BINARIA *arvore;
	char codigo[TAM2][TAM2];
};
typedef struct tabela_huffman TABELA_HUFFMAN;

TABELA_HUFFMAN *criarTabelaHuffman();
int compactarHuffman(char *, char **, TABELA_HUFFMAN **);
char *descompactarHuffman(char *, int, TABELA_HUFFMAN *);
void liberarArvore(ARVORE_BINARIA **);
void liberarTabelaHuffman(TABELA_HUFFMAN **);

#endif
