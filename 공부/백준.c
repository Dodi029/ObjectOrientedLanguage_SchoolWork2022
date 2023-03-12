#include<stdio.h>

int main() {
    int num = 0;
    int a, tmp, ori;;
    scanf_s("%d", &a);
    ori = a;        // ori에 원본값 저장
    while (1) {
        tmp = a % 10;       // tmp에 일의 자리 숫자 저장
        a = a / 10 + a % 10;        // 십의자리와 일의자리 숫자 더하기
        a = tmp * 10 + a % 10;
        num++;
        if (a == ori) {
            break;
        }
    }
    printf("%d", num);
}