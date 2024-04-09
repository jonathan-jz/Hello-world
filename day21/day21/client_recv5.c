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
    char buf[100] = {0};
    ret = recv(sockFd,buf,5,0);
    ERROR_CHECK(ret,-1,"recv");
    puts(buf);
    bzero(buf,sizeof(buf));
    ret = recv(sockFd,buf,5,0);
    ERROR_CHECK(ret,-1,"recv");
    puts(buf);
}