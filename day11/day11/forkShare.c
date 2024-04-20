#include <func.h>
int main(){
    int fd = open("file1", O_WRONLY);
    if(fork() == 0){
        write(fd,"world",5);
    }
    else{
        write(fd,"hello",5);
        //sleep(1);
    }
}