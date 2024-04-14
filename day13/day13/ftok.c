#include<func.h>
int main(int argc, char *argv[]){
    // ./ftok file1
    ARGS_CHECK(argc,2);
    key_t key = ftok(argv[1], 0);
    ERROR_CHECK(key,-1,"ftok");
    printf("key = %d\n", key);
}