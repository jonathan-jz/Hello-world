#include <stdio.h>
#include<func.h>
int main()
{
    FILE *fp = popen("./print","r");
    ERROR_CHECK(fp,NULL,"popen");
 
    char buf[128] = {0};
    fread(buf,1,sizeof(buf),fp);
    printf("read from pipe %s",buf);
    pclose(fp);

    return 0;
}

