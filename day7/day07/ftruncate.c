#include <func.h>
int main(int argc, char *argv[]){
    // ./open file1
    ARGS_CHECK(argc,2);
    int fd = open(argv[1], O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    printf("fd = %d\n", fd);
    int ret = ftruncate(fd,24);
    printf("%d\n",ret);
    ERROR_CHECK(ret,-1,"ftruncate");
    close(fd);  
      
}
