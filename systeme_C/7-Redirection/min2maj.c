#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        int fd_in = open(argv[1], O_RDONLY, 0644);
        dup2(fd_in, STDIN_FILENO);
        close(fd_in);
    }
    if(argc > 2){
        int fd_out = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0644);
        dup2(fd_out, STDOUT_FILENO);
        close(fd_out);
    }
    execl("/usr/bin/tr", "tr", "[a-z]", "[A-Z]", NULL);
}