#ifndef _MAZE_H_
#define _MAZE_H_

struct PONTO{
  int saida;          //verifica se é saida
  int id;             //id do ponto
  int n_pontos;       //numero de pontos conectados
  int *pontos;        //vetor com o id dos pontos conectados
  int visitado;       //verifica se ja foi visitado
  int n_visitados;    //numero de visitados dos pontos conectados
  int proximo_index;  //proximo indice do vetor de pontos a ser verificado 
  float x,y;          //cordenadas do ponto
};

typedef struct PONTO PONTO;

typedef struct{
  int *caminho; //pontos do caminho
  int n_pontos; //numero de pontos no caminho
  float tamanho;//soma das distancias euclidianas dos pontos do caminho
}CAMINHO;

PONTO* MAZE_create_maze(); //cria labirinto
CAMINHO * MAZE_find_paths(PONTO *p,int *); //acha caminho
void MAZE_sort_path(CAMINHO *, int); //ordena labirinto
void MAZE_print_paths(CAMINHO *, int);  //prinmta labirinto

#endif
