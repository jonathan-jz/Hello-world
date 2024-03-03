#include <func.h>
int main(int argc, char *argv[]){
    // ./mkdir dir2
    ARGS_CHECK(argc,2);
    int ret = mkdir(argv[1],0777);
    //只要是创建文件的行为，都受到umask的影响
    ERROR_CHECK(ret,-1,"mkdir");
}