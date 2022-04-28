#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[])
{

char str[50];

for(int i=0;;i++){

printf("Kérem adja meg a %d. parancsot\n",i+1);
scanf("%s",str);
system(str);

}

printf("hello");
return 0;

}
