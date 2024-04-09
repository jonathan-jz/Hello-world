#include <func.h>
int main(){
    int pipefds[2];
    pipe(pipefds);//传入的是数组名
    printf("pipefs[0] = %d, pipefds[1] = %d\n", pipefds[0], pipefds[1]);
    write(pipefds[1],"hello",5);
    char buf[10] = {0};
    read(pipefds[0],buf,sizeof(buf));
    puts(buf);
}