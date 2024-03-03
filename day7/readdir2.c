#include<func.h>
int main(int argc,char* argv[]){
    //./readdir dir
    ARGS_CHECK(argc,2);
    DIR *pdir = opendir(argv[1]);
    ERROR_CHECK(pdir,NULL,"opendir");
    struct dirent *pdirent;
    //pdirent = readdir(pdir);

while((pdirent = readdir(pdir))!= NULL){    //不断移动
    printf("inode = %ld    reclen =%d     type = %d   name  = %s\n",\
        
        pdirent->d_ino,pdirent->d_reclen,pdirent->d_type,pdirent->d_name);
    
}
    closedir(pdir);

    return 0;
}

