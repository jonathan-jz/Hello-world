#include <func.h>
int main(){
    key_t key = ftok("file1",0);
    ERROR_CHECK(key,-1,"ftok");
    printf("key = %d\n",key);
    int shmid = shmget(key,4096,IPC_CREAT|0600);//创建共享内存
    ERROR_CHECK(shmid, -1, "shmget");
    int ret = shmctl(shmid,IPC_RMID,NULL);
    if(ret == 0){
        printf("success.\n");
    }
    return 0;
}