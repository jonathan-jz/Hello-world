#include<func.h>
int main(int argc,char*argv[]){
    ARGS_CHECK(argc,2);
    int fd =  open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    printf("fd = %d\n",fd);
    //close(0);
    int newfd =dup(fd);
    
    printf("newfd = %d\n",newfd);

    write(fd,"hello",5);
    write(newfd," world",6);

    close(fd);
    close(newfd);

    return 0;
}