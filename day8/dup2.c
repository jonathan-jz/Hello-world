#include <func.h>
int main(int argc, char *argv[]){
    // ./dup file1
    ARGS_CHECK(argc,2);
    int fd = open(argv[1] , O_RDWR);
    ERROR_CHECK(fd, -1, "open");
    printf("fd = %d\n" ,fd);
    int newFd = dup(fd) ;
    //dup2(newFd,fd);

    //int newFd = dup(fd);
    printf("newFd = %d\n", newFd);
    write(fd,"hello",5);
    write(newFd,"world",5);
    close(fd);
    close(newFd);
}
