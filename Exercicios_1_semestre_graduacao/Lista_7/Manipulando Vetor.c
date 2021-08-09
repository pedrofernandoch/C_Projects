#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int maior(int *, int, int, int);
int menor(int *, int, int, int);
int media(int *vetor, int, int, int);
int resultado(int *, int , int, int, int (*)(int *, int , int , int ));

int main(){

int tam,op,*vetor,(*pMaior)(int *,int,int, int),(*pMenor)(int *,int,int, int),(*pMedia)(int *,int, int, int),i,a=0;

pMaior=maior;
pMenor=menor;
pMedia=media;

scanf("%d %d",&tam,&op);

vetor=(int *) malloc(tam*sizeof(int));
assert(vetor);

for (i=0;i<tam;i++){
  scanf("%d",&vetor[i]);
}

if (op==1){
    printf("%d",pMenor(vetor,tam,a,tam));
    //printf("%d",resultado(vetor,tam,a,tam,menor));
}
if (op==2){
    printf("%d",pMaior(vetor,tam,a,tam));
    //printf("%d",resultado(vetor,tam,a,tam,maior));
}
if (op==3){
    printf("%d",pMedia(vetor,tam,a,tam));
   // printf("%d",resultado(vetor,tam,a,tam,media));
}

free(vetor);
  return 0;
}
int maior(int *vet,int tam,int a, int b){
    
    int aux;
    
    if (tam==1){
        return vet[0];
    }
    aux=maior(vet+1,tam-1,a,b);
    if (aux>vet[0]) return aux;
    return vet[0];
}
int menor(int *vet,int tam,int a, int b){
    
    int aux;
    
    if (tam==1){
        return vet[0];
    }
    aux=menor(vet+1,tam-1,a, b);
    if (aux<vet[0]) return aux;
    return vet[0];
}
int media(int *vet,int tam,int a, int b){

   if (tam>=0){
     a = a + vet[tam];
      return media(vet, tam-1, a, b);
   }
   else{
     return a/b;
   }

}

int resultado(int *vetor, int tam, int a,int b, int (*operador)(int *v, int t, int a, int b)){

  return operador(vetor,tam,a,b);
}