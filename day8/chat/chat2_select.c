#include <func.h>
int main(int argc, char *argv[])
{
    // ./chat2 1.pipe 2.pipe
    ARGS_CHECK(argc, 3);
    int fdr = open(argv[1], O_RDONLY);
    ERROR_CHECK(fdr, -1, "open fdr");
    int fdw = open(argv[2], O_WRONLY);
    ERROR_CHECK(fdw, -1, "open fdw");
    puts("chat established!");
    fd_set rdset;
    struct timeval timeout;
    char buf[2048] = {0};
    while (1)
    {
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO, &rdset);
        FD_SET(fdr, &rdset);
        timeout.tv_sec = 3;
        timeout.tv_usec = 0;
        int sret = select(fdr + 1, &rdset, NULL, NULL, &timeout);
        if(sret == 0){
            printf("time out!\n");
            continue;
        }
        if (FD_ISSET(fdr, &rdset))
        {
            printf("Messsage from pipe!\n");
            memset(buf, 0, sizeof(buf));
            read(fdr, buf, sizeof(buf));
            puts(buf);
        }
        if (FD_ISSET(STDIN_FILENO, &rdset))
        {
            printf("Messsage from stdin!\n");
            memset(buf, 0, sizeof(buf));
            int ret = read(STDIN_FILENO, buf, sizeof(buf));
            if(ret == 0){
                printf("I quit!\n");
                write(fdw,"nishigehaoren", 13);
                break;
            }
            write(fdw, buf, strlen(buf));
        }
    }
    close(fdw);
    close(fdr);
}