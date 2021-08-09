#include<stdio.h>
#include<stdlib.h>
//TESTE diagonal----------------------------------------------------------------------------------TESTED2
int ganhoudiagonal(char s[3][3])
{
int x=0;
  if(s[0][0]!=' '&&s[1][1]!=' '&&s[2][2]!=' ')
   if(s[0][0]==s[1][1]&&s[0][0]==s[2][2])
    {
   printf("\tGANHOU!!!\nFechou diagonalmente\n");
      x+=1;
      return x;
  }
  if(s[0][2]!=' ')
   if(s[0][2]==s[1][1]&&s[0][2]==s[2][0])
        {
   printf("\tGANHOU!!!\nFechou diagonalmente\n");
      x+=1;
      return x;
  }
}
//TESTE vertical-----------------------------------------------------------------------------------TESTEV
int ganhouvertical(char s[3][3])
{
int i,x=0;
for(i=0;i<3;i++)
 if(s[0][i]!=' '&&s[1][i]!=' '&&s[2][i]!=' ')
  if(s[0][i]==s[1][i]&&s[0][i]==s[2][i])
        {
   printf("\tGANHOU!!!\nFechou verticalmente\n");
      x+=1;
      return x;
  }
}
//TESTE horizontal---------------------------------------------------------------------------------TESTEH
int ganhouhorizontal(char s[3][3])
{
int i,x=0;
for(i=0;i<3;i++)
 if(s[i][0]!=' '&&s[i][1]!=' '&&s[i][2]!=' ')
 if(s[i][0]==s[i][1]&&s[i][0]==s[i][2])
 {
  printf("\tGANHOU!!!\nFechou horizontalmente\n");
  x+=1;
  return x;
 }
}
//MENU das Instruções--------------------------------------------------------------------------------HELP
int suporte()
{
int i,j,help[3][3]={{1,2,3},{4,5,6},{7,8,9}};
for(i=0;i<3;i++)
  {
  for(j=0;j<3;j++)
   printf(" %d %c",help[i][j],j==2?' ':'|');
  if(i!=2)
  printf("\n---------");
  putchar('\n');
  }
  printf("10-Reiniciar\n11-Voltar ao menu\n12-Sair\n");
}
//Desenhar tabuleiro--------------------------------------------------------------------------------PAINT
void mostra(char s[3][3])
{
int i,j;
for(i=0;i<3;i++)
  {
  for(j=0;j<3;j++)
   printf(" %c %c",s[i][j],j==2?' ':'|');
  if(i!=2)
  printf("\n---------");
  putchar('\n');
  }
}
//----//---//---//---//---//---//---//---//---//---//---//---//---//---//---//---//---//---//---//---//--
main()
{
char velha[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
int x,y,win=0;
int jogadas=0,opcao,i,j;
do
{
 voltamenu:printf("Versão 1.2\nBem-vindo ao jogo da velha\n1-Jogar\n2-Instrucoes\n3-Sair\n");//-----GOTOR
 scanf("%d",&opcao);
 system("cls");
//Instruções--------------------------------------------------------------------HELP
  if(opcao==2)
    {
    suporte();
    system("pause");
    system("cls");
    opcao=4;
    }
  if(opcao==3)
 break;
}
while(opcao<1||opcao>3);
//Jogo--------------------------------------------------------------------------GAME
if(opcao==1)
{
printf("1 jogador X\n2 jogador O\n");
while(win==0)
  {
 mostra(velha);
 printf("Insira o numero referente a localizacao no tabuleiro\n");
 scanf("%d",&y);
 x=0;y-=1;
 if(y==10)
 {
  system("cls");
  goto voltamenu;//---------------------------------------------------------------------------GOTOF
 }
 if(y==11)
  break;
 if(y==9)
 for(i=0;i<3;i++)
  for(j=0;j<3;j++)
   velha[i][j]=' ';
 if(velha[x][y]==' ')
    {
  if(jogadas%2==0)
   velha[x][y]='X';
  else
   velha[x][y]='O';
  jogadas+=1;
    }
 else
      if(y==9)
   {
       printf("Tabuleiro Reiniciado\n");
        system("pause");
   }
     else
      if(y<11)
            {
   printf("Posição ja ocupada!\n");
         system("pause");
            }
 system("cls");
 if(jogadas==9)//----------------------EMPATE
    {
    printf("Empatou");
    system("pause");
    break;
       }
 if(ganhouhorizontal(velha)==1)
  {
  system("pause");
  break;
  }
 if(ganhouvertical(velha)==1)
  {
     system("pause");
  break;
  }
 if(ganhoudiagonal(velha)==1)
  {
  system("pause");
  break;
       }
  }
}
}
