//#include<stdio.h>
#include<func.h>

int main(int argc,char*argv[]){
    //.fopen()

    ARGS_CHECK(argc,2);

    FILE*fp = fopen(argv[1],"a+");
    ERROR_CHECK(fp,NULL,"fopen");
    char buf[6]={0};

    fread(buf,1,5,fp);
    puts(buf);
    fwrite("bagan",1,5,fp);
    fclose(fp);


    return 0;
}
