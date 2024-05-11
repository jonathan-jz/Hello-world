#include <func.h>
void func(){
    pthread_exit((void *) 246);
    return;
}
void *threadFunc(void *args){//子线程的main函数
    printf("I am child thread, tid = %lu\n", pthread_self());
    //while(1);
    //return (void *)123;
    func();
    printf("Can you see me?\n");
}
int main(){
    pthread_t tid;
    pthread_create(&tid,NULL,threadFunc,NULL);
    //线程id的地址，线程的属性是默认NULL，线程启动函数，主线程给子线程传递的参数
    void * ret;//ret将要存储子线程的终止状态
    pthread_join(tid, &ret);//主线程会等待tid子线程的终止，会将子线程的终止状态保存在ret中
    printf("ret = %ld\n", (long )ret);
    // pthread_join(tid,NULL);
    // pthread_join(&tid,NULL);
    int ret = pthread_join(0,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_join");
}