#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    char str[] = "Juhasz Tibor";

    int fd;
    int pid = fork();
    if(pid == -1){
        printf("Hiba a forkolas kozben.\n");
        return 1;
    }

    if(pid == 0){
        //child
        fd = open("x7kwvg", O_WRONLY);
        
        if(write(fd, str, sizeof(str)) == -1){
            printf("Hiba a fifo-ba iras kozben\n");
            return 2;
        }    
        close(fd);

    } else {
        //parent
        if(mkfifo("x7kwvg", 0777) == -1){
            if(errno != EEXIST){
                printf("Hiba a fifo letrehozasa kozben\n");
                return 3;
            }
        }
        fd = open("x7kwvg", O_RDONLY);
        
        char str2[20];

        read(fd, str2, sizeof(str2));
        printf("Olvasas eredmenye: %s\n", str2);
        close(fd);
        wait(NULL);

    }

    return 0;
}
