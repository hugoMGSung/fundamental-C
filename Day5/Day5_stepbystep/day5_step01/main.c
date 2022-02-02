#pragma comment (lib, "libmysql.lib")

#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <my_global.h>
#include <mysql.h>

int main() {
	printf("MySQL info = %s\n", mysql_get_client_info());
	
	system("pause");
	return EXIT_SUCCESS;
}