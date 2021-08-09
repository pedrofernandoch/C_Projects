#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

 double *vet1, *vet2;
 int size,i,j;

  scanf("%d",&size);

  vet1 = (double *) malloc(size*sizeof(double));
  vet2 = (double *) calloc(size,sizeof(double));

  for (i=0;i<size;i++){
    scanf("%lf",&vet1[i]);
  }

  for (i=0;i<size;i++){
    for (j=0;j<size;j++){
      vet2[i]+= vet1[j] * cos((M_PI/size)*(j+0.5)*i);
    }
  }

  for (i=0;i<size;i++){
    printf("%lf\n",vet2[i]);
  }

  free(vet1);
  free(vet2);

 return 0;
}

