#include <func.h>
void *threadFunc(void *args){//子线程的main函数
    printf("I am child thread, tid = %lu\n", pthread_self());
}
int main(){
    pthread_t tid;
    pthread_create(&tid,NULL,threadFunc,NULL);
    //线程id的地址，线程的属性是默认NULL，线程启动函数，主线程给子线程传递的参数
    //sleep(1);
    printf("I am main thread, tid = %lu\n", pthread_self());
    usleep(500);
    _exit(0);
}