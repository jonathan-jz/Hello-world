#include<func.h>

int main(int argc,char*argv[]){
    ARGS_CHECK(argc,2);
    int fd = open(argv[1],O_CREAT|O_RDWR,0666);
    ERROR_CHECK(fd,-1,"open");
    lseek(fd,100,SEEK_SET);
    write(fd,"hello",5);
    close(fd);

    return 0;
}