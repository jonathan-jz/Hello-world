#include <head.h>
#include<mysql/mysql.h>

int main(int argc, char **argv)
{
    MYSQL * conn;

    MYSQL *ret = NULL;
    MYSQL_RES * res;
    MYSQL_ROW row;

    char *host = NULL;
    char *user = NULL;
    char *passwd = "wy2021";
    char *db = "40th";

    char query[128] = "select * from hero where name = '";
    sprintf(query, "%s%s%s", query, argv[1], "'");

    //初始化数据库  
    conn = mysql_init(NULL);
    if(NULL == conn){
        printf("error init\n");
        return -1;
    }

    //连接数据库
    ret = mysql_real_connect(conn, host, user, passwd, db, 0, NULL, 0);
    if(NULL == ret){
        printf("connect error: %s\n", mysql_error(conn));
        return -1;
    }

    int queryRet = mysql_query(conn, query);
    if(0 != queryRet){
        printf("query error: %s\n", mysql_error(conn));
    }

    else{
        //保存结果
        res = mysql_store_result(conn);
        printf("mysql_num_rows = %d\n", (int)mysql_num_rows(res));

        //检索结果集的下一行数据，保存在row中
        row = mysql_fetch_row(res);

        if(NULL == row){
            printf("dont find any data\n");
        }

        else{
            do{
                //检索列
                for(int i = 0; i < (int)mysql_num_fields(res); ++i){
                    printf("%8s", row[i]);
                }
                printf("\n");
            }while(NULL != (mysql_fetch_row(res)));
        }

        mysql_free_result(res);
    }

    //断开连接
    mysql_close(conn);
    return 0;
}

