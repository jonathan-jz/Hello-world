#include <func.h>
#define NUM 20000000
typedef struct shareRes_s{
    int val;
    pthread_mutex_t mutex;
} shareRes_t;
void *threadFunc(void *p){
    shareRes_t *pShareRes = (shareRes_t *)p;
    for(int i = 0;i < NUM; ++i){
        pthread_mutex_lock(&pShareRes->mutex);
        ++pShareRes->val;
        pthread_mutex_unlock(&pShareRes->mutex);
    }
    pthread_exit((void *)0);
}
int main(){
    pthread_t tid;
    //int val = 0;
    //pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    //pthread_mutex_t mutex;
    //pthread_mutex_init(&mutex,NULL);//第二参数填NULL，表示锁是默认属性
    shareRes_t shareRes;
    shareRes.val = 0;
    pthread_mutex_init(&shareRes.mutex,NULL);
    struct timeval begTime, endTime;
    gettimeofday(&begTime,NULL);
    pthread_create(&tid,NULL,threadFunc,(void *)&shareRes);
    for(int i = 0;i < NUM; ++i){
        pthread_mutex_lock(&shareRes.mutex);
        ++shareRes.val;
        pthread_mutex_unlock(&shareRes.mutex);
    }
    pthread_join(tid,NULL);
    gettimeofday(&endTime,NULL);
    printf("total time = %ld\n", (endTime.tv_sec - begTime.tv_sec)*1000000 + endTime.tv_usec - begTime.tv_usec);
    printf("val = %d\n", shareRes.val);
    pthread_mutex_destroy(&shareRes.mutex);
    return 0;
}