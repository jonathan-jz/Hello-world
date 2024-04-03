#include <func.h>
//#include <errno.h>
void * threadFunc(void *p){
    while(1){
        sleep(1);
    }
}
int main(){
    //printf("%s\n", strerror(EPERM));
    for(int i = 0;; ++i){
        pthread_t tid;
        int ret = pthread_create(&tid,NULL,threadFunc,NULL);
        if(ret != 0){
            printf("i = %d\n", i);
        }
        THREAD_ERROR_CHECK(ret,"pthread_create");
    }
}