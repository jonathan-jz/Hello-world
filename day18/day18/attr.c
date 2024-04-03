#include <func.h>
typedef struct shareRes_s{
    int num;
} shareRes_t; 
void *threadFunc(void *arg){
    pthread_exit(NULL);
}
int main(){
    pthread_t tid1;
    shareRes_t shareRes;
    shareRes.num = 0;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
    pthread_create(&tid1,&attr,threadFunc,(void *)&shareRes);
    int ret = pthread_join(tid1,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_join");
}