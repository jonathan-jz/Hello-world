#include <func.h>
int main(){
    int fds1[2];
    int fds2[2];
    pipe(fds1);
    pipe(fds2);
    if(fork() == 0){
        //fds1 子向父通信
        close(fds1[0]);//子关闭fds1的读
        //fds2 父向子通信
        close(fds2[1]);//子关闭fds2的写
        char buf[10] = {0};
        read(fds2[0],buf,sizeof(buf));
        printf("I am child, buf = %s\n", buf);
        write(fds1[1], "nihao", 5);
        exit(0);
    }
    else{
        //fds1 子向父通信
        close(fds1[1]);//父关闭fds1的写
        //fds2 父向子通信
        close(fds2[0]);//父关闭fds2的读
        write(fds2[1],"hello", 5);
        char buf[10] = {0};
        read(fds1[0],buf,sizeof(buf));
        printf("I am parent, buf = %s\n", buf);
        wait(NULL);
    }
}