#include <func.h>
int func(){
    //_Exit(-1);//_exit不会把FILE结构体的所有内容清空
    abort();//自己给自己发送了一个6号信号，缓冲区内容不会清空
}
int main(){
    pid_t ret = fork();
    if(ret == 0){
        printf("hello");
        func();
    }
    else{
        int status;
        printf("I am parent, pid = %d, ppid = %d\n",
            getpid(),getppid());
        wait(&status);
        if(WIFEXITED(status)){
            printf("exit code = %d\n", WEXITSTATUS(status));
        }
        else if(WIFSIGNALED(status)){
            printf("abnormal exit, termsig = %d\n", WTERMSIG(status));
        }
    }
}