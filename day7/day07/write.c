#include <func.h>
int main(int argc, char *argv[]){
    // ./open file1
    ARGS_CHECK(argc,2);
    int fd = open(argv[1], O_WRONLY|O_CREAT, 0666);
    ERROR_CHECK(fd,-1,"open");
    printf("fd = %d\n", fd);
    int val = 10000000;
    int ret = write(fd,&val,sizeof(val));
    ERROR_CHECK(ret,-1,"write");
    printf("ret = %d\n", ret);
    close(fd);
}