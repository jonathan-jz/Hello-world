#include <func.h>
int main(){
    int semid = semget(1001,2,IPC_CREAT|0600);
    //信号量创建时key相同的大小也一定要相同
    ERROR_CHECK(semid,-1,"semget");
    //int ret = semctl(semid,0,SETVAL,0);
    //ERROR_CHECK(ret,-1,"semctl");
    //ret = semctl(semid,1,SETVAL,5);
    //ERROR_CHECK(ret,-1,"semctl");
    unsigned short arr[] = {5,0};//0->商品 1->仓库
    int ret = semctl(semid,0,SETALL,arr);
    ERROR_CHECK(ret,-1,"semctl");
    printf("sem[0] = %d, sem[1] = %d\n",
        semctl(semid,0,GETVAL), semctl(semid,1,GETVAL)); 
    struct sembuf produce[2];
    produce[0].sem_num = 0;
    produce[0].sem_op = 1;
    produce[0].sem_flg = SEM_UNDO;
    produce[1].sem_num = 1;
    produce[1].sem_op = -1;
    produce[1].sem_flg = SEM_UNDO;
    struct sembuf consume[2];
    consume[0].sem_num = 0;
    consume[0].sem_op = -1;
    consume[0].sem_flg = SEM_UNDO;
    consume[1].sem_num = 1;
    consume[1].sem_op = 1;
    consume[1].sem_flg = SEM_UNDO;
    if(fork() == 0){
        //子进程 生产者
        while(1){
            sleep(1);
            printf("before produce, sem[0] = %d, sem[1] = %d\n",
                semctl(semid,0,GETVAL), semctl(semid,1,GETVAL));
            semop(semid,produce,2);//这个操作会影响到2个资源 
            printf("after produce, sem[0] = %d, sem[1] = %d\n",
                semctl(semid,0,GETVAL), semctl(semid,1,GETVAL));
        }
    }
    else{
        //父进程 消费者
        while(1){
            usleep(500000);
            printf("before consume, sem[0] = %d, sem[1] = %d\n",
                semctl(semid,0,GETVAL), semctl(semid,1,GETVAL));
            semop(semid,consume,2);//这个操作会影响到2个资源 
            printf("after consume, sem[0] = %d, sem[1] = %d\n",
                semctl(semid,0,GETVAL), semctl(semid,1,GETVAL));
        }
    }
}