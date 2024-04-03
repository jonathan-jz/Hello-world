#include <func.h>
void *threadFunc(void *parg){
    char *p = (char *)parg;
    printf("I am child, p = %s\n", p);
    strcpy(p,"World");
}
int main(){
    pthread_t tid;
    char *p = (char *)malloc(1024);
    strcpy(p,"Hello");
    pthread_create(&tid,NULL,threadFunc,(void *)p);
    sleep(1);
    printf("I am main, p = %s\n", p);
    free(p);
}