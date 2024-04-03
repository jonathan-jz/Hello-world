#include <func.h>
void handler(int num){
    printf("num = %d\n", num);
}
int main(){
    signal(SIGINT,handler);
    char buf[1024] = {0};
    read(STDIN_FILENO,buf,sizeof(buf));
    printf("buf = %s\n", buf);
    return 0;
}

