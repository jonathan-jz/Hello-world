#include <func.h>
int main(){
    pid_t ret = fork();
    if(ret == 0){
        setpgid(0,0);//子进程单独成立一个进程组
        printf("I am child, pid = %d, ppid = %d, pgid = %d\n",
            getpid(),getppid(), getpgid(0));
        while(1);
    }
    else{
        printf("I am parent, pid = %d, ppid = %d, pgid = %d\n",
            getpid(),getppid(), getpgid(0));
        printf("the pgid of bash = %d\n", getpgid(getppid()));
        wait(NULL);
    }
}