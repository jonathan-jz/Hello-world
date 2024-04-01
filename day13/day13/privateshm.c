#include <func.h>
#define NUM 10000000
int main(){
    int shmid = shmget(IPC_PRIVATE,4096,IPC_CREAT|0600);
    //创建无名共享内存
    ERROR_CHECK(shmid, -1, "shmget");
    int *p = (int *)shmat(shmid,NULL,0);
    ERROR_CHECK(p,(void *)-1,"shmat");
    if(fork() == 0){
        for(int i = 0;i < NUM; ++i){
            ++*p;
        }
    }
    else{
        for(int i = 0; i < NUM; ++i){
            ++*p;
        }
        wait(NULL);
        printf("*p = %d\n", *p);
    }
    shmdt(p);
}