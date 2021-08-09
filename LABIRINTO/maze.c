#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "maze.h"
#include "stack.h"

//==========================================================================================//
//                                      CRIA LABIRINTO                                      //
//==========================================================================================//
PONTO* MAZE_create_maze(){

  int  qtdPontos,qtdC,qtdS,i,id1,id2,j,l,start,caminhos,saida;
  PONTO *p,*aux;

  scanf("%d",&qtdPontos);
  p = (PONTO*) calloc (qtdPontos,sizeof(PONTO));

  // LÊ PONTOS
  for(i=0;i<qtdPontos;i++){
    scanf("%f %f",&p[i].x,&p[i].y);
    p[i].id = i+1;
  } 

  //LÊ CÂMARAS 
  scanf("%d",&qtdC);
  for(i=0;i<qtdC;i++){
    scanf("%d %d",&id1,&saida);
    p[id1-1].saida=saida; 
  }

  //LÊ SEGMENTOS E CONECTA PONTOS
  scanf("%d",&qtdS); 
  for(i=0;i<qtdS;i++){
    scanf("%d %d",&id1,&id2); 
    if(id2>0){ // SE FOR POSSÍVEL PASSAR PELO SEGMENTO
      id1 = id1-1;
      id2 = id2-1;
      if(p[id1].n_pontos==0){ //SE ID 1 NÃO POSSUI PONTOS CONECTADOS
        p[id1].pontos = (int*) malloc(sizeof(int));
        p[id1].pontos[0] = id2+1;
        p[id1].n_pontos++;
        if(p[id2].n_pontos==0){ //SE ID 2 NÃO POSSUI PONTOS CONECTADOS
          p[id2].pontos = (int*) malloc(sizeof(int));
          p[id2].pontos[0] = id1+1;
          p[id2].n_pontos++;
        }else{  //SE ID 2 JA POSSUI PONTOS CONECTADOS
          p[id2].n_pontos++;
          p[id2].pontos = (int*) realloc(p[id2].pontos,p[id2].n_pontos * sizeof(int));
          p[id2].pontos[p[id2].n_pontos-1] = id1+1;
        }
      }else{ //SE ID 1 JA POSSUI PONTOS CONECTADOS
        p[id1].n_pontos++;
        p[id1].pontos = (int*) realloc(p[id1].pontos,p[id1].n_pontos * sizeof(int));
        p[id1].pontos[p[id1].n_pontos-1] = id2+1;
        if(p[id2].n_pontos==0){ //SE ID 2 NÃO POSSUI PONTOS CONECTADOS
          p[id2].pontos = (int*) malloc(sizeof(int));
          p[id2].pontos[0] = id1+1;
          p[id2].n_pontos++;
        }else{ //SE ID 2 JA POSSUI PONTOS CONECTADOS
          p[id2].n_pontos++;
          p[id2].pontos = (int*) realloc(p[id2].pontos,p[id2].n_pontos * sizeof(int));
          p[id2].pontos[p[id2].n_pontos-1] = id1+1;
        }
      }
    }
  }   

  return p;
}

//==========================================================================================//
//                                     CALCULA TAMANHO                                      //
//==========================================================================================//
void __MAZE_calcula_tam(CAMINHO *c, int caminhos, PONTO *p){ 
  //CALCULA A DISTÂNCIA GEODÉSIMA DOS PONTOS EM CADA CAMINHO
  int i,j;
  PONTO *atual,*proximo;
  double soma=0;

  for (i=0;i<caminhos;i++){
    for(j=0;j<c[i].n_pontos-1;j++){ 
      soma += sqrt( pow( (p[c[i].caminho[j+1]-1].x - p[c[i].caminho[j]-1].x) ,2) + pow( ((p[c[i].caminho[j+1]-1].y - p[c[i].caminho[j]-1].y)) , 2) );
    }
    c[i].tamanho = soma;
    soma=0;
  }
}

//==========================================================================================//
//                                     ACHA CAMINHO                                         //
//==========================================================================================//
CAMINHO* MAZE_find_paths(PONTO *p, int *n_caminhos){

  int start, contador = 1, ponto_anterior;
  int i=0, j=0, k=0;
  CAMINHO *c = (CAMINHO *) malloc(sizeof(CAMINHO));
  PONTO *top,*follow;
  STACK *path = stack_create(), *sol = stack_create();
  *n_caminhos += 1;

  scanf("%d",&start); 
  top = follow = &p[start-1];
  stack_push(path, top->id);
  stack_push(sol, top->id);

  while(top->visitado != 1){ //enquanto o ponto de inicio não for visitado roda
    ponto_anterior = follow->id;
    if((follow->proximo_index)>follow->n_pontos-1){ //se o proximo indice não existir
      follow->visitado = 1;
      if(top->visitado == 1)break;
      stack_pop(path);
      stack_pop(sol);
      follow = &p[stack_top(path)-1];
      follow->n_visitados++;
      contador--;
    }else{
      if (ponto_anterior!=start){
        stack_pop(path);
        if(follow->pontos[follow->proximo_index] == stack_top(path)) follow->proximo_index++; 
        stack_push(path, follow->id);
      }
      if((follow->proximo_index)>follow->n_pontos-1){ //se o proximo indice não existir
      follow->visitado = 1;
      if(top->visitado == 1)break;
      stack_pop(path);
      stack_pop(sol);
      follow = &p[stack_top(path)-1];
      follow->n_visitados++;
      contador--;
      }else{
        follow->proximo_index++;
        follow = &p[follow->pontos[follow->proximo_index-1]-1];
        stack_push(path, follow->id);
        stack_push(sol, follow->id);
        contador++;
        if (follow->saida == 1){ // se for saida
          c[k].n_pontos = contador;
          c[k].caminho = (int*) malloc(contador * sizeof(int));
          for (j=contador-1;j>=0;j--){
            c[k].caminho[j] = stack_top(sol);
            stack_pop(sol);
          }
          for(i=0;i<contador;i++) stack_push(sol, c[k].caminho[i]);
          k++;
          *n_caminhos += 1;
          c = (CAMINHO*) realloc(c, *n_caminhos * sizeof(CAMINHO));
        }
        if(follow->n_pontos==1 && follow->pontos[0]==ponto_anterior){ //se chegou em edge
          follow->visitado=1;
          if(top->visitado == 1)break;
          follow = &p[ponto_anterior-1];
          follow->n_visitados++;
          stack_pop(path);
          stack_pop(sol);
          contador--;
        }
      }
    }
  }
  stack_free(path);
  stack_free(sol);
  printf("1 ");
  printf("%d ",top->id);
  printf("0\n");
  __MAZE_calcula_tam(c, *n_caminhos-1, p);
  return c;
}

//==========================================================================================//
//                                     ORDENA CAMINHOS                                      //
//==========================================================================================//
void MAZE_sort_path(CAMINHO *c, int caminhos){ //BUBBLE_SORT COM SENTINELA
  int j, u, i,k;
  CAMINHO temp;
  j = caminhos-1;
  while( j > 0 ){
    u = -1;
    for( i = 0; i < j; i++ ){
      if( c[i].tamanho > c[i+1].tamanho ){ //SE O TAMANHO É DIFERENTE 
        temp = c[i];
        c[i] = c[i+1];
        c[i+1] = temp;
        u = i;
      }else if (c[i].tamanho == c[i+1].tamanho){ //SE O TAMANHO É IGUAL
        if(c[i].n_pontos > c[i+1].n_pontos){ // SE O NUMERO DE PONTOS É DIFERENTE
          temp = c[i];
          c[i] = c[i+1];
          c[i+1] = temp;
          u = i;
        }else if (c[i].n_pontos == c[i+1].n_pontos){ //SE O NUMERO DE PONTOS É IGUAL
          for (k=0;k<c[i].n_pontos;k++){
            if (c[i].caminho[k] > c[i+1].caminho[k]){ // SE UM DOS PONTOS DO CAMINHO FOR DIFERENTE
              temp = c[i];
              c[i] = c[i+1];
              c[i+1] = temp;
              u = i;
              break;
            }
          }
        }
      }
    }
    j = u; 
    }
}

//==========================================================================================//
//                                      PRINTA CAMINHOS                                     //
//==========================================================================================//
void MAZE_print_paths(CAMINHO *c, int caminhos){

  int i,j;
  for (i=0;i<caminhos;i++){
    printf("%d ",c[i].n_pontos); //NUMERO DE PONTOS
    for(j=0;j<c[i].n_pontos;j++){
      printf("%d ",c[i].caminho[j]); //PONTOS
    }
    printf("%d\n",(int)c[i].tamanho); //DISTANCIA GEODÉSIMA DOS PONTOS
  }
}