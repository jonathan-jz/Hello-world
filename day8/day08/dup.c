#include<func.h>
int main(int argc,char*argv[]){
    ARGS_CHECK(argc,2);
    int fd =  open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    // printf("fd = %d\n",fd);
    //close(0);
    printf("\n");

    close(STDOUT_FILENO);
    int newfd =dup(fd);
    
    printf("newfd = %d\n",newfd);

//    write(fd,"hello",5);
  //  write(fd,"world",5);

    close(fd);
    close(newfd);

    return 0;
}