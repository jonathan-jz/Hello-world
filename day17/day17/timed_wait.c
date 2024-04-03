#include <func.h>
int main(){
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    pthread_mutex_lock(&mutex);
    time_t now = time(NULL);
    printf("now = %s\n", ctime(&now));
    struct timespec abstime;
    abstime.tv_nsec = 0;
    abstime.tv_sec = now + 1;
    //pthread_cond_wait(&cond,&mutex);
    pthread_cond_timedwait(&cond,&mutex,&abstime);
    now = time(NULL);
    printf("now = %s\n", ctime(&now));
    pthread_mutex_unlock(&mutex);
}