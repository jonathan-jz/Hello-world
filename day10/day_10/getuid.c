#include<func.h>
int main(int argc,char*argv[]){
    printf("pid = %d,ppid = %d\n",getuid(),geteuid());
    int fd = open("file1",O_WRONLY);
    int ret = write(fd,"hello",6);
    ERROR_CHECK(ret,-1,"write");

    return 0;
}