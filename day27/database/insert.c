#include <mysql/mysql.h>
#include <string.h>
#include <stdio.h>

int main(int argc,char* argv[])
{
	MYSQL *conn;
	char *server = "localhost";
	char *user = "root";
	char *password = "wy2021";
	char *database = "39th";//要访问的数据库名称
    char query[200]="insert into hero (id, name, age) values (7,'zhaoxin', 78)";
	int queryResult;

	conn = mysql_init(NULL);

	if(!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{
		printf("Error connecting to database: %s\n", mysql_error(conn));
	}
    else
    {
		printf("Connected...\n");
	}

	queryResult = mysql_query(conn, query);
	if(queryResult)
	{
		printf("Error making query:%s\n", mysql_error(conn));
	}
    else
    {
		printf("insert success\n");
	}
	mysql_close(conn);

	return 0;
}
