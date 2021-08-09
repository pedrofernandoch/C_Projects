#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

int main(){

    char comando[MAX];
    int i,position=1,countD=0,countE=0,count;
    
    scanf("%s",comando);

    for (i=0;i<strlen(comando);i++){
        if (comando[i]=='D'){
            countD++;
        }
        else{
            countE++;
        }
    } 
    
    count = countD - countE;
    
    if (count==0){
        printf("Norte");
        return 0;
    }
    
    if (count>0){
        for (i=1;i<=count;i++){
            if (position<=4){
                position+=1; 
            }
            if (position>4){
                position=1;
            }
        }
    }
    
    if (count<0){
        for (i=1;i<=(count*-1);i++){
            if (position<=1){
              position-=1;
            }
            if (position<-3){
              position=0;
            }
            
        }
    }
    
    if (position==1 || position==-3){
        printf("Norte");
    }
    if (position==2 || position==-2){
        printf("Leste");
    }
    if (position==3 || position==-1){
        printf("Sul");
    }
    if (position==4 || position==0){
        printf("Oeste");
    }
	
    return 0;
}