#include <func.h>
int main(int argc, char *argv[]){
    // ./redir1 file1
    ARGS_CHECK(argc,2);
    printf("I can see you!\n");
    close(1);
    int fd = open(argv[1], O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    printf("%d\n",fd);
    printf("I can't see you!\n");

}