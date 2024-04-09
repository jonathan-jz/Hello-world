#include <func.h>
int main(int argc, char *argv[]){
    // ./open file1
    ARGS_CHECK(argc,2);
    //int fd = open(argv[1], O_RDONLY);
    //int fd = open(argv[1], O_RDONLY|O_CREAT, 0666);//创建文件受到掩码的影响
    int fd = open(argv[1], O_RDWR|O_CREAT|O_EXCL, 0666);
    ERROR_CHECK(fd,-1,"open");
    printf("fd = %d\n", fd);
    close(fd);    
    
}