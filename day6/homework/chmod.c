#include<func.h>
int main(int argc,char**argv){
    
    char buf[1024]={0};
    char *ret = getcwd(buf,sizeof(buf));
    ERROR_CHECK(ret,NULL,"getcwd");

    printf("%s\n",buf);
    printf("%s\n",ret);
    // free(ret);

    return 0;
}
