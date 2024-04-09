#include <func.h>
#define MAXFD 64
void Daemon(){
    if(fork() != 0){
        exit(0);
        //父进程本身是进程组的组长不能创建新会话
    }
    setsid();//子进程去创建一个新会话
    for(int i = 0;i < MAXFD; ++i){
        close(i);//把原来终端脱离守护进程
    }
    chdir("/");//切换目录到根目录
    umask(0);//去掉文件创建掩码
}
int main(){
   // Daemon();
    for(int i = 0;i < 20; i += 2){
        time_t now = time(NULL);
        struct tm * pTm = localtime(&now);
        syslog(LOG_INFO,"%02d%02d %02d:%02d:%02d\n",
            pTm->tm_mon+1, pTm->tm_mday,pTm->tm_hour,pTm->tm_min,pTm->tm_sec);
        sleep(2);
    }
}