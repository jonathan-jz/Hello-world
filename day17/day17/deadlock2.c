#include <func.h>
int main(){
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex,NULL);
    pthread_mutex_lock(&mutex);
    printf("I got lock\n");
    pthread_mutex_lock(&mutex);
    exit(0);
}