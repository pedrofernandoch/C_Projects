#include <stdio.h>
#define MAX 100

int main()
{
    char nome[MAX];

    printf("nome: ");
    gets(nome);
    printf("%s\n",nome);
    
    printf("nome: ");
    fgets(nome,MAX,stdin);
    printf("%s\n",nome);
    
    printf("nome: ");
    scanf("%7[^\n]s",nome);
    printf("%s",nome);
    
    return 0;
}
