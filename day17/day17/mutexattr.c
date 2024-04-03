#include <func.h>
int main(){
    pthread_mutex_t mutex;
    pthread_mutexattr_t mutexattr;//指明锁得属性
    pthread_mutexattr_init(&mutexattr);
    pthread_mutexattr_settype(&mutexattr,PTHREAD_MUTEX_ERRORCHECK);
    pthread_mutex_init(&mutex,&mutexattr);//创建锁，用mutexattr指明的属性
    puts("First lock");
    int ret  = pthread_mutex_lock(&mutex);
    THREAD_ERROR_CHECK(ret,"pthread_mutex_lock");
    puts("Second lock");
    ret = pthread_mutex_lock(&mutex);
    THREAD_ERROR_CHECK(ret,"pthread_mutex_lock");
    puts("Hello");
    pthread_mutex_destroy(&mutex);
    pthread_mutexattr_destroy(&mutexattr);
}