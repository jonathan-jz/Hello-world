#include <func.h>
int main(){
    printf("gid = %d, egid = %d\n", getgid(), getegid());
    int fd = open("file1",O_WRONLY);
    int ret = write(fd,"hello",5);
    ERROR_CHECK(ret,-1,"write");
    return 0;
}