#include <func.h>
typedef struct shareRes_s
{
    int num;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} shareRes_t;
void *window1(void *arg){
    shareRes_t *pShareRes = (shareRes_t *)arg;
    while (1){
        pthread_mutex_lock(&pShareRes->mutex);
        if (pShareRes->num > 0){
            printf("Before window1 sells ticket, num = %d\n", pShareRes->num);
            --pShareRes->num;
            if (pShareRes->num <= 0){
                pthread_cond_signal(&pShareRes->cond);//给add发signal
                //如果没有任何一个线程阻塞在cond上，signal就毫无影响
                //一般情况下要让wait在signal之前调用
            }
            printf("After window1 sells ticket, num = %d\n", pShareRes->num);
            pthread_mutex_unlock(&pShareRes->mutex);
            usleep(100000);//避免本线程马上调用mutex_lock
        }else{
            pthread_mutex_unlock(&pShareRes->mutex);
            break;
        }
    }
    pthread_exit(NULL);
}
void *window2(void *arg)
{
    shareRes_t *pShareRes = (shareRes_t *)arg;
    while (1)
    {
        pthread_mutex_lock(&pShareRes->mutex);
        if (pShareRes->num > 0)
        {
            printf("Before window2 sells ticket, num = %d\n", pShareRes->num);
            --pShareRes->num;
            if (pShareRes->num <= 0)
            {
                pthread_cond_signal(&pShareRes->cond);//给add发signal
            }
            printf("After window2 sells ticket, num = %d\n", pShareRes->num);
            pthread_mutex_unlock(&pShareRes->mutex);
            usleep(100000);//避免本线程马上调用mutex_lock
        }
        else{
            pthread_mutex_unlock(&pShareRes->mutex);
            break;
        }
    }
    pthread_exit(NULL);
}
void *add(void *arg)
{
    shareRes_t *pShareRes = (shareRes_t *)arg;
    pthread_mutex_lock(&pShareRes->mutex);
    if(pShareRes->num > 0){
        printf("add is waiting!\n");
        pthread_cond_wait(&pShareRes->cond,&pShareRes->mutex);
    }
    printf("add is signaled\n");
    pShareRes->num += 10;
    pthread_mutex_unlock(&pShareRes->mutex);
    pthread_exit(NULL);
}
int main()
{
    pthread_t tid1, tid2, tid3;
    shareRes_t shareRes;
    shareRes.num = 20;
    pthread_mutex_init(&shareRes.mutex, NULL);
    pthread_cond_init(&shareRes.cond, NULL);
    pthread_create(&tid1, NULL, window1, (void *)&shareRes);
    pthread_create(&tid2, NULL, window2, (void *)&shareRes);
    pthread_create(&tid3, NULL, add, (void *)&shareRes);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    printf("main thread Sold out!\n");
    pthread_mutex_destroy(&shareRes.mutex);
    pthread_cond_destroy(&shareRes.cond);
    return 0;
}