#include <func.h>
int main(int argc, char *argv[]){
    // ./redir3 file1
    ARGS_CHECK(argc,2);
    int fd = open(argv[1] , O_RDWR);
    ERROR_CHECK(fd, -1, "open");
    printf("You can see me!\n");
    dup2(STDOUT_FILENO,5);
    dup2(fd,STDOUT_FILENO);
    printf("You can't see me!\n");
    dup2(5,STDOUT_FILENO);
    printf("You can see me!\n");
    close(fd);
}