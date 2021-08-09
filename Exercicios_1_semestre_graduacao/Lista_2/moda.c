#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n1,n2,n3,n4,i,moda,c1=0,c2=0,c3=0,c4=0;
   int vetor[4];

    scanf("%d",&n1);scanf("%d",&n2);scanf("%d",&n3);scanf("%d",&n4);
    
    vetor[0]=n1;
    vetor[1]=n2;
    vetor[2]=n3;
    vetor[3]=n4;
    
    for (i=0;i<4;i++){
        if (vetor[i]==n1){
            c1++;
        }
    }
    for (i=0;i<4;i++){
        if (vetor[i]==n2){
            c2++;
        }
    }
    for (i=0;i<4;i++){
        if (vetor[i]==n3){
            c3++;
        }
    }
    for (i=0;i<4;i++){
        if (vetor[i]==n4){
            c4++;
        }
    }
    
    if ((c1>=c2)&&(c1>=c3)&&(c1>=c4)){
        moda=n1;
    }
    if ((c2>=c1)&&(c2>=c3)&&(c2>=c4)){
        moda=n2;
    }
    if ((c3>=c1)&&(c3>=c2)&&(c3>=c4)){
        moda=n3;
    }
    if ((c4>=c1)&&(c4>=c2)&&(c4>=c3)){
        moda=n4;
    }
    
    printf("%d",moda);
    
    return 0;
}
