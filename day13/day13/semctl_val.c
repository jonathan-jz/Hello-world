#include <func.h>
int main(){
    int semid = semget(1000,1,IPC_CREAT|0600);
    ERROR_CHECK(semid,-1,"semget");
    int ret = semctl(semid,0,GETVAL);
    ERROR_CHECK(ret,-1,"semctl getval");
    printf("val = %d\n", ret);
    ret = semctl(semid,0,SETVAL,2);//0代表的是下标为0的信号量
    ERROR_CHECK(ret,-1,"semctl setval");
    printf("VAl = %d\n",ret);
    ret = semctl(semid,0,GETVAL);
    ERROR_CHECK(ret,-1,"semctl getval");
    printf("val = %d\n", ret);
}