#include <func.h>
int mySystem(char * command);
int main(){
    //execl("add", "./add", "3", "4", NULL);
    char *args[] = {"./add", "4", "5", NULL};
    //execv("add",args);
    system("./add 4 5");
    //mySystem("./add 4 5");
    // char str[] = "./add 4 5";
    // char *word = strtok(str," ");
    // puts(word);
    // while( (word = strtok(NULL," ")) != NULL){
    //     puts(word);
    // }
    printf("You can see me ?\n");
}
int mySystem(char * command){
    if(fork() == 0){
        // "./add 4 5" --> {"./add", "4", "5", NULL}
        char *args[] = {"./add", "4", "5", NULL};
        execv("add",args);
    }
    else{
        //不做什么事情
    }
}