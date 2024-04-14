#include <func.h>
void sigfunc(int signum){
printf("before signum = %d is coming\n",signum);
sleep(2);
printf("after signum = %d is coming\n",signum);
}
int main()
{
signal(SIGINT, sigfunc);//将SIGINT信号的处理行为注册成sigfunc
signal(SIGQUIT, sigfunc);
printf("proces begin!\n");
while(1);
return 0;
}
