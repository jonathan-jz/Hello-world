#include<func.h>

int main(int argc,char*argv){
    ARGS_CHECK(argc,2);
    FILE*fp = fopen(argv[1],"a+");
    ERROR_CHECK(fp,NULL,"fopen");
    char buf[6]={0};
    //ptr一开始指向开头
    fread(buf,1,5,fp);
    puts(buf);
    fseek(fp,0,SEEK_SET);
    fwrite("hello",1,5,fp);
    fseek(fp,0,SEEK_SET);
    fwrite("hello",1,5,fp);
    fclose(fp);
}