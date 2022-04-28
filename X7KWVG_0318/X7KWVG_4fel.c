#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int pid = fork();
    char *args[] = {NULL};
    
    
    
    if(pid == 0) {
        system("exec ls -1");
    } else {
        wait(NULL);
        printf("A gyermek processz lefutott.\n");
    }

    
    return 0;
}
