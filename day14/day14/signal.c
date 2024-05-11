#include <func.h>
typedef __sighandler_t sighandler_t;
void handler(int num){
    printf("num = %d\n", num);
    //signal(SIGINT,SIG_DFL);//default
}
int main(){
    //sleep(5);
    //puts("wake up");
    sighandler_t ret = signal(SIGINT,handler);
    //sighandler_t ret = signal(SIGINT,SIG_IGN);
    ERROR_CHECK(ret,SIG_ERR,"signal");
    //signal(SIGQUIT,handler);
    while(1);
}