#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main() {

  int oc1=0,oc2=0;
  FILE *musica;
  char p1[15],p2[15],palavra[15];
  
    musica = fopen("QuePaiseEste.txt","r");
    assert(musica);
    
    scanf("%s %s",p1,p2);
    
    while (fscanf(musica, "%s ",palavra)!=EOF){
            if (strcmp(palavra,p1)==0){
                oc1++;
            }
            if (strcmp(palavra,p2)==0){
                oc2++;
            }
    }
    
    printf("%s %d %s %d",p1,oc1,p2,oc2);
 
    fclose(musica);

  return 0;
}