#include <head.h>

void setNonBlock(int fd)
{
    int state;
    //获取当前描述符的状态
    state = fcntl(fd, F_GETFL);

    //将文文件描述符的状态设置为非阻塞的
    state |= O_NONBLOCK;
    fcntl(fd,  F_SETFL, state);
}

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
    //创建epoll
    int epfd = epoll_create(1);
    ERROR_CHECK(epfd, -1, "epoll_create");

    struct epoll_event event, evs[2];
    memset(&event, 0, sizeof(event));
    memset(evs, 0, sizeof(evs));
    //监听文件描述符的读事件
    event.events = EPOLLIN;
    event.data.fd = STDIN_FILENO;

    //把STDIN_FILENO加入到监听集合中
    ret = epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &event);
    ERROR_CHECK(ret, -1, "epoll_ctl");

    //将newFd设置为边缘触发模式
    event.events = EPOLLIN|EPOLLET;
    event.data.fd = newFd;
    ret = epoll_ctl(epfd, EPOLL_CTL_ADD, newFd, &event);
    ERROR_CHECK(ret, -1, "epoll_ctl");

    char buf[6] = {0};
    int readyNum = 0;
    while(1){
        readyNum = epoll_wait(epfd, evs, 2, 5000);
        printf("after wait\n");

        for(int i = 0; i < readyNum; ++i){
            if(evs[i].data.fd == STDIN_FILENO){
                memset(buf, 0, sizeof(buf));
                read(STDIN_FILENO, buf, sizeof(buf));
                send(newFd, buf, strlen(buf)-1, 0);
            }

            //如果是newfd就绪。就说明对端有数据到来
            if(evs[i].data.fd == newFd){
                memset(buf, 0, sizeof(buf));

                //将newFd设置为非阻塞的
                /* setNonBlock(newFd); */
                while(1){
                    //第二种方式将recv设置为非阻塞的
                    ret = recv(newFd, buf, sizeof(buf)-1, MSG_DONTWAIT);
                    if(0 == ret){
                        printf("byebye\n");
                        close(newFd);
                        break;
                    }

                    if(-1 == ret){
                        break;
                    }
                    printf("buf = %s\n", buf);
                }
            }
        }
    }

    close(sfd);
    close(newFd);
    return 0;
}

