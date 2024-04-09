#include <func.h>
int main(int argc, char *argv[]){
    // ./open file1
    ARGS_CHECK(argc,2);
    int fd = open(argv[1], O_RDONLY);
    ERROR_CHECK(fd,-1,"open");
    printf("fd = %d\n", fd);
    char buf[1024] = {0};
    int ret = read(fd,buf,sizeof(buf));
    ERROR_CHECK(ret,-1,"read");
    puts(buf);
    printf("ret = %d\n", ret);
    close(fd);
    
}