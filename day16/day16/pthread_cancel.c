#include <func.h>
void * threadFunc(void *arg){
    while(1){
       //printf("I still alive!\n");
        pthread_testcancel();
    }
}
int main(){
    pthread_t tid;
    pthread_create(&tid,NULL,threadFunc,NULL);
    sleep(1);
    pthread_cancel(tid);
    void *ret;
    pthread_join(tid,&ret);
    printf("You dies, ret = %ld\n", (long)ret);
}