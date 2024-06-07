#include<func.h>
int main(int argc, char* argv[]){
    //./getcws

    //
    char buf[1024]={0};//suoyou yaoduqu de kogjian yao xian qingkong 

    char *ret =getcwd(buf,sizeof(buf));
  //  char *ret = getcwd(NULL,0);
    ERROR_CHECK(ret,NULL,"getcwd");
    printf("ret = %s\n",ret);
    printf("buff = %s\n ",buf);
    // free(ret);
    return 0;
}
