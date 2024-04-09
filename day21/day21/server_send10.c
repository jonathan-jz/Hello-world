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
    int ret = bind(sockFd,(struct sockaddr *)&addr,sizeof(addr));
    ERROR_CHECK(ret,-1,"bind");
    ret = listen(sockFd,10);
    ERROR_CHECK(ret,-1,"listen");
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    int netFd = accept(sockFd,NULL,NULL);
    ERROR_CHECK(netFd,-1,"accept");
    ret = send(netFd,"helloworld",10,0);
    ERROR_CHECK(ret,-1,"send");
}