#include <func.h>
void func1(int num){
    printf("func1\n");
}
void func2(int num, siginfo_t * info, void * p){
    //printf("pid = %d\n", info->si_pid);
    //printf("uid = %d\n", info->si_uid);
    printf("before num = %d\n", num);
    sleep(2);
    printf("after num = %d\n", num);
    sigset_t set;
    sigpending(&set);
    if(sigismember(&set,SIGQUIT)){
        printf("SIGQUIT is pending!\n");
    }
    else{
        printf("SIGQUIT is not pending!\n");
    }
}
int main(){
    struct sigaction act;
    memset(&act,0,sizeof(act));
    //act.sa_flags = 0;
    //act.sa_handler = func1;
    //act.sa_flags = SA_SIGINFO|SA_NODEFER;
    act.sa_flags = SA_SIGINFO|SA_RESTART;
    sigfillset(&act.sa_mask);//设置递送过程中额外屏蔽的信号
    act.sa_sigaction = func2;
    sigaction(SIGINT,&act,NULL);
    //while(1);
    char buf[1024] = {0};
    read(STDIN_FILENO,buf,sizeof(buf));
    printf("buf = %s\n", buf);
}