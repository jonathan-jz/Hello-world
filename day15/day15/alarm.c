#include <func.h>
void handler(int num){
    printf("num = %d\n", num);
}
int main(){
    signal(SIGALRM,handler);
    alarm(1);
    while(1);
}