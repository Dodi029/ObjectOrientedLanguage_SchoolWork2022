#include<stdio.h>

int main() {
    int num = 0;
    int a, tmp, ori;;
    scanf_s("%d", &a);
    ori = a;        // ori�� ������ ����
    while (1) {
        tmp = a % 10;       // tmp�� ���� �ڸ� ���� ����
        a = a / 10 + a % 10;        // �����ڸ��� �����ڸ� ���� ���ϱ�
        a = tmp * 10 + a % 10;
        num++;
        if (a == ori) {
            break;
        }
    }
    printf("%d", num);
}