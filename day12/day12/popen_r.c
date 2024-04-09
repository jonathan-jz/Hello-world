#include <func.h>
int main(){
    FILE *fp = popen("./write", "r");
    ERROR_CHECK(fp,NULL,"popen");
    char buf[1024] = {0};
    fread(buf,1,sizeof(buf),fp);
    printf("buf = %s\n",buf);
    pclose(fp);
}