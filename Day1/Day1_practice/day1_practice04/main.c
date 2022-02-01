/* ASCII¿Í char */
// American Standard Code for Information Interchange
#include <stdio.h>
#include <locale.h>

void main() {
	printf("sizeof(char):%d byte\n", sizeof(char));

	printf("%c:%d %#x\n", '0', '0', '0');
	printf("%c:%d %#x\n", 'A', 'A', 'A');
	printf("%c:%d %#x\n", 'a', 'a', 'a');

	// ¹®ÀÚ¸®ÅÍ·²
	printf("sizeof('a'):%d bytes\n", sizeof('a'));

	// ´Ü ÇÑ±Û
	char ch = '¤¡';
	printf("%c\n", ch);

	printf("sizeof(wchar_t):%d byte\n", sizeof(wchar_t));
	// wchar_t
	setlocale(LC_ALL, "KOREAN");
	wchar_t ch2 = L'¤¡';
	wprintf(L"%c\n", ch);

	putwchar(L'È«');
	putwchar(L'\n');
	_putws(L"È«±æµ¿");
}