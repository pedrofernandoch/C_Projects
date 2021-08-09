//Nome: Pedro Fernando Christofoletti dos Santos
//NUSP: 11218560

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "huffman.h"
#include "heap.h"

//=================================================================//
//                       CRIA TABELA HUFFMAN                       //
//=================================================================//
TABELA_HUFFMAN *criarTabelaHuffman() {

	TABELA_HUFFMAN *nova_tabela = (TABELA_HUFFMAN *) malloc(sizeof(TABELA_HUFFMAN));
	int i;
	
	for (i = 0; i < TAM2; i++) nova_tabela->codigo[i][0] = ' ';
	nova_tabela->arvore = NULL;
	
	return nova_tabela;
}

//=================================================================//
//                            CRIA ÁRVORE                          //
//=================================================================//
ARVORE_BINARIA *criarArvore() {

	ARVORE_BINARIA *arv = (ARVORE_BINARIA *) malloc (sizeof(ARVORE_BINARIA));

	arv->raiz = NULL;

	return arv;
}

//=================================================================//
//                            CRIA TABELA                          //
//=================================================================//
void criarTabela(TABELA_HUFFMAN *tabela, char *texto) {

	int i, len, *freq = NULL;

	len = strlen(texto);
	freq = (int *) calloc (TAM2, sizeof(int));

	for (i = 0; i < len; i++)freq[(int) texto[i]]++;

	HEAP *heap = criarHeap();

	for (i = 0; i < TAM2; i++) {
		if (freq[i] > 0) {
			NODE *no = (NODE *) malloc (sizeof(NODE));
			no->simbolo = i;
			no->freq = freq[i];
			no->filho_esq = NULL;
			no->filho_dir = NULL;
			enfileirar(heap, no);
		}
	}

	while (tamanho(heap) > 1) {
		NODE *mrg = (NODE*) malloc (sizeof(NODE));
		mrg->simbolo = 90 + (rand()%30);
		mrg->filho_esq = desenfileirar(heap);
		mrg->filho_dir = desenfileirar(heap);
		mrg->freq = mrg->filho_esq->freq + mrg->filho_dir->freq;
		enfileirar(heap, mrg);
	}

	tabela->arvore = criarArvore();
	tabela->arvore->raiz =  desenfileirar(heap);
	free(freq);
}

//=================================================================//
//                        CRIA CODIGO AUXILIAR                     //
//=================================================================//
void criarCodigo_aux(TABELA_HUFFMAN *tabela, NODE *no, char *cod, int fim) {

	if (no != NULL) {
		if (no->filho_esq == NULL && no->filho_dir == NULL) {
			int i;
			for (i = 0; i <= fim; i++)tabela->codigo[(int) no->simbolo][i] = cod[i];
			tabela->codigo[(int) no->simbolo][fim+1] = '\0';
		} else {
			if (no->filho_esq != NULL) {
				fim++;
				cod[fim] = '0';
				criarCodigo_aux(tabela, no->filho_esq, cod, fim);
				fim--;
			}
			if (no->filho_dir != NULL) {
				fim++;
				cod[fim] = '1';
				criarCodigo_aux(tabela, no->filho_dir, cod, fim);
				fim--;
			}
		}
	}
}

//=================================================================//
//                            CRIA CODIGO                          //
//=================================================================//
void criarCodigo(TABELA_HUFFMAN *tabela) {

	char codigo[TAM2];

	criarCodigo_aux(tabela, tabela->arvore->raiz, codigo, -1);
}

//=================================================================//
//                          COMPACTA HUFFMAN                       //
//=================================================================//
int compactarHuffman(char *texto, char **texto_c, TABELA_HUFFMAN **tabela) {

	int i, j, cod_fim;
	char *cod = NULL;

	criarTabela(*tabela, texto);
	criarCodigo(*tabela);
	cod_fim = -1;
	
	for (i = 0; texto[i] != '\0'; i++) {
		char *pch = (*tabela)->codigo[(int) texto[i]];
		for (j = 0; pch[j] != '\0'; j++) {
			cod_fim++;
			cod = (char *) realloc (cod, (cod_fim+1)*sizeof(char));
			cod[cod_fim] = pch[j];
		}
	}

	cod_fim++;
	cod = (char *) realloc (cod, (cod_fim+1)*sizeof(char));
	cod[cod_fim] = '\0';

	*texto_c = (char *) malloc (cod_fim * sizeof(char));
	strcpy(*texto_c, cod);
	free(cod);
	return ceil(cod_fim / 8.0) + 1;
}

//=================================================================//
//                       DESCOMPACTA HUFFMAN                       //
//=================================================================//
char *descompactarHuffman(char *texto_c, int tam_c, TABELA_HUFFMAN *tabela) {

	int i, decod_fim = -1;
	char *decod = NULL;
	NODE *pra = tabela->arvore->raiz;

	for (i = 0; texto_c[i] != '\0'; i++) {
		if (texto_c[i] == '0') pra = pra->filho_esq;
		else if (texto_c[i] == '1') pra = pra->filho_dir;
		else return NULL;

		if (pra->filho_esq == NULL && pra->filho_dir == NULL) {
			decod_fim++;
			decod = (char*) realloc (decod, (decod_fim+1)*sizeof(char));
			decod[decod_fim] = pra->simbolo;
			pra = tabela->arvore->raiz;
		}
	}

	decod[decod_fim+1] = '\0';
	return decod;
}

//=================================================================//
//                          LIBERA ARVORE                          //
//=================================================================//
void liberarArvore(ARVORE_BINARIA **arv) {

	free((*arv)->raiz);
	free(*arv);
	*arv = NULL;
}

//=================================================================//
//                           LIBERA TABELA                         //
//=================================================================//
void liberarTabelaHuffman(TABELA_HUFFMAN **tabela) {

	liberarArvore(&((*tabela)->arvore));
	free(*tabela);
	*tabela = NULL;
}