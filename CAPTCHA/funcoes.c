#include "funcoes.h"
#include <stdio.h>

void homogenizar(int **vet, int linha, int coluna){

  int i,j;

  for (i=0;i<linha;i++){
    for (j=0;j<coluna;j++){
      if(vet[i][j]!=0)
        vet[i][j]=1;
    }
  }

}

void eliminaRuido(int **vet, int linha, int coluna){

  int i=0,j;

  for (j=0;j<coluna;j++){
    while(i<=(linha-2)){
      if ((vet[i][j] + vet[i+1][j] + vet[i+2][j]) >= 2){
          vet[i][j] = 1; vet[i+1][j]= 1; vet[i+2][j] =1;
      }  else{
            vet[i][j] = 0; vet[i+1][j]= 0; vet[i+2][j] = 0;
          }
      i= i + 3;
    }
    i=0;
  }
}

void frequencia_dos_identificadores_de_numeros(int k, int maior, int **identificadores_de_numerosSeparados, int **freq_identificadores_de_numeros){

  int i,j;
  int um=0,dois=0,tres=0,quatro=0,cinco=0;

  for (i=0;i<k;i++){
    for (j=0;j<=maior;j++){
      switch(identificadores_de_numerosSeparados[i][j]){
        case 1: um++;
          break;
        case 2: dois++;
          break;
        case 3: tres++;
          break;
        case 4: quatro++;
          break;
        case 5: cinco++;
          break;
      }
    }
    // Eliminando ruidos da frequencia por arredondamento para o multiplo de 10 mais proximo //
    freq_identificadores_de_numeros[i][0]= ((int)(um+5)/10)*10;
    freq_identificadores_de_numeros[i][1]= ((int)(dois+5)/10)*10;
    freq_identificadores_de_numeros[i][2]= ((int)(tres+5)/10)*10;
    freq_identificadores_de_numeros[i][3]= ((int)(quatro+5)/10)*10;
    freq_identificadores_de_numeros[i][4]= ((int)(cinco+5)/10)*10;
    um=dois=tres=quatro=cinco=0;
  }

}

int descobre_numero(int x1, int x2, int x3, int x4, int x5, int i, int linhas, int coluna_final_do_numero, int **identificadores_de_numerosSeparados, int **imagem){

  int r,c1=0,c2=0;
  int w=0,x,y=0;

  if(x1 == 0 && x2 == 10 && x3 == 0 && x4 == 0 && x5 == 20){// Frequencia de Identificadores do 0
    return 0;
  }
  else if(x1 == 0 && x2 == 0 && x3 == 0 && x4 == 0 && x5 == 10){// Frequencia de Identificadores do 1
    return 1;
  }
  else if(x1 == 0 && x2 == 0 && x3 == 10 && x4 == 20 && x5 == 0){// Frequencia de Identificadores do 2 ou 5
    w = x = y = 0;
    for (x=0;x<linhas;x++){
      if (w<=90){
        for (int t=0;t<10;t++){
            w= w+ imagem[x][coluna_final_do_numero -t];
        }
      }else{
        if(y>10){
          break;
        }
        else{
          for (int t=0;t<10;t++){
            w = w+imagem[x][coluna_final_do_numero -t];
          }
          y++;
        }
      }
    }
    if (w>=200)
      return 2;
    else
      return 5;
  }
  else if(x1 == 0 && x2 == 0 && x3 == 20 && x4 == 0 && x5 == 10){// Frequencia de Identificadores do 3
    return 3;
  }
  else if(x1 == 10 && x2 == 0 && x3 == 10 && x4 == 0 && x5 == 10){// Frequencia de Identificadores do 4
    return 4;
  }
  else if(x1 == 0 && x2 == 0 && x3 == 10 && x4 == 10 && x5 == 10){// Frequencia de Identificadores do 6 ou 9
    for (r=0;r<10;r++){
        if (identificadores_de_numerosSeparados[i][r] == 5)
            c1++;
        else c2++;
    }
    if (c1>c2)
        return 6;
    else return 9;
  }
  else if(x1 == 20 && x2 == 0 && x3 == 0 && x4 == 0 && x5 == 10){// Frequencia de Identificadores do 7
    return 7;
  }
  else if(x1 == 0 && x2 == 0 && x3 == 10 && x4 == 0 && x5 == 20){// Frequencia de Identificadores do 8
    return 8;
  }
  else{ // Em caso de espacos entre os numeros identificados como numeros por conta de ruidos nao eliminados
    return -1;
  }
}
