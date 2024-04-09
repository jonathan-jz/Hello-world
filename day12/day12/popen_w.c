#include <func.h>
int main(){
    FILE *fp = popen("./read", "w");
    ERROR_CHECK(fp,NULL,"popen");
    fwrite("1 2",1,3,fp);
    pclose(fp);
}