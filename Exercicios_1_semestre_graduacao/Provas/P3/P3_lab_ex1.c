#include <stdio.h>
#include <stdlib.h>

typedef struct{ 
  int HP;
  int Ataque;
  int defesa;
  int Ataque_Especial;
  int Defesa_Especial;
  int Velocidade;
}Atributos; 

typedef struct{ 
  char nome[50];
  int Poder_base;
  float Acuracia;
  char Classe;
}Ataques[4]; 


typedef struct{ 
  char nome[50]; 
  char Tipo_primario[20]; 
  char Tipo_secundario[20];
  Atributos status; 
  Ataques habilidade;
}Pokedex; 

int main(){

  int i=0,size=1,Tipo_Ataque,id,op;
  Pokedex *pokemons=NULL;

  scanf("%d",&op);
  while(op!=0){
    switch(op){

      case 1:

        pokemons = (Pokedex*) realloc(pokemons,size*sizeof(Pokedex));
        size++;
        scanf(" %s",pokemons[i].nome);
        scanf(" %s",pokemons[i].Tipo_primario);
        scanf(" %s",pokemons[i].Tipo_secundario);
        scanf("%d",&pokemons[i].status.HP);
        scanf("%d",&pokemons[i].status.Ataque);
        scanf("%d",&pokemons[i].status.defesa);
        scanf("%d",&pokemons[i].status.Ataque_Especial);
        scanf("%d",&pokemons[i].status.Defesa_Especial);
        scanf("%d",&pokemons[i].status.Velocidade);
        i++;

      break;

      case 2:

        scanf("%d",&id);
        scanf("%d",&Tipo_Ataque);
        scanf(" %s",pokemons[id].habilidade[Tipo_Ataque].nome);
        scanf("%d",&pokemons[id].habilidade[Tipo_Ataque].Poder_base);
        scanf("%f\n",&pokemons[id].habilidade[Tipo_Ataque].Acuracia);
        scanf("%c",&pokemons[id].habilidade[Tipo_Ataque].Classe);

      break;

    case 3:

        scanf("%d",&id);
        printf("Nome do Pokemon: %s\n",pokemons[id].nome);
        printf("Tipo primario: %s\n",pokemons[id].Tipo_primario);
        printf("Tipo secundario: %s\n",pokemons[id].Tipo_secundario);
        printf("Status:\n"); 
        printf("\tHP: %d\n",pokemons[id].status.HP);
        printf("\tAtaque: %d\n",pokemons[id].status.Ataque);
        printf("\tDefesa: %d\n",pokemons[id].status.defesa); 
        printf("\tAtaque Especial: %d\n",pokemons[id].status.Ataque_Especial);
        printf("\tDefesa Especial: %d\n",pokemons[id].status.Defesa_Especial);
        printf("\tVelocidade: %d\n\n",pokemons[id].status.Velocidade);

      break;

      case 4:

        scanf("%d",&id);
        scanf("%d",&Tipo_Ataque);
        printf("Nome do Ataque: %s\n",pokemons[id].habilidade[Tipo_Ataque].nome);
        printf("Poder base: %d\n",pokemons[id].habilidade[Tipo_Ataque].Poder_base);
        printf("Acuracia: %f\n",pokemons[id].habilidade[Tipo_Ataque].Acuracia);
        printf("Classe: %c\n\n",pokemons[id].habilidade[Tipo_Ataque].Classe);

      break;
    }
    scanf("%d",&op);
  }
	return 0;
}