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
    scanf("%s",ch);//获取字符串
    printf("Current position :%ld\n",ftell(fp));//当前的位置
    fprintf(fp,"%s\n",&ch);//将信息转移到文件中

    fclose(fp); //关闭文件

    return 0;
}