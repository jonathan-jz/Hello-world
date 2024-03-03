#include<func.h>
int main(int argc, char * argv[]){
    ARGS_CHECK(argc,2);
    FILE *fp= fopen("./file1","a+");

    fseek(fp,0,SEEK_SET);    //从偏移量为头部
    char line[100];

    for(int i =0 ;i<3;i++){
        if(fgets(line,sizeof(line),fp)!=NULL){
            printf("%s",line);
        }
    }
    char ch[200];
    scanf("%s",ch);
    printf("Current position :%ld\n",ftell(fp));
    fprintf(fp,"%s\n",&ch);

    fclose(fp);

    return 0;
}