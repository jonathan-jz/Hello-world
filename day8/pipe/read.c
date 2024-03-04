#include <func.h>
int main(int argc, char *argv[]){
    // ./read 1.pipe
    ARGS_CHECK(argc,2);
    int fdr = open(argv[1], O_RDONLY);
    puts("Read side open!");
    sleep(10000);
    close(fdr);
}