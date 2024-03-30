#include <func.h>
int main(){
    printf("uid = %d, euid = %d\n", getuid(), geteuid());
    int fd = open("file1",O_WRONLY);
    int ret = write(fd,"hello",5);
    ERROR_CHECK(ret,-1,"write");
    return 0;
}