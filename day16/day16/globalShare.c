#include <func.h>
int global = 1000;
void *threadFunc(void *arg){
    printf("child thread global = %d\n", global);
}
int main(){
    pthread_t tid;
    int ret = pthread_create(&tid,NULL,threadFunc,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_create");
    sleep(1);
    // printf("%d",global);
    global = 200;
    printf("main thread global = %d\n", global);
    sleep(1);
}