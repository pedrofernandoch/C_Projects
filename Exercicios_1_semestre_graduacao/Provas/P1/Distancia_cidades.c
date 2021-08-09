#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  
  int n,origem,destino,i,j;
  float d;

  scanf("%d",&n);
  scanf("%d",&origem);
  scanf("%d",&destino);

  int matriz[n][3],x1,x2,y1,y2;

  for (j=0,i=0;i<n;i++){
        scanf("%d (%d,%d)",&matriz[i][j],&matriz[i][j+1],&matriz[i][j+2]);
  }

  for (i=0;i<n;i++){
    if (origem==matriz[i][0]){
    x1=matriz[i][1];
    y1=matriz[i][2];
    }
    if (destino==matriz[i][0]){
    x2=matriz[i][1];
    y2=matriz[i][2];
    }
  }
  d = (float) sqrt(pow(x2-x1,2)+pow(y2-y1,2));

  printf("%.2f",d);
  

   return 0;
}

