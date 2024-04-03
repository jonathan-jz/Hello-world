#include <func.h>
typedef struct shareRes_s{
    pthread_mutex_t mutex;
} shareRes_t;
void * threadFunc(void *p){
    shareRes_t * pShareRes = (shareRes_t *)p;
    pthread_mutex_lock(&pShareRes->mutex);
    printf("I am child thread\n");
}
int main(){
    pthread_t tid;
    shareRes_t shareRes;
    pthread_mutex_init(&shareRes.mutex,NULL);
    pthread_create(&tid,NULL,threadFunc,(void *)&shareRes);
    sleep(1);
    pthread_mutex_lock(&shareRes.mutex);
    printf("I am main thread\n");
    pthread_mutex_unlock(&shareRes.mutex);
}