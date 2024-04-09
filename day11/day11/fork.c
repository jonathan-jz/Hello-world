#include <func.h>
int main(){
    pid_t ret = fork();
    if(ret == 0){
        printf("I am child, pid = %d, ppid = %d\n",
            getpid(),getppid());
    }
    else{
        printf("I am parent, pid = %d, ppid = %d\n",
            getpid(),getppid());
        //sleep(1);
        wait(NULL);
    }
}