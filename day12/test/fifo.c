#include <stdio.h>
#include <func.h>

int main(int argc,char*argv[])
{
    ARGS_CHECK(argc,2);
    
    int ret = mkfifo(argv[1],0600);
    ERROR_CHECK(ret,-1,"mkfifo");
    int fd = open(argv[1],O_WRONLY);
    write(fd,"hello",5);
    unlink(argv[1]);
    return 0;
}

