//Nome: Pedro Fernando Christofoletti dos Santos
//NUSP: 11218560

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "heap.h"
#include "huffman.h"

//=================================================================//
//                            CRIA HEAP                            //
//=================================================================//
HEAP *criarHeap() {

	HEAP *heap = (HEAP *) malloc (sizeof(HEAP));
	heap->fim = -1;

	return heap;
}

//=================================================================//
//                              CHEIA                              //
//=================================================================//
int cheia(HEAP *heap) {
	return (heap->fim == TAM1 - 1);
}

//=================================================================//
//                              VAZIA                              //
//=================================================================//
int vazia(HEAP *heap) {
	return (heap->fim == -1);
}

//=================================================================//
//                              SWAP                               //
//=================================================================//
void swap(HEAP *h, int i, int j) {

	NODE *aux = h->vetor[i];

	h->vetor[i] = h->vetor[j];
	h->vetor[j] = aux;
}

//=================================================================//
//                              FIX UP                             //
//=================================================================//
void fix_up(HEAP *h) {

	int pos = h->fim;
	int pai = (pos - 1) / 2;

	while (pos > 0 && h->vetor[pos]->freq < h->vetor[pai]->freq) {
		swap(h, pos, pai);
		pos = pai;
		pai = (pai - 1) / 2;
	}
}

//=================================================================//
//                            ENFILEIRAR                           //
//=================================================================//
int enfileirar(HEAP *h, NODE *no) {

	if (!cheia(h)) {
		h->fim++;
		h->vetor[h->fim] = no;
		fix_up(h);

		return 1;
	}
	return 0;
}

//=================================================================//
//                            FIX DOWN                             //
//=================================================================//
void fix_down(HEAP *h) {

	int pos = 0;

	while (pos <= h->fim / 2) {
		int filhoesq = 2 * pos + 1;
		int filhodir = 2 * pos + 2;
		int maiorfilho;

		if (filhodir <= h->fim &&	h->vetor[filhoesq]->freq > h->vetor[filhodir]->freq)maiorfilho = filhodir;
		else maiorfilho = filhoesq;

		if (h->vetor[pos]->freq <= h->vetor[maiorfilho]->freq)break;

		swap(h, pos, maiorfilho);
		pos = maiorfilho;
	}
}

//=================================================================//
//                            DESENFILEIRAR                        //
//=================================================================//
NODE *desenfileirar(HEAP *h) {

	if (!vazia(h)) {
		NODE *node = h->vetor[0];
		h->vetor[0] = h->vetor[h->fim];
		h->fim--;
		fix_down(h);
		return node;
	}
	return NULL;
}

//=================================================================//
//                            TAMANHO                              //
//=================================================================//
int tamanho(HEAP *h) {
	return (h->fim+1);
}

//=================================================================//
//                            APAGAR HEAP                          //
//=================================================================//
void apagarHeap(HEAP **h) {

	int i;

	for (i = 0; i < (*h)->fim; i++) {
		if ((*h)->vetor[i]->filho_esq != NULL)free((*h)->vetor[i]->filho_esq);
		if ((*h)->vetor[i]->filho_dir != NULL)free((*h)->vetor[i]->filho_dir);
		free((*h)->vetor[i]);
	}
	free((*h)->vetor);
	free(*h);
	*h = NULL;
}