#include<func.h>
int main(int argc,char* argv[]){
    //./readdir dir
    ARGS_CHECK(argc,2);
    DIR *pdir = opendir(argv[1]);
    ERROR_CHECK(pdir,NULL,"opendir");
    struct dirent *pdirent;
//    pdirent = readdir(pdir);

    long location ;
    while((pdirent =readdir(pdir))!=NULL){
        if(strcmp(pdirent->d_name,"file1")==0){
            location = telldir(pdir);
        }
        printf("inode = %ld, reclen = %d ,type = %d,name = %s\n",pdirent->d_ino,pdirent->d_reclen,pdirent->d_type,pdirent->d_name);
    }


    puts("----------------------------------------------------------------------");
    seekdir(pdir,location);
    pdirent = readdir(pdir);
    
        printf("inode = %ld, reclen = %d ,type = %d,name = %s\n",pdirent->d_ino,pdirent->d_reclen,pdirent->d_type,pdirent->d_name);



    closedir(pdir);

    return 0;
}

