#include <func.h>
int main(int argc, char *argv[]){
    //./writeBlock 1.pipe
    ARGS_CHECK(argc,2);
    int fdr = open(argv[1], O_RDWR);
    int fdw = open(argv[1], O_RDWR);
    puts("pipe open!");
    fd_set rdset;
    fd_set wrset;
    int cnt = 0;
    char buf[4096] = {0};
    while(1){
        FD_ZERO(&rdset);
        FD_SET(fdr,&rdset);
        FD_ZERO(&wrset);
        FD_SET(fdw,&wrset);
        select(fdw+1,&rdset,&wrset,NULL,NULL);
        if(FD_ISSET(fdr,&rdset)){
            printf("read , cnt = %d\n", cnt++);
            read(fdr,buf,2048);
        }
        if(FD_ISSET(fdw, &wrset)){
            printf("write, cnt = %d\n", cnt++);
            write(fdw,buf,4097);
        }
        usleep(100000);
    }
    close(fdr);
    close(fdw);
}