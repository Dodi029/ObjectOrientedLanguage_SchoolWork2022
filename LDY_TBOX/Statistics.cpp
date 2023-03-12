#include <iostream>
#include <string>
#include "Statistics.h"
using namespace std;

int Statistics::totalRevenue(Screen* pScreen) {     // �� ������ ����ϴ� �Լ�
    int sum = 0;        // �ʱⰪ = 0
    Ticket** ticket = pScreen->getTicketArray();        // ���������͸� ���� pScreen->getTicketArray�� ����
    for (int i = 0; i < pScreen->getRowMax(); i++) {        // �ݺ����� ���� ��ȭ�� �ִ� �� �� ��ŭ
        for (int j = 0; j < pScreen->getColMax(); j++) {        // ��ȭ�� �ִ� �� ��ŭ �ݺ�
            sum += ticket[i][j].getPayAmount();    // ������ ���� ��� ����
        }
    }
    return sum;     // ������ �� ��(�ݾ�)�� ����
}

int Statistics::totalSalesCount(Screen* pScreen)        // �� �Ǹ��� Ƽ�ϼ��� ���ϴ� �Լ�
{
    int count = 0;      // �ʱⰪ 0
    Ticket** ticket = pScreen->getTicketArray();        // ���������͸� ���� pScreen->getTicketArray()�� ����
    for (int i = 0; i < pScreen->getRowMax(); i++) {        // �ݺ����� ���� ��ȭ�� �ִ� �� ����ŭ
        for (int j = 0; j < pScreen->getColMax(); j++) {        // ��ȭ�� �ִ� �� ��ŭ �ݺ�
            if (ticket[i][j].getCheck() == SEAT_COMPLETION_MARK) {    // �����Ͱ� ����Ų �¼��� ������ ǥ���� ��
                count++;        // ������ �÷� �� �� �ڸ��� �����Ǿ� �� ǥ�� �ȷȴ��� Ȯ��
            }
        }
    }
    return count;       // �� Ƽ�� ���� ����
}