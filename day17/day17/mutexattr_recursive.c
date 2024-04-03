#include <func.h>
void *threadFunc(void *arg){
    pthread_mutex_t *pMutex = (pthread_mutex_t *)arg;
    //usleep(20);
    pthread_mutex_lock(pMutex);
    printf("Child\n");
    pthread_mutex_unlock(pMutex);
}
int main(){
    pthread_mutex_t mutex;
    pthread_mutexattr_t mutexattr;//指明锁得属性
    pthread_mutexattr_init(&mutexattr);
    pthread_mutexattr_settype(&mutexattr,PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutex,&mutexattr);//创建锁，用mutexattr指明的属性
    pthread_t tid;
    pthread_create(&tid,NULL,threadFunc,(void *)&mutex);
    usleep(20);
    int ret = pthread_mutex_lock(&mutex);
    THREAD_ERROR_CHECK(ret,"pthread_mutex_lock");
    puts("First lock");
    ret = pthread_mutex_lock(&mutex);
    THREAD_ERROR_CHECK(ret,"pthread_mutex_lock");
    puts("Second lock");
    puts("Hello");
    puts("First unlock");
    pthread_mutex_unlock(&mutex);
    puts("Second unlock");
    pthread_mutex_unlock(&mutex);
    pthread_join(tid,NULL);
    pthread_mutex_destroy(&mutex);
    pthread_mutexattr_destroy(&mutexattr);
}