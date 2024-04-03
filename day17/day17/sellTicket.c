#include <func.h>
typedef struct shareRes_s{
    int num;
    pthread_mutex_t mutex;
} shareRes_t;
void *window1(void *arg){
    shareRes_t *pShareRes = (shareRes_t *)arg;
    int cnt1 = 0;
    while(1){
        pthread_mutex_lock(&pShareRes->mutex);
        if(pShareRes->num <= 0){
            // 要么记得解锁，要么就用pthread_cleanup_push/pop
            pthread_mutex_unlock(&pShareRes->mutex);
            break;
        }
        printf("Before window1 sells ticket, num = %d\n", pShareRes->num);
        --pShareRes->num;
        ++cnt1;
        printf("After window1 sells ticket, num = %d\n", pShareRes->num);
        pthread_mutex_unlock(&pShareRes->mutex);
        usleep(100000);
    }
    printf("cnt1 = %d\n", cnt1);
    pthread_exit(NULL);
}
void *window2(void *arg){
    shareRes_t *pShareRes = (shareRes_t *)arg;
    int cnt2 = 0;
    while(1){
        pthread_mutex_lock(&pShareRes->mutex);
        if(pShareRes->num <= 0){
            // 要么记得解锁，要么就用pthread_cleanup_push/pop
            pthread_mutex_unlock(&pShareRes->mutex);
            break;
        }
        printf("Before window2 sells ticket, num = %d\n", pShareRes->num);
        --pShareRes->num;
        ++cnt2;
        printf("After window2 sells ticket, num = %d\n", pShareRes->num);
        pthread_mutex_unlock(&pShareRes->mutex);
        usleep(100000);
    }
    printf("cnt2 = %d\n", cnt2);
    pthread_exit(NULL);
}
void *add(void *arg){
    shareRes_t * pShareRes = (shareRes_t *)arg;
    while(1){
        pthread_mutex_lock(&pShareRes->mutex);
        printf("if no ticket?\n");
        if (pShareRes->num <= 10){
            pShareRes->num += 10;
            printf("yes!\n");
            pthread_mutex_unlock(&pShareRes->mutex);
            break;
        }
        pthread_mutex_unlock(&pShareRes->mutex);
        usleep(100000);
    }
    pthread_exit(NULL);
}
int main(){
    pthread_t tid1,tid2,tid3;
    shareRes_t shareRes;
    shareRes.num = 20;
    pthread_mutex_init(&shareRes.mutex,NULL);
    pthread_create(&tid1,NULL,window1,(void *)&shareRes);
    pthread_create(&tid2,NULL,window2,(void *)&shareRes);
    pthread_create(&tid3,NULL,add,(void *)&shareRes);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    printf("main thread Sold out!\n");
    return 0;
}