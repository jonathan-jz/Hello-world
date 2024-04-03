#include <head.h>

int main(int argc, char **argv)
{
    int sfd = socket(AF_INET, SOCK_DGRAM, 0);
    ERROR_CHECK(sfd, -1, "socket");

    struct sockaddr_in serAddr;
    memset(&serAddr, 0, sizeof(serAddr));
    serAddr.sin_family = AF_INET;
    serAddr.sin_addr.s_addr = inet_addr(argv[1]);
    serAddr.sin_port = htons(atoi(argv[2]));

    int ret = bind(sfd, (struct sockaddr*)&serAddr, sizeof(serAddr));
    ERROR_CHECK(ret, -1, "bind");

    struct sockaddr_in cliAddr;
    memset(&cliAddr, 0, sizeof(cliAddr));
    
    socklen_t len;
    len = sizeof(cliAddr);

    char buf[4] = {0};
    recvfrom(sfd, buf, sizeof(buf), 0, (struct sockaddr *)&cliAddr, &len);
    printf("buf = %s\n", buf);

    recvfrom(sfd, buf, sizeof(buf), 0, (struct sockaddr *)&cliAddr, &len);
    printf("buf = %s\n", buf);

    sendto(sfd, "helloclient", 11, 0, (struct sockaddr *)&cliAddr, len);

    close(sfd);

    return 0;
}

