#include <func.h>
void *threadFunc(void *parg){
    int *pval = (int *)parg;
    printf("I am child, *pval = %d\n", *pval);
}
int main(){
    pthread_t tid;
    int val = 1001;
    pthread_create(&tid,NULL,threadFunc,(void *)&val);
    sleep(1);
    val = 1002;
    pthread_create(&tid,NULL,threadFunc,(void *)&val);
    sleep(1);
}