#include <func.h>
int main(int argc, char *argv[]){
    // ./redir2 file1
    ARGS_CHECK(argc,2);
    int fd = open(argv[1] , O_RDWR);
    ERROR_CHECK(fd, -1, "open");
    printf("\n");//先要输出一个换行
    close(STDOUT_FILENO);
    int newFd = dup(fd);
    printf("newFd = %d\n", newFd);
    close(fd);
    close(newFd);
}