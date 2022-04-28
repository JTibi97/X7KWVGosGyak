#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

int ret;

printf("System call\n");

ret = system("Ez egy hibás parancs");

printf("ret= %d\n", ret);

return 0;



}
