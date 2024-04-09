#include <func.h>
int main(int argc, char *argv[]){
    // ./inet_aton 192.168.4.163 1234
    ARGS_CHECK(argc,3);
    int sockFd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;//这是一个IPv4的地址
    addr.sin_port = htons(atoi(argv[2]));//"1234" --> 1234 --> 大端
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    int ret = connect(sockFd,(struct sockaddr *)&addr,sizeof(addr));
    ERROR_CHECK(ret,-1,"connect");
    char buf[4096];
    fd_set rdset;
    while(1){
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        FD_SET(sockFd,&rdset);
        select(sockFd+1,&rdset,NULL,NULL,NULL);
        if(FD_ISSET(STDIN_FILENO,&rdset)){
            bzero(buf,sizeof(buf));
            int ret = read(STDIN_FILENO,buf,sizeof(buf));
            ERROR_CHECK(ret,-1,"read");
            send(sockFd,buf,strlen(buf),0);
        }
        if(FD_ISSET(sockFd,&rdset)){
            bzero(buf,sizeof(buf));
            int ret = recv(sockFd,buf,sizeof(buf),0);
            ERROR_CHECK(ret, -1, "recv");
            if(ret == 0){
                break;
            }
            puts(buf);
        }
    }
    close(sockFd);
}