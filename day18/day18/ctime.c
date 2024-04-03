#include <func.h>
void *threadFunc(void *arg){
    time_t now = time(NULL);
    char *p = ctime(&now);
    printf("before child thread, time = %s\n", p);
    sleep(5);
    printf("after child thread, time = %s\n", p);
    pthread_exit(NULL);
}
int main(){
    pthread_t tid1;
    pthread_create(&tid1,NULL,threadFunc,NULL);
    sleep(2);
    time_t mainNow = time(NULL);
    char *p = ctime(&mainNow);
    printf("main thread, time = %s\n", p);
    pthread_join(tid1,NULL);
}