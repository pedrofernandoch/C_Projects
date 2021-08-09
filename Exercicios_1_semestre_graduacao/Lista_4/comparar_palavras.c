#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 20

int main()
{
    int op,i,soma1=0,soma2=0,count=0,count1=0,count2=0,flag1=0,flag2=0;
    char palavra1[MAX],palavra2[MAX];
    char letra;
    
    scanf("%d",&op);
    
    if (op==1){
        scanf("%s\n",palavra1);
        scanf("%s",palavra2);
        if (strlen(palavra1)>strlen(palavra2)){
            printf("1");
        }
        if (strlen(palavra1)<strlen(palavra2)){
            printf("2");
        }
        if (strlen(palavra1)==strlen(palavra2)){
            printf("0");
        }
    }
    if (op==2){
        scanf("%s\n",palavra1);
        scanf("%s",palavra2);
        for (i=0;i<MAX;i++){
        palavra1[i]= toupper(palavra1[i]);
        palavra2[i]= toupper(palavra2[i]);
        }
        for (i=0;i<MAX;i++){
            
            if (palavra1[i]<palavra2[i]){
                printf("1");
                return 0;
            }
            if (palavra1[i]>palavra2[i]){
                printf("2");
                return 0;
            }
            if (palavra1[i]==palavra2[i]){
                count++;
            }
            if (count==strlen(palavra1)&&count==strlen(palavra2)){
                printf("0");
                return 0;
            }
        }
    }
    if (op==3){
        
        scanf("%s\n",palavra1);
        scanf("%s",palavra2);
        
        for (i=0;i<strlen(palavra1);i++){
            soma1+=palavra1[i];           
        }
        for (i=0;i<strlen(palavra2);i++){
            soma2+=palavra2[i];        
        }
            if (soma1>soma2){
                printf("1");
            }
            if (soma1<soma2){
                printf("2");
            }
            if (soma1==soma2){
                printf("0");
            }
    }
    
    if (op==4){
        
        scanf("%s\n",palavra1);
        scanf("%s\n",palavra2);
        scanf("%c",&letra);
        
        for (i=0;i<strlen(palavra1);i++){
            if (letra==palavra1[i]){
                count1++;
            }
        }
        for (i=0;i<strlen(palavra2);i++){
            if (letra==palavra2[i]){
                count2++;
            }
        }
        if (count1>count2){
            printf("1");
        }
        if (count1<count2){
            printf("2");
        }
        if (count1==count2){
            printf("0");
        }
    }
    
    if (op==5){
        scanf("%s\n",palavra1);
        scanf("%s\n",palavra2);
        scanf("%c",&letra);

        for (i=0;i<MAX;i++){
            if (palavra1[i]==letra){
                flag1=1;
            }
            if (palavra2[i]==letra){
                flag2=1;
            }
            if (flag1==1&&flag2==0){
                printf("1");
                return 0;
            }
            if (flag1==0&&flag2==1){
                printf("2");
                return 0;
            }
            if (flag1==1&&flag2==1){
                printf("0");
                return 0;
            }
            
        }
        
    }
 
    return 0;
}