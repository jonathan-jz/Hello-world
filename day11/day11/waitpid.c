#include <func.h>
int main()
{
    pid_t ret = fork();
    if (ret == 0){
        printf("I am child, pid = %d, ppid = %d\n",
               getpid(), getppid());
        // return 200;
        // return -1;
        while (1)
            ;
    }
    else{
        int status;
        printf("I am parent, pid = %d, ppid = %d\n",
               getpid(), getppid());
        while (1){
            printf("waitpid\n");
            int wret = waitpid(-1, &status, WNOHANG);
            if (wret != 0){
                if (WIFEXITED(status)){
                    printf("exit code = %d\n", WEXITSTATUS(status));
                }
                else if (WIFSIGNALED(status)){
                    printf("abnormal exit, termsig = %d\n", WTERMSIG(status));
                }
                break;
            }
            else{
                printf("No child process has dead yet\n");
                sleep(5);
            }
        }
    }
}