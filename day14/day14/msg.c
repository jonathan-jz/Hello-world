#include <func.h>
typedef struct msgbuf_s{
    long mtype;
    char mtext[256];
}msgbuf_t;
int main(){
    int msgid = msgget(1000,IPC_CREAT|0600);
    ERROR_CHECK(msgid,-1,"msgget");
    msgbuf_t mymsg;
    mymsg.mtype = 1;//mtype一定要是一个正整数
    strcpy(mymsg.mtext,"hello");
    msgsnd(msgid,&mymsg,5,0);
}