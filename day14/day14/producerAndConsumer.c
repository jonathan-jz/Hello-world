#include <func.h>
int main(){
    int shmid = shmget(1000,4096,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");
    int *p = shmat(shmid,NULL,0);
    ERROR_CHECK(p,(void *)-1,"shmat");
    int semid = semget(1000,1,IPC_CREAT|0600);
    ERROR_CHECK(semid,-1,"semget");
    int ret = semctl(semid,0,SETVAL,1);
    ERROR_CHECK(ret,-1,"semctl");
    
    struct sembuf P;
    P.sem_num = 0;//下标为0
    P.sem_op = -1;//二元信号量，P操作减一
    P.sem_flg = SEM_UNDO;//先固定为SEM_UNDO
    struct sembuf V;
    V.sem_num = 0;//下标为0
    V.sem_op = 1;//二元信号量，V操作加一
    V.sem_flg = SEM_UNDO;//先固定为SEM_UNDO
    //p[0] --> 商品
    //p[1] --> 仓库
    p[0] = 0;
    p[1] = 5;
    if(fork() == 0){
        //子进程 生产者
        while(1){
            semop(semid,&P,1);
            printf("before produce, p[0] = %d, p[1] = %d\n", p[0], p[1]);
            printf("child sem = %d\n", semctl(semid,0,GETVAL));
            sleep(1);
            if(p[1] > 0){
               --p[1];
               ++p[0];
            }
            printf("after produce, p[0] = %d, p[1] = %d\n", p[0], p[1]);
            semop(semid,&V,1);
        }
    }
    else{
        //父进程 消费者
        while(1){
            semop(semid,&P,1);
            printf("before consume, p[0] = %d, p[1] = %d\n", p[0], p[1]);
            printf("parent sem = %d\n", semctl(semid,0,GETVAL));
            sleep(1);            
            if(p[0] >0){
                --p[0];
                ++p[1];
            }
            printf("after consume, p[0] = %d, p[1] = %d\n", p[0], p[1]);
            semop(semid,&V,1);
        }
    }
}