#include <func.h>
int main(){
    execl("add", "./add", "3", "4", NULL);
    printf("You can see me ?\n");
}