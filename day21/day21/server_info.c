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
    int netFd = accept(sockFd,(struct sockaddr *)&clientAddr,&clientAddrLen);
    ERROR_CHECK(netFd,-1,"accept");
    printf("addrLen = %d\n", clientAddrLen);
    printf("client family = %d\n", clientAddr.sin_family);
    printf("client ip = %s\n",inet_ntoa(clientAddr.sin_addr));
    printf("client port = %d\n",ntohs(clientAddr.sin_port));
    ret = send(netFd,"hello",5,0);
    ERROR_CHECK(ret,-1,"send");
    char buf[100] = {0};
    ret = recv(netFd,buf,100,0);
    ERROR_CHECK(ret,-1,"recv");
    puts(buf);
}