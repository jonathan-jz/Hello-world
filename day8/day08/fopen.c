#include<func.h>
int main(int argc,char*argv[]){
    ARGS_CHECK(argc,2);
    FILE*fp = fopen(argv[1],"r+");
    ERROR_CHECK(fp,NULL,"fopen");
   // write(fp->_fileno,"hello",5);
    write(fileno(fp),"hello",5);
    fclose(fp);
    return 0;
}