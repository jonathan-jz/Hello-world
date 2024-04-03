#include <func.h>
void *threadFunc(void *arg){
    time_t now = time(NULL);
    char buf[128] = {0};
    ctime_r(&now,buf);
    printf("before child thread, time = %s\n", buf);
    sleep(5);
    printf("after child thread, time = %s\n", buf);
    pthread_exit(NULL);
}
int main(){
    pthread_t tid1;
    pthread_create(&tid1,NULL,threadFunc,NULL);
    sleep(2);
    time_t mainNow = time(NULL);
    char buf[128] = {0};
    ctime_r(&mainNow, buf);
    printf("main thread, time = %s\n", buf);
    pthread_join(tid1,NULL);
}