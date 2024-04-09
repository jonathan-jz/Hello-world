#include <func.h>
#include <dirent.h>
int DFSprint(char *path, int width);
int main(int argc, char *argv[]){
    //./myTree dir1
    ARGS_CHECK(argc,2);
    printf("%s\n", argv[1]);
    DFSprint(argv[1],4);
}
int DFSprint(char *path, int width){
    DIR *dirp = opendir(path);
    ERROR_CHECK(dirp,NULL,"opendir");
    struct dirent * pdirent;
    char newPath[1024] = {0};
    while((pdirent = readdir(dirp))!= NULL){
        if(strcmp(pdirent->d_name,".") == 0 || 
            strcmp(pdirent->d_name,"..") == 0){
                continue;
        }
        for(int i = 0;i < width; ++i){
            printf("-");
        }
        printf("%s\n", pdirent->d_name);
        if(pdirent->d_type == DT_DIR){
            sprintf(newPath,"%s%s%s", path,"/",pdirent->d_name);
            DFSprint(newPath,width+4);

        }
    }
}