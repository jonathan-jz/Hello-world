#include <func.h>
int main(){
    key_t key = ftok("file1",0);
    ERROR_CHECK(key,-1,"ftok");
    int shmid = shmget(key,4096,IPC_CREAT|0600);//创建共享内存
    ERROR_CHECK(shmid, -1, "shmget");
    struct shmid_ds buf;
    shmctl(shmid,IPC_STAT,&buf);
    printf("cuid = %d\n",buf.shm_perm.cuid);
    printf("perm = %o\n",buf.shm_perm.mode);
    printf("size = %ld\n", buf.shm_segsz);
    printf("nattach = %ld\n", buf.shm_nattch);
    buf.shm_perm.mode = 0666;
    shmctl(shmid,IPC_SET,&buf);//在设置属性之前必须先获取
}