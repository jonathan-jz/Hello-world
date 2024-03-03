#include<func.h>
int main(int argc,char* argv[]){
    ARGS_CHECK(argc,2);

    int ret  = rmdir(argv[1]);
    ERROR_CHECK(ret,-1,"mkdir");
    //只要创建文件的行为都会收到umask的影响


    return 0;
}

