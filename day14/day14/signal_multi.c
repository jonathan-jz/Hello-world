#include <func.h>
typedef __sighandler_t sighandler_t;
void handler(int num){
    printf("before num = %d\n", num);
    sleep(1);
    printf("after num = %d\n", num);
}
int main(){
    sighandler_t ret = signal(SIGINT,handler);
    ERROR_CHECK(ret,SIG_ERR,"signal");
    signal(SIGQUIT,handler);
    handler(5);
    //while(1);
}