#include <func.h>
int main(){
    sigset_t set;
    sigfillset(&set);
    sigset_t oldSet;
    sigprocmask(SIG_SETMASK,&set,&oldSet);
    printf("block all!\n");
    sleep(10);
    printf("unblock all!\n");
    sigprocmask(SIG_SETMASK,&oldSet,NULL);
    while(1);
}