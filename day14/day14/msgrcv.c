#include <func.h>
typedef struct msgbuf_s{
    long mtype;
    char mtext[256];
}msgbuf_t;
int main(){
    int msgid = msgget(1000,IPC_CREAT|0600);
    ERROR_CHECK(msgid,-1,"msgget");
    msgbuf_t mymsg;
    msgrcv(msgid,&mymsg,sizeof(mymsg.mtext),1,0);
    msgrcv(msgid,&mymsg,1,1,0);
    printf("mymsg.mtype = %ld, mymsg.mtext = %s\n", mymsg.mtype, mymsg.mtext);
}