#include <func.h>
typedef struct shareRes_s{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} shareRes_t;
void *threadFunc(void *arg){
    shareRes_t *pShareRes = (shareRes_t *)arg;
    pthread_mutex_lock(&pShareRes->mutex);
    pthread_cond_wait(&pShareRes->cond,&pShareRes->mutex);
    // 上半部 检查加锁 加入唤醒队列 解锁并陷入阻塞
    // 下半部 苏醒并加锁
    puts("world");
    pthread_mutex_unlock(&pShareRes->mutex);
}
int main(){
    pthread_t tid;
    shareRes_t shareRes;
    pthread_mutex_init(&shareRes.mutex,NULL);
    pthread_cond_init(&shareRes.cond,NULL);
    pthread_create(&tid,NULL,threadFunc,(void *)&shareRes);
    sleep(1);
    //pthread_mutex_lock(&shareRes.mutex);
    pthread_cond_signal(&shareRes.cond);
    sleep(1);
    puts("hello");
    //pthread_mutex_unlock(&shareRes.mutex);
    pthread_join(tid,NULL);
}