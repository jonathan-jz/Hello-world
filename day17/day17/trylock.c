#include <func.h>
int main(){
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex,NULL);
    int ret = pthread_mutex_trylock(&mutex);
    THREAD_ERROR_CHECK(ret,"pthread_mutex_trylock");
    puts("1");
    ret = pthread_mutex_trylock(&mutex);//trylock执行的时候，锁已经被持有了
    THREAD_ERROR_CHECK(ret,"pthread_mutex_trylock");
    puts("2");
}