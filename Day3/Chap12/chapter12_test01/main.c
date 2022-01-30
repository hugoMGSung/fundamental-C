#include <stdio.h>

void main()
{
	char data[] = { 'D','o','n','\'','t',' ', 'w','o','r','r','y', ',' ,' ' ,'B','e',' ',
	'h', 'a', 'p', 'p', 'y', '!',0 }; /* char data[23] = "Don't worry, Be happy!"; 같은표현임*/
	char ment[] = "걱정 마. 행복할 거야."; /* [ ] 안의 22 를 생략해도 됨 */
	printf("%s\n", data);
	printf("%s\n", ment);
}