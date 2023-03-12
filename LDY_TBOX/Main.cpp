#include <iostream>
#include <string>
#include "Screen.h"
#include "TicketBox.h"
#include "Statistics.h"
using namespace std;

int main() {
    TUKoreaTBox tBox;
    Screen* screen = NULL;     // NULL�� �ʱ�ȭ
    bool bScreenMenu = true;   // bScreenMenu�� true�� ����
    int select = 0;            // ����ڰ� �Է��� ��ȣ�� ������ ����
    tBox.Initialize(); // 3���� ��ũ�� ��ü ����
    while (1) {       // while�ݺ������� ��ȭ �޴�ȭ�� ��� �� ��ȣ �Է� �ޱ�
        if (bScreenMenu) {      // bScreenMenu�� true�̹Ƿ� 

            screen = tBox.selectMenu();   // TUKoreaTBox�� serlectMenu() ����
            bScreenMenu = false;    // ���� �� bScreenMenu�� false�� �����Ͽ� if�� Ż��
            if (!screen) return 0;  // ���� selectMenu()���� 1,2,3�� �ƴ� �ٸ� ���� �Է��Ͽ�
                                    // default�� ���� NULL�� ���ϵ� ��� ���α׷� ����
        }
        screen->showMovieMenu();   // NULL�� ���ϵ� ��찡 �ƴ� ��� ������ ��ȭ �޴� ���
        cout << "�޴��� �����ϼ���: ";   // ��µ� �����ּ� ����ڰ� �Է��� ��ȣ�� ������ ������ ����
        cin >> select; cout << endl;  // �������� ���� ���� �ٷ� �̵�
        switch (select) {       // switch()���� ���� ����ڰ� �Է��� ��ȣ�� ���� �ٸ� �Լ� ����
        case 1: // ��ȭ ����
            screen->showMovieInfo();   // 1���� ������ ��� ��ȭ ���� ���
            break;               // �ٽ� while()������ �̵�
        case 2: // �¼� ��Ȳ
            screen->showSeatMap();     // 2���� ������ ��� �¼� ���� ���� ���
            break;               // �ٽ� while()������ �̵�
        case 3: // �¼� ����
            screen->reserveTicket();    // 3���� ������ ��� �¼� ���� �ϱ� ����
            break;
        case 4: // �¼� ���� ���
            screen->cancelReservation();    // 4���� ������ ��� �¼� ���� ��� ����
            break;
        case 5: // ����
            screen->Payment();      // �����ϴ� �Լ� ����
            break;
        case 7: // ��ũ�� ���� �޴�
            bScreenMenu = true;        //   bScreenMenu()�� true�� �����Ͽ� �ٽ� while()�ݺ����� if()������ ���ư�
            break;      // while()������ ���ư�

        }
    }
    return 0;
}
