#include <func.h>
int main(int argc, char *argv[]){
    // ./chat1 1.pipe 2.pipe 
    ARGS_CHECK(argc,3);
    int fdw = open(argv[1], O_WRONLY);
    ERROR_CHECK(fdw, -1, "open fdw");
    int fdr = open(argv[2], O_RDONLY);
    ERROR_CHECK(fdr, -1, "open fdr");
    puts("chat established!");
    fd_set rdset;
    char buf[2048] = {0};
    while (1)
    {
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        FD_SET(fdr,&rdset);
        select(fdr + 1, &rdset, NULL, NULL, NULL);
        if (FD_ISSET(fdr, &rdset))
        {
            printf("Messsage from pipe!\n");
            memset(buf, 0, sizeof(buf));
            int ret = read(fdr, buf, sizeof(buf));
            if(ret == 0){
                puts("hehe");
                break;
            }
            puts(buf);
        }
        if (FD_ISSET(STDIN_FILENO, &rdset))
        {
            printf("Messsage from stdin!\n");
            memset(buf, 0, sizeof(buf));
            read(STDIN_FILENO, buf, sizeof(buf));
            write(fdw, buf, strlen(buf));
        }
    }
    close(fdw);
    close(fdr);
}