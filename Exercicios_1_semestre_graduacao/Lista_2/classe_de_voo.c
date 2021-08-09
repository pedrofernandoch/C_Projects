#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){

char x;

scanf("%s",&x);
x=tolower(x);

if (x=='b'){
    printf("executiva");
}
if (x=='e'){
    printf("economica");
}
if (x=='p'){
    printf("primeira classe");
}
if (x!='b'&&x!='e'&&x!='p') {
    printf("classe desconhecida");
}

return 0;
}