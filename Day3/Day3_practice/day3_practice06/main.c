// ���ڿ� ���� ���
#include <stdio.h>
#include <string.h>  // wcslen �Լ��� ����ϱ� ����!
#include <locale.h>  // setlocale �Լ��� ����ϱ� ����!

int main()
{
    wchar_t str[64];
    int len;

    setlocale(LC_ALL, "ko-KR");
    wprintf(L"���ڿ� �Է� : ");
    _getws_s(str, 64);

    wprintf(L"\n�Էµ� ���ڿ��� [ %s ] �Դϴ�\n", str);
    // wcslen �Լ��� ����Ͽ� ���ڿ��� ���̸� ����Ѵ�.
    len = wcslen(str);
    wprintf(L"�Էµ� ���ڿ��� ���� = %d\n", len);
    return 0;
}