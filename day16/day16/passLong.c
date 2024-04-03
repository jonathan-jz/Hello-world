#include <func.h>
void *threadFunc(void *arg){
    long val = (long)arg;
    printf("I am child, val = %ld\n", val);

}
int main(){
    pthread_t tid;
    long val = 1001;
    pthread_create(&tid,NULL,threadFunc,(void *)val);
    val = 1002;
    pthread_create(&tid,NULL,threadFunc,(void *)val);
    val = 1003;
    pthread_create(&tid,NULL,threadFunc,(void *)val);
    sleep(1);
}