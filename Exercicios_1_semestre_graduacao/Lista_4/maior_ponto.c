#include <stdio.h>
#include <stdlib.h>

int main(){

    int  x[5],y[5];
    int i,xfinal,yfinal;
    float media,maior=0;
	
	for (i=0;i<5;i++){
	    scanf("%d",&x[i]);
	    scanf("%d",&y[i]);
	}
	
	for (i=0;i<5;i++){
	    media=(float)(x[i]+y[i])/2;
	    if (media>maior){
	        maior=media;
	        xfinal=x[i];
	        yfinal=y[i];
	    }
	}
	
	printf("%.2f %d %d",maior,xfinal,yfinal);
	
    return 0;

}