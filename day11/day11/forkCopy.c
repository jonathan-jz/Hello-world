#include <func.h>
int global = 1;//数据段
int main(){
    static int staticLocal = 2;//静态局部变量 分配在数据段
    int local = 3;//普通局部变量 分配在栈上
    int *pHeap = (int *)malloc(sizeof(int));
    *pHeap = 4;//*pHeap在堆上
    if(fork() == 0){
        global += 4;
        staticLocal += 4;
        local += 4;
        *pHeap += 4;
        printf("I am child, global = %d, staticLocal = %d, local = %d, *pHeap = %d\n",
            global,staticLocal,local,*pHeap);
    }
    else{
        sleep(3);
        printf("I am parent, global = %d, staticLocal = %d, local = %d, *pHeap = %d\n",
            global,staticLocal,local,*pHeap);
    }
}