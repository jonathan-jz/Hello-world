#include <func.h>
int main(int argc, char *argv[]){
    // ./chat1 1.pipe 2.pipe 
    ARGS_CHECK(argc,3);
    int fdw = open(argv[1], O_WRONLY);
    ERROR_CHECK(fdw, -1, "open fdw");
    int fdr = open(argv[2], O_RDONLY);
    ERROR_CHECK(fdr, -1, "open fdr");
    puts("chat established!");
    char buf[2048] = {0};
    while (1)
    {
        memset(buf,0,sizeof(buf));//读的时候内存有多大就读多少
        read(STDIN_FILENO,buf,sizeof(buf));
        write(fdw,buf,strlen(buf));//写的时候有多少实际内容就写多少
        memset(buf,0,sizeof(buf));
        read(fdr,buf,sizeof(buf));
        puts(buf);
    }
    
    close(fdw);
    close(fdr);
}