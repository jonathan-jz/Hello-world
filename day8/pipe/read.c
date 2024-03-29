#include <func.h>
int main(int argc, char *argv[]){
    // ./read 1.pipe
    ARGS_CHECK(argc,2);
    int fdr = open(argv[1], O_RDONLY);
    puts("Read side open!");
    char buf[1024] = {0};
    read(fdr,buf,sizeof(buf));
    printf("%s",buf);

    close(fdr);
}
