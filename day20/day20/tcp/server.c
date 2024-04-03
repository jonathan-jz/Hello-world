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

    int ret = bind(sfd, (struct sockaddr *)&serAddr, sizeof(serAddr));
    ERROR_CHECK(ret, -1, "bind");

    //监听的最大连接数量是10
    ret = listen(sfd, 10);
    ERROR_CHECK(ret, -1, "listen");

    //接收对端的连接请求
    int newFd = accept(sfd, NULL, NULL);
    ERROR_CHECK(newFd, -1, "accept");


    char buf[4] = {0};
    ret = recv(newFd, buf, sizeof(buf), 0);
    printf("buf = %s\n", buf);

    ret = recv(newFd, buf, sizeof(buf), 0);
    printf("buf = %s\n", buf);

    ret = recv(newFd, buf, sizeof(buf), 0);
    printf("buf = %s\n", buf);

    ret = send(newFd, "helloclient", 11, 0);
    ERROR_CHECK(ret, -1, "send");

    close(sfd);
    close(newFd);
    return 0;
}

