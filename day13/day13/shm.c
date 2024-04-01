#include <func.h>
int main(){
    key_t key = ftok("file1",0);
    ERROR_CHECK(key,-1,"ftok");
    int shmid = shmget(key,4096,IPC_CREAT|0600);//创建共享内存
    ERROR_CHECK(shmid, -1, "shmget");
    char *p = (char *)shmat(shmid,NULL,0);
    ERROR_CHECK(p,(void *)-1,"shmat");
    //while(1);
    puts(p);
    shmdt(p);
}