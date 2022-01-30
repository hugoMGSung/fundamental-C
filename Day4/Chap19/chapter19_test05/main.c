/* �������� 5 */
#include <stdio.h>  // printf, fopen_s, fgets, fclose �Լ��� ����ϱ� ����!
#include <stdlib.h> // atoi, malloc, free �Լ��� ����ϱ� ����!

#define MAX_NAME_LEN  16    // �̸��� �ִ� ����

typedef struct StudentData  // �л� 1���� ������ ������ ����ü ����
{
    int num;  // �й�
    char name[MAX_NAME_LEN];  // �̸�
    unsigned int kor, eng, math, total; // ����, ����, ����, ����
} S_DATA;

// ap_src_str ���ڿ����� a_delimiter �Ǵ� NULL ���ڰ� ���ö����� ap_buffer �޸𸮿�
// ���ڿ��� �����Ѵ�. �������, ap_src_str�� "abc,def"��� ����ְ� a_delimiter��
// ','�� ���޵Ǹ� ap_buffer���� "abc"���ڿ��� ����ȴ�.
// �׸��� �� �Լ��� �ڽ��� Ž���� �Ϸ��� ��ġ�� �ּҸ� ��ȯ�Ѵ�. �� ���ÿ� �����ϸ�
// "abc,def" ���ڿ��� ','���ڰ� ��ġ�� �ּҸ� ��ȯ�Ѵ�.
char* GetNextString(char* ap_src_str, char a_delimiter, char* ap_buffer)
{
    // NULL ���� �Ǵ� a_delimiter ���ڰ� ���ö����� �ݺ��ϸ鼭 
    // ap_src_str�� ����Ű�� ���ڸ� ap_buffer�� ����Ű�� �޸𸮿� �����Ѵ�.
    while (*ap_src_str && *ap_src_str != a_delimiter) *ap_buffer++ = *ap_src_str++;

    // ������ ��ġ�� �ִ� ���ڰ� �ٹٲ� �����̸� �ٹٲ� ���� ��� NULL ���ڸ� �߰��Ѵ�.
    // �ٹٲ� ���ڰ� �ƴ϶�� ���ڿ��� ���� NULL ���ڸ� �߰��Ѵ�.
    if (*(ap_buffer - 1) == '\n') *(ap_buffer - 1) = 0;
    else *ap_buffer = 0;

    // ap_src_str �����Ͱ� ����Ű�� ��ġ�� ���ڿ� �и��� ���� a_delimiter ������
    // ��ġ�̰ų� NULL ������ ��ġ�Դϴ�. ���� a_delimiter ���� ��ġ�� ����Ų�ٸ�
    // ���� ���ڴ� ',' ���� ��ġ���� ����� ���̱� ������ �ǳʶ��.
    if (*ap_src_str == a_delimiter) ap_src_str++;

    // Ž���� �Ϸ��� ��ġ�� �ּҸ� ��ȯ�Ѵ�.
    return ap_src_str;
}

int GetDataCount(FILE* ap_file) // ���� ���Ͽ� ����� �������� ������ ��´�.
{
    // �Լ��� ȣ��� ������ ���� �б� ��ġ�� old_pos�� �����Ѵ�.
    int old_pos = ftell(ap_file), count = 0;
    char temp_string[128];
    // ���� ���ڸ� üũ�ؼ� �� ���� �����Ͱ� �ִ��� Ȯ���Ѵ�.
    while (NULL != fgets(temp_string, 128, ap_file)) count++;
    // ���� ���� �б� ��ġ�� �����Ѵ�.
    fseek(ap_file, old_pos, SEEK_SET);
    // ������ ������ ��ȯ�Ѵ�.
    return count;
}

// ���Ͽ��� �л� ������ �о S_DATA�� ����� �迭�� �����Ѵ�.
int ReadData(const char* ap_file_name, S_DATA** ap_data, unsigned int* ap_data_count)
{
    FILE* p_file = NULL;  // ������ ��� ����� ���� ������!
    // fopen_s �Լ��� ����Ͽ� ������ �ؽ�Ʈ ������ �б� ���� ����!
    // �� �Լ��� ���� ���⿡ �����ߴٸ� 0�� ��ȯ�Ѵ�.
    if (0 == fopen_s(&p_file, ap_file_name, "rt")) {
        // ���Ͽ��� �� ���� ������ �о ������ ������ 
        // ��ǥ�� �������� �и��� ���ڿ��� ������ ����
        char one_line_string[128], str[32], * p_pos;
        // ���Ͽ��� �� ���� �����͸� �д´�. 
        // ������ ù ���� Ÿ��Ʋ ������ ó������ �ʰ� �Ѿ��.
        if (NULL != fgets(one_line_string, 128, p_file)) {
            // ���� ���Ͽ� ����� �������� ������ ��´�.
            *ap_data_count = GetDataCount(p_file);
            if (*ap_data_count > 0) {  // ������ ������ ��ȿ���� üũ�Ѵ�.
                // �������� ������ŭ ������ �޸𸮸� �Ҵ��Ѵ�.
                S_DATA* p_data = (S_DATA*)malloc(sizeof(S_DATA) * (*ap_data_count));
                // �Ҵ�� �ּҸ� main �Լ��� p_data �����Ϳ� �����Ѵ�.
                *ap_data = p_data;
                // ������ ������ �л��� ���� ������ �о���δ�.
                while (NULL != fgets(one_line_string, 128, p_file)) {
                    p_pos = GetNextString(one_line_string, ',', str); // �й��� �д´�.
                    p_data->num = atoi(str);  // �й��� ������ �����Ѵ�.
                    p_pos = GetNextString(p_pos, ',', p_data->name); // �̸��� �д´�.
                    p_pos = GetNextString(p_pos, ',', str); // ���� ������ �д´�.
                    p_data->kor = atoi(str);  // ���� ������ ������ �����Ѵ�.
                    p_pos = GetNextString(p_pos, ',', str); // ���� ������ �д´�.
                    p_data->eng = atoi(str);  // ���� ������ ������ �����Ѵ�.
                    p_pos = GetNextString(p_pos, ',', str); // ���� ������ �д´�.
                    p_data->math = atoi(str);  // ���� ������ ������ �����Ѵ�.

                    // ���κ� ���� ������ �ջ��Ѵ�.
                    p_data->total = p_data->kor + p_data->eng + p_data->math;
                    p_data++; // ���� ���� ��ġ�� �̵��Ѵ�.
                }
            }
        }
        fclose(p_file);  // ������ �ݴ´�.
        return 1;  // ���Ͽ��� ���� �б� ����
    }
    return 0;  // ���Ͽ��� ���� �б� ����
}

// �о���� �л� ������ ��� ����Ѵ�.
void ShowData(S_DATA* ap_data, unsigned int a_count)
{
    printf("-------------------------------------------------------------\n");
    printf("    �й�         �̸�   ����  ����  ����     ����     ���\n");
    printf("-------------------------------------------------------------\n");

    unsigned int sum = 0; // �б� ��ü ����� ����ϱ� ����
    for (unsigned int i = 0; i < a_count; i++, ap_data++) {
        // �л����� ������ ����Ѵ�.
        printf("  %08u %10s   %3d   %3d   %3d,      %3d    %.2f\n",
            ap_data->num, ap_data->name, ap_data->kor, ap_data->eng, ap_data->math,
            ap_data->total, ap_data->total / 3.0);
        sum += ap_data->total; // �л��� ������ �ջ��Ѵ�.
    }
    printf("-------------------------------------------------------------\n");
    // �о���� ������ 1�� �̻��� ��쿡�� �ο����� ��ü ����� ����Ѵ�.
    if (a_count > 0) {
        printf("    �� %d ��, ��ü ��� %.2f\n", a_count, sum / (a_count * 3.0));
        printf("-------------------------------------------------------------\n");
    }
}

// �о���� �л� ������ �����Ѵ�. ������ �л��� ������ �й����θ� �����ϴ�.
void ModifyData(S_DATA* ap_data, unsigned int a_count)
{
    int num, select;
    printf("������ ������ �л��� �й��� �Է��ϼ��� : ");
    scanf_s("%d", &num);  // ������ �л��� �й��� �Է� �޴´�!

    for (unsigned int i = 0; i < a_count; i++, ap_data++) {
        if (ap_data->num == num) {  // ������ �л� ������ ã�´�.
            printf("������ �׸��� �����ϼ���.\n");
            printf("1.�̸�,  2.����,  3.����, 4.����\n����: ");
            scanf_s("%d", &select);  // � �׸��� ������ ������ �Է� �޴´�!
            switch (select) {
            case 1:
                printf("������ �̸��� �Է��ϼ��� : ");
                scanf_s("%s", ap_data->name, MAX_NAME_LEN);  // �̸� ����
                break;
            case 2:
                printf("������ ���� ������ �Է��ϼ��� : ");
                scanf_s("%u", &ap_data->kor); // ���� ���� ����
                break;
            case 3:
                printf("������ ���� ������ �Է��ϼ��� : ");
                scanf_s("%u", &ap_data->eng); // ���� ���� ����
                break;
            case 4:
                printf("������ ���� ������ �Է��ϼ��� : ");
                scanf_s("%u", &ap_data->math); // ���� ���� ����
                break;
            }
            if (select >= 2 && select <= 4) {  // ������ ����Ǹ� ���κ� ������ �ٽ� �ջ��Ѵ�.
                ap_data->total = ap_data->kor + ap_data->eng + ap_data->math;
            }
            return;
        }
    }
    printf("[����] �Է��� �й��� �л��� �����ϴ�.\n");
}

void SaveData(const char* ap_file_name, S_DATA* ap_data, unsigned int a_count)
{
    FILE* p_file = NULL;  // ������ ��� ����� ���� ������!
    // fopen_s �Լ��� ����Ͽ� ������ �ؽ�Ʈ ������ ���� ���� ����!
    // �� �Լ��� ���� ���⿡ �����ߴٸ� 0�� ��ȯ�Ѵ�.
    if (0 == fopen_s(&p_file, ap_file_name, "wt")) {
        // ù �ٿ� Ÿ��Ʋ ������ �����Ѵ�.
        fprintf(p_file, "�й�,�̸�,����,����,����\n");
        // �л��� ����ŭ ������ �����Ѵ�.
        for (unsigned int i = 0; i < a_count; i++, ap_data++) {
            fprintf(p_file, "%d,%s,%u,%u,%u\n", ap_data->num, ap_data->name,
                ap_data->kor, ap_data->eng, ap_data->math);
        }
        printf("%s ���Ͽ� �����͸� �����߽��ϴ�!\n", ap_file_name);
        fclose(p_file);  // ������ �ݴ´�.
    }
}

void main()
{
    S_DATA* p_data = NULL;  // �л� ������ ������ �޸��� �ּҸ� ������ ���� ����
    // �л� ����, ���õ� ����� ������ ���� ����
    unsigned int data_count = 0, select = 0;

    // 'data.csv' ���Ͽ��� �л� ������ �о� ���δ�.
    if (ReadData("data.csv", &p_data, &data_count)) {
        // ����ڰ� 4�� �Է��� ������ ��� �ݺ��Ѵ�.
        while (select != 4) {
            printf("\n\n==========[  �޴�  ]==========\n"); // �޴��� ����Ѵ�.
            printf("1.���� ����\n");
            printf("2.���� ����\n");
            printf("3.���� ����\n");
            printf("4.���α׷� ����\n");

            printf("���� : ");
            // �߸��� �Է¿� ���ؼ� üũ�Ѵ�.
            if (1 == scanf_s("%u", &select)) {
                printf("\n\n");
                // ��ɺ��� �Լ��� ȣ���Ѵ�.
                if (select == 1) ShowData(p_data, data_count);  // ���� ����
                else if (select == 2) ModifyData(p_data, data_count); // ����
                else if (select == 3) SaveData("data.csv", p_data, data_count); // ����             
            }
            else {
                // �߸��� �Է��� ���� �޽��� ��� �Ŀ� ǥ���Է� ���۸� ����.
                printf("\n�߸��� ���� �Է��߽��ϴ�. �ٽ� �Է��ϼ���.\n\n");
                rewind(stdin);
            }
        }
        // �л� ������ �����ϱ� ���� �Ҵ��ߴ� �޸𸮸� �����Ѵ�.
        if (p_data != NULL) free(p_data);
    }
    else {
        printf("data.csv ������ ���� �����ϴ�. ���� ��θ� Ȯ���ϼ���!!\n");
    }

}