#include <func.h>
int main(int argc, char *argv[]){
    ARGS_CHECK(argc,2);
    int fd = open(argv[1], O_RDWR|O_CREAT, 0666);
    ERROR_CHECK(fd,-1,"open");
    lseek(fd,4,SEEK_SET);
    write(fd,"1555",4);
    close(fd);
    return 0;
}

