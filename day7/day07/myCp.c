#include <func.h>
int main(int argc, char *argv[]){
    // ./myCp src dest
    ARGS_CHECK(argc,3);
    int fdr = open(argv[1], O_RDONLY);
    ERROR_CHECK(fdr,-1,"open fdr");
    int fdw = open(argv[2], O_WRONLY|O_CREAT,0666);
    ERROR_CHECK(fdw,-1,"open fdw");
    char buf[4096] = {0};
    while(1){
        memset(buf,0,sizeof(buf));
        int ret = read(fdr,buf,sizeof(buf));
        ERROR_CHECK(ret, -1, "read");
        if(ret == 0){
            break;
        }
        write(fdw,buf,ret); //写入的数量由读取的数量决定的。
    }
    close(fdr);
    close(fdw);
}