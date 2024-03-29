#include <func.h>
int main(int argc, char *argv[]){
    // ./write 1.pipe
    ARGS_CHECK(argc,2);
    int fdw = open(argv[1], O_WRONLY);
    puts("Write side open!");
    char buf[4096] = {0};
    int cnt = 0;
    printf("cnt = %d\n", cnt++);
    write(fdw,"hello",5);
    close(fdw);
}
