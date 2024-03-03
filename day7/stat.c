#include<func.h>
int main(int argc,char* argv[]){
    //./readdir dir
    ARGS_CHECK(argc,2);
    DIR *pdir = opendir(argv[1]);
    ERROR_CHECK(pdir,NULL,"opendir");
    chdir(argv[1]);
    struct dirent *pdirent;
    struct stat statbuf;
    while((pdirent = readdir(pdir))!=NULL){

        int ret =  stat(pdirent->d_name,&statbuf);
        ERROR_CHECK(ret,-1,"stat");
        printf("%6o %ld %s %s %4ld %s %s\n",
            statbuf.st_mode,
            statbuf.st_nlink,
            getpwuid(statbuf.st_uid)->pw_name,
            getgrgid(statbuf.st_gid)->gr_name,
            statbuf.st_size,
            ctime(&statbuf.st_mtime),
            pdirent->d_name
        );
    } 
    closedir(pdir);
    return 0;
}

