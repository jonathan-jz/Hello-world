#include <func.h>
#define NUM 10000000
int main(){
    int shmid = shmget(IPC_PRIVATE,4096,IPC_CREAT|0600);
    //创建无名共享内存
    ERROR_CHECK(shmid, -1, "shmget");
    int *p = (int *)shmat(shmid,NULL,0);
    ERROR_CHECK(p,(void *)-1,"shmat");
    int semid = semget(1000,1,IPC_CREAT|0600);
    //创建一个长度为1的信号量数组
    ERROR_CHECK(semid,-1,"semget");
    int ret = semctl(semid,0,SETVAL,1);
    //设置资源的值初始为1
    ERROR_CHECK(ret,-1,"semctl");
    struct sembuf P;
    P.sem_num = 0;//下标为0
    P.sem_op = -1;//二元信号量，P操作减一
    P.sem_flg = SEM_UNDO;//先固定为SEM_UNDO
    struct sembuf V;
    V.sem_num = 0;//下标为0
    V.sem_op = 1;//二元信号量，V操作加一
    V.sem_flg = SEM_UNDO;//先固定为SEM_UNDO
    struct timeval begTime, endTime;
    gettimeofday(&begTime,NULL);
    if(fork() == 0){
        for(int i = 0;i < NUM; ++i){
            semop(semid,&P,1);//执行P操作
            ++*p;
            semop(semid,&V,1);//执行V操作
        }
    }
    else{
        for(int i = 0; i < NUM; ++i){
            semop(semid,&P,1);//执行P操作
            ++*p;
            semop(semid,&V,1);//执行V操作
        }
        wait(NULL);
        gettimeofday(&endTime,NULL);
        printf("*p = %d\n", *p);
        printf("Total microseconds = %ld\n",
            (endTime.tv_sec-begTime.tv_sec)*1000000+endTime.tv_usec-begTime.tv_usec);
    }
    shmdt(p);
}