#include <func.h>
void handler(int num){
    printf("num = %d\n", num);
}
int main(){
    signal(SIGALRM,handler);
    alarm(1);
    pause();//阻塞进程直到任何一个信号递送

    //禁止混用sleep和alarm
}