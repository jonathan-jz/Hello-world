#include <func.h>
typedef struct shareRes_s{
    int num;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} shareRes_t; 
void *threadFunc(void *arg){
    printf("I am child thread, tid = %lu\n",
        pthread_self());
    shareRes_t *pShareRes = (shareRes_t *)arg;
    pthread_mutex_lock(&pShareRes->mutex);
    //if(pShareRes->num == 0){
    while(pShareRes->num == 0){
        puts("wait");//为了防止虚假唤醒，这里要使用while
        pthread_cond_wait(&pShareRes->cond,&pShareRes->mutex);
    }
    printf("wake up! num = %d\n", pShareRes->num);
    --pShareRes->num;
    pthread_mutex_unlock(&pShareRes->mutex);
    pthread_exit(NULL);
}
int main(){
    pthread_t tid1,tid2;
    shareRes_t shareRes;
    shareRes.num = 0;
    pthread_mutex_init(&shareRes.mutex,NULL);
    pthread_cond_init(&shareRes.cond,NULL);    
    pthread_create(&tid1,NULL,threadFunc,(void *)&shareRes);
    pthread_create(&tid2,NULL,threadFunc,(void *)&shareRes);
    sleep(1);
    pthread_mutex_lock(&shareRes.mutex);
    shareRes.num += 1;
    //pthread_cond_signal(&shareRes.cond);
    pthread_cond_broadcast(&shareRes.cond);
    pthread_mutex_unlock(&shareRes.mutex);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    printf("num = %d\n", shareRes.num);
}