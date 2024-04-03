#include <func.h>
int main(){
    raise(SIGPIPE);
    printf("Can you see me ?\n");
}