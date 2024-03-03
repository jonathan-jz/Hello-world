#include<func.h>
int main(int argc,char* argv[]){
    ARGS_CHECK(argc,2);
    int ret  = mkdir(argv[1],0777);
    ERROR_CHECK(ret,-1,"mkdir");
    //只要创建文件的行为都会收到umask的影响


    return 0;
}

