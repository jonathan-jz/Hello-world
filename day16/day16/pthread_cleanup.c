#include <func.h>
void func1(void *arg){
    free(arg);
    printf("free p1\n");
}
void func2(void *arg){
    free(arg);
    printf("free p2\n");
}
void * threadFunc(void *arg){
    void *p1 = malloc(1024);
    pthread_cleanup_push(func1,p1);
    //弹栈时相当于调用了 func1(p1)
    //pthread_exit((void *)-1);//会弹栈并调用清理函数
    //return (void *)-1;//return不一定会弹栈
    void *p2 = malloc(1024);
    pthread_cleanup_push(func2,p2);
    pthread_cleanup_pop(1);
    pthread_exit((void *)-1);
    pthread_cleanup_pop(1);//如果执行到cleanup_pop 参数是0不会执行，是正数就会执行
    // pthread_cleanup_pop必须和pthread_cleanup_push成对出现
    puts("pop");
    pthread_exit((void *)-1);
}
int main(){
    pthread_t tid;
    pthread_create(&tid,NULL,threadFunc,NULL);
    void *ret;
    pthread_join(tid,&ret);
}