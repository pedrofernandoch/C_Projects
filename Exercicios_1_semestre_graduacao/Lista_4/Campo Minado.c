#include <stdio.h>
#include <stdlib.h>


void calcula_celula(int LINHA, int COLUNA,char matriz[][COLUNA],int i, int j){

    int count=0;

    if (i>=0 && (j-1)>=0 && i<LINHA && (j-1)<COLUNA){
        if (matriz[i][j-1]=='*'){                                //Ao lado Esquerdo
            count++;
        }
    }

    if (i>=0 && (j+1)>=0 && i<LINHA && (j+1)<COLUNA){
        if (matriz[i][j+1]=='*'){                                //Ao Lado Direito
            count++;
        }
    }

    if ((i-1)>=0 && j>=0 && (i-1)<LINHA && j<COLUNA){
        if (matriz[i-1][j]=='*'){                                //Em Cima
            count++;
        }
    }

    if ((i+1)>=0 && j>=0 && (i+1)<LINHA && j<COLUNA){
        if (matriz[i+1][j]=='*'){                                //Embaixo
            count++;
        }
    }

    if ((i-1)>=0 && (j-1)>=0 && (i-1)<LINHA && (j-1)<COLUNA){
        if (matriz[i-1][j-1]=='*'){                              //Diagonal Cima Esquerda
            count++;
        }
    }

    if ((i-1)>=0 && (j+1)>=0 && (i-1)<LINHA && (j+1)<COLUNA){
        if (matriz[i-1][j+1]=='*'){                              //Diagonal Cima Direita
            count++;
        }
    }

    if ((i+1)>=0 && (j-1)>=0 && (i+1)<LINHA && (j-1)<COLUNA){
        if (matriz[i+1][j-1]=='*'){                             //Diagonal Baixo Esquerda
            count++;
        }
    }

    if ((i+1)>=0 && (j+1)>=0 && (i+1)<LINHA && (j+1)<COLUNA){
        if (matriz[i+1][j+1]=='*'){                             //Diagonal Baixo Direita
            count++;
        }
    }

    matriz[i][j]=count+'0';

}


int main()
{
    
    int i,j,LINHA,COLUNA;
    char aux;

    scanf("%d",&LINHA);
    scanf("%d",&COLUNA);

    char matriz[LINHA][COLUNA];

    for (i=0;i<LINHA;i++){
        for (j=0;j<COLUNA;j++){
            do{
              scanf("%c", &aux);
            }while(aux == ' ' || aux == '\n' || aux =='\r');
            matriz[i][j] = aux;
        }
    }

    for (i=0;i<LINHA;i++){
        for (j=0;j<COLUNA;j++){
            if (matriz[i][j]!='*'){
                calcula_celula(LINHA,COLUNA,matriz,i,j);
            }
        }
    }

    for (i=0;i<LINHA;i++){
        for (j=0;j<COLUNA;j++){
            printf("%c ",matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

