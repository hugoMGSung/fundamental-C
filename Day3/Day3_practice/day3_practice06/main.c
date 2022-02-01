// 문자열 길이 계산
#include <stdio.h>
#include <string.h>  // wcslen 함수를 사용하기 위해!
#include <locale.h>  // setlocale 함수를 사용하기 위해!

int main()
{
    wchar_t str[64];
    int len;

    setlocale(LC_ALL, "ko-KR");
    wprintf(L"문자열 입력 : ");
    _getws_s(str, 64);

    wprintf(L"\n입력된 문자열은 [ %s ] 입니다\n", str);
    // wcslen 함수를 사용하여 문자열의 길이를 계산한다.
    len = wcslen(str);
    wprintf(L"입력된 문자열의 길이 = %d\n", len);
    return 0;
}