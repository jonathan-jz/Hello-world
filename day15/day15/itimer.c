#include <func.h>
void handler(int signum){
    printf("signum = %d ", signum);
    time_t now = time(NULL);
    printf("%s\n", ctime(&now));
}
int main(){
    //signal(SIGALRM,handler);
    signal(SIGPROF,handler);
    struct itimerval timer;
    timer.it_value.tv_sec = 3;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;
    //setitimer(ITIMER_REAL,&timer,NULL);
    setitimer(ITIMER_PROF,&timer,NULL);
    handler(0);
    while(1);
}