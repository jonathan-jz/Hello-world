#include <func.h>
void mySystem(const char *command);
int main(){
    //system("./add 3 4");
    mySystem("./add 3 4");//字符串字面值常量 在数据段/代码段 .rodata 不能修改内容
    printf("I am parent!\n");
}
void mySystem(const char *command){
    if(fork() == 0){
        char *args[10] = {0};
        char buf[1024] = {0};
        strcpy(buf,command);
        args[0] = strtok(buf," ");
        puts(args[0]);
        for(int i = 1;;++i){
            args[i] = strtok(NULL," ");
            if(args[i] == NULL){
                break;
            }
        }
        //char *args[] = {"./add","3", "4", NULL};
        execv(args[0],args);
    }
    wait(NULL);
}