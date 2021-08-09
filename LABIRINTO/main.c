#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

int main(void) {

  int n_caminhos;
  PONTO *p;
  CAMINHO *c;

  p = MAZE_create_maze(); //cria labirinto
  c = MAZE_find_paths(p,&n_caminhos); //acha caminhos
  MAZE_sort_path(c, n_caminhos-1); //ordena caminhos
  MAZE_print_paths(c, n_caminhos-1); //printa caminhos
  free(c);
  free(p);
  
  return 0;
}