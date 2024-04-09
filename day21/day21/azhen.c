#include <func.h>
int main(int argc, char *argv[]){
    // ./inet_aton 192.168.4.163 1234
    ARGS_CHECK(argc,3);
    int sockFd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;//这是一个IPv4的地址
    addr.sin_port = htons(atoi(argv[2]));//"1234" --> 1234 --> 大端
    //inet_aton(argv[1],&addr.sin_addr);
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    int optval = 1;
    int ret = setsockopt(sockFd,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(int));
    ERROR_CHECK(ret,-1,"setsockopt");
    ret = bind(sockFd,(struct sockaddr *)&addr,sizeof(addr));
    ERROR_CHECK(ret,-1,"bind");
    ret = listen(sockFd,10);
    ERROR_CHECK(ret,-1,"listen");
    int netFd = accept(sockFd,NULL,NULL);
    ERROR_CHECK(netFd,-1,"accept");
    char buf[4096];
    fd_set rdset;
    while(1){
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        FD_SET(netFd,&rdset);
        select(netFd+1,&rdset,NULL,NULL,NULL);
        if(FD_ISSET(STDIN_FILENO,&rdset)){
            bzero(buf,sizeof(buf));
            int ret = read(STDIN_FILENO,buf,sizeof(buf));
            ERROR_CHECK(ret,-1,"read");
            if(ret == 0){
                break;
            }
            send(netFd,buf,strlen(buf),0);
        }
        if(FD_ISSET(netFd,&rdset)){
            bzero(buf,sizeof(buf));
            int ret = recv(netFd,buf,sizeof(buf),0);
            ERROR_CHECK(ret, -1, "recv");
            puts(buf);
        }
    }
    close(netFd);
    close(sockFd);
}