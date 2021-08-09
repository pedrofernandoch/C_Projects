#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

void modifica_matriz(int,int,int,char[][MAX],char [][MAX]);

int main(){
  
  int m,n,t,i,j;

  scanf("%d",&m);
  scanf("%d",&n);
  scanf("%d",&t);

  char matrizCopia[m][n],matriz[m][n],aux;

  for (i=0;i<m;i++){
        for (j=0;j<n;j++){
            do{
              scanf("%c", &aux);
            }while(aux == ' ' || aux == '\n' || aux =='\r');
            matriz[i][j] = aux;
        }
    } 

  for (i=0;i<m;i++){
        for (j=0;j<n;j++){
            matrizCopia[i][j]=matriz[i][j];
        }
    }   

  modifica_matriz(m,n,t,matrizCopia,matriz);

  return 0;
}

void modifica_matriz(int m, int n, int t,char matrizCopia[][n],char matriz[][n]){

  int i,j;
  
  while(t>0){

      for (i=0;i<m;i++){
          for (j=0;j<n;j++){
              if (matrizCopia[i][j]=='0'){
                  matrizCopia[i][j]='*';
                  if (i>=0 && (j-1)>=0 && i<m && (j-1)<n){
                  matrizCopia[i][j-1]='*';     
                  }
                  if (i>=0 && (j+1)>=0 && i<m && (j+1)<n){     
                  matrizCopia[i][j+1]='*';
                  }
                  if ((i-1)>=0 && j>=0 && (i-1)<m && j<n){          matrizCopia[i-1][j]='*';
                  }        
                  if ((i+1)>=0 && j>=0 && (i+1)<m && j<n){          matrizCopia[i+1][j]='*';    
                  }
              }                               
          }
      }
      t--;

      for (i=0;i<m;i++){
          for (j=0;j<n;j++){
              if (matriz[i][j]=='.' && matrizCopia[i][j]=='.'){
                matrizCopia[i][j]='0';
                    
              }                               
          }
      }t--;

      for (i=0;i<m;i++){
          for (j=0;j<n;j++){
              if (matrizCopia[i][j]=='*'){
                matrizCopia[i][j]='.';
              }                               
          }
      }
      t--;

      for (i=0;i<m;i++){
          for (j=0;j<n;j++){
              printf("%c",matrizCopia[i][j]);
          }
          printf("\n");
      }

  }
}
