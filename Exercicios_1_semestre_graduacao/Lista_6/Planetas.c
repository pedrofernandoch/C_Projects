#include <stdio.h>
#include <stdlib.h>
#define MAX 15

void calculaTempo(int, char *, int *, int *, int *, int *);

int main(void) {

  int tempo,dia,hora,min,seg;
  char planeta[MAX];

 scanf("%d %s",&tempo, planeta);

 calculaTempo(tempo, planeta, &dia ,&hora, &min, &seg);

 printf("%d segundos no planeta %s equivalem a:\n",tempo,planeta);
 printf("%d dias, %d horas, %d minutos e %d segundos\n",dia,hora,min,seg);

  return 0;
}

void calculaTempo(int tempo, char *planeta, int *dia, int *hora, int *min, int *seg){

  int resto;

if (planeta[0]=='T'){
    *dia = tempo/86400;
    resto = tempo % 86400;
    *hora = resto / 3600;
    resto = resto % 3600;
    *min = resto / 60;
    *seg = resto % 60;
}
else if (planeta[0]=='M'){
        *dia = tempo/5068800;
        resto = tempo % 5068800;
        *hora = resto / 3600;
        resto = resto % 3600;
        *min = resto / 60;
        *seg = resto % 60;
}
else if (planeta[0]=='J'){
        *dia = tempo/35760;
        resto = tempo % 35760;
        *hora = resto / 3600;
        resto = resto % 3600;
        *min = resto / 60;
        *seg = resto % 60;
  
}
else {
      *dia = tempo/20995200;
      resto = tempo % 20995200;
      *hora = resto / 3600;
      resto = resto % 3600;
      *min = resto / 60;
      *seg = resto % 60;
}

}