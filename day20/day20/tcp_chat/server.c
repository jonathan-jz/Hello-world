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

    //设置地址可重用，reuse>0表示地址可重用选项生效
    int reuse = 1;
    setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    int ret = bind(sfd, (struct sockaddr *)&serAddr, sizeof(serAddr));
    ERROR_CHECK(ret, -1, "bind");

    //监听的最大连接数量是10
    ret = listen(sfd, 10);
    ERROR_CHECK(ret, -1, "listen");

    //接收对端的连接请求
    int newFd = accept(sfd, NULL, NULL);
    ERROR_CHECK(newFd, -1, "accept");

    fd_set rdset;
    //清空结合
    FD_ZERO(&rdset);

    char buf[64] = {0};
    int readyNum = 0;
    while(1){
        //将标准输入加入到读集合
        FD_SET(STDIN_FILENO, &rdset);
        //将newFd加入到集合
        FD_SET(newFd, &rdset);
        readyNum = select(newFd+1, &rdset, NULL, NULL, NULL);

        for(int i = 0; i < readyNum; ++i){
            //如果是STDIN_FILENO就绪，就说明要给对端发送数据
            if(FD_ISSET(STDIN_FILENO, &rdset)){
                memset(buf, 0, sizeof(buf));
                read(STDIN_FILENO, buf, sizeof(buf));
                send(newFd, buf, strlen(buf)-1, 0);
            }

            //如果是newfd就绪。就说明对端有数据到来
            if(FD_ISSET(newFd, &rdset)){
                memset(buf, 0, sizeof(buf));
                ret = recv(newFd, buf, sizeof(buf)-1, 0);
                if(0 == ret){
                    close(newFd);
                    FD_CLR(newFd, &rdset);
                    printf("byebye\n");
                    break;
                }
                printf("buf = %s\n", buf);
            }
        }
    }

    close(sfd);
    close(newFd);
    return 0;
}

