#include <func.h>
int main(){
    if(fork() == 0){
        sleep(3);
        puts("I am child");
    }
    else{
        puts("I am parent");
        return 0;
    }
}