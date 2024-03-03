#include <func.h>
int main(int argc, char *argv[]){
    ARGS_CHECK(argc,2);
    FILE * fp = fopen(argv[1], "r+");
    ERROR_CHECK(fp,NULL,"fopen");
    //write(3,"hello", 5);
    //write(fp->_fileno,"hello", 5);
    write(fileno(fp),"hello",5);
    fclose(fp);
    printf("fileno(stdin) = %d\n", fileno(stdin));
    printf("fileno(stdout) = %d\n", fileno(stdout));
    printf("fileno(stderr) = %d\n", fileno(stderr));
    return 0;
}

