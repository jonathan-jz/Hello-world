#include <func.h>
int main(int argc, char *argv[]){
    //./kill -9 12345
    ARGS_CHECK(argc,3);
    //argv[2] --> "12345"
    //argv[1] --> "-9" char * 
    int ret = kill(atoi(argv[2]),atoi(argv[1]+1));
    ERROR_CHECK(ret,-1,"kill");
    return 0;
}