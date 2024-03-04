#include <func.h>
int main(int argc, char *argv[]){
    // ./chdir dir1
    ARGS_CHECK(argc,2);
    printf("before chdir, cwd = %s\n", getcwd(NULL,0));
    int ret = chdir(argv[1]);
    ERROR_CHECK(ret,-1,"chdir");
    printf("after chdir, cwd = %s\n", getcwd(NULL,0));
}


//这里只是just改变的运行程序的位置，而不是改变真实的位置
