#include <head.h>

int main(int argc, char **argv)
{
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    ERROR_CHECK(sfd, -1, "socket");

    struct sockaddr_in serAddr;
    memset(&serAddr, 0, sizeof(serAddr));
    serAddr.sin_family = AF_INET;
    serAddr.sin_addr.s_addr = inet_addr(argv[1]);
    serAddr.sin_port = htons(atoi(argv[2]));

    //客户端连接服务端
    int ret = connect(sfd, (struct sockaddr*)&serAddr, sizeof(serAddr));
    ERROR_CHECK(ret, -1, "connect");

    ret = send(sfd, "helloserver", 11, 0);
    ERROR_CHECK(ret, -1, "send");

    char buf[64] = {0};
    ret = recv(sfd, buf, sizeof(buf), 0);
    printf("buf = %s\n", buf);

    close(sfd);
    return 0;
}

