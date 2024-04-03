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
    
    fd_set rdset;
    //清空结合
    FD_ZERO(&rdset);

    char buf[64] = {0};

    recvfrom(sfd, buf, sizeof(buf), 0, (struct sockaddr *)&cliAddr, &len);
    printf("buf = %s\n", buf);

    int readyNum = 0;
    while(1){
        //将标准输入加入到读集合
        FD_SET(STDIN_FILENO, &rdset);
        //将newFd加入到集合
        FD_SET(sfd, &rdset);
        readyNum = select(sfd+1, &rdset, NULL, NULL, NULL);
        for(int i = 0; i < readyNum; ++i){
            if(FD_ISSET(STDIN_FILENO, &rdset)){
                memset(buf, 0, sizeof(buf));
                read(STDIN_FILENO, buf, sizeof(buf));
                ret = sendto(sfd, buf, strlen(buf)-1, 0, (struct sockaddr *)&cliAddr, len);
                ERROR_CHECK(ret, -1, "sendto");
            }
            if(FD_ISSET(sfd, &rdset)){
                memset(buf, 0, sizeof(buf));
                recvfrom(sfd, buf, sizeof(buf), 0, (struct sockaddr *)&cliAddr, &len);
                printf("buf = %s\n", buf);
            }
        }
           
    }

    close(sfd);

    return 0;
}

