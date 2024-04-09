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
    setNonBlock(STDIN_FILENO);
    char buf[64] = {0};
    read(STDIN_FILENO, buf, sizeof(buf));
    return 0;
}

