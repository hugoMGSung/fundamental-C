#pragma comment (lib, "libmysql.lib")

#include <winsock.h>
#include <windows.h>
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mysqlip "127.0.0.1"
#define port 3306
#define loginusername "root"
#define loginpassword "mysql_p@ssw0rd"
#define mysqlname "bms"

MYSQL * conn;
MYSQL_RES* sql_result;
MYSQL_ROW sql_row;
int query_stat;

int main() {
	conn = mysql_init(NULL);
	mysql_real_connect(conn, mysqlip, loginusername, loginpassword, mysqlname, port, NULL, 0);

	if (conn == NULL) {
		fprintf(stderr, "연결오류! : %s\n", mysql_error(conn));
		return EXIT_FAILURE;
	}

	printf("연결성공!\n");
	printf("서버버전 %s\n", conn->server_version);

	/*query_stat = mysql_query(conn, "SELECT * FROM books_info");
	if (query_stat != 0) {
		fprintf(stderr, "쿼리오류! : %s\n", mysql_error(conn));
		return EXIT_FAILURE;
	}

	sql_result = mysql_store_result(conn);
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
		printf("%s\n", sql_row[0]);
	}*/

	mysql_close(conn);
	printf("연결종료\n");
	system("pause");
	return EXIT_SUCCESS;
}