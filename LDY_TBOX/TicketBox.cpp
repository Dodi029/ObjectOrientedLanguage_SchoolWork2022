#include <iostream>
#include "Screen.h"
#include "TicketBox.h"
#include "Statistics.h"
using namespace std;

// ��ũ�� ��ü ����
void TUKoreaTBox::Initialize() {
    // Screen(��ȭ����, Ƽ�ϰ���, �¼�(nRowMax), �¼�(nColMax))
    pThrillerScreen = new  ThrillerScreen("������Ƽ��", 10000, 20, 15);      // ��ȭ ���� ���� ����
    pActionScreen = new ActionScreen("��ũ����Ʈ", 12000, 20, 20);           // ��ȭ ���� ���� ����
    pSFScreen = new SFScreen("�Ƴ�", 30000, 12, 12);                          // ��ȭ ���� ���� ����
}

TUKoreaTBox::TUKoreaTBox() {
    pThrillerScreen = NULL;     // �ʱ�ȭ
    pActionScreen = NULL;       // �ʱ�ȭ
    pSFScreen = NULL;           // �ʱ�ȭ
}

TUKoreaTBox::~TUKoreaTBox() {
    delete pThrillerScreen;     // ���� ������ ��ȭ ���� �Ҹ�
    delete pActionScreen;       // ���� ������ ��ȭ ���� �Ҹ�
    delete pSFScreen;           // ���� ������ ��ȭ ���� �Ҹ�
}

Screen* TUKoreaTBox::selectMenu() {           // TicketBox.h�� �ִ� selectMenu�� ����
    cout << "------------------------------------" << endl;
    cout << "         �󿵰� ���� �޴�   " << endl;
    cout << "------------------------------------" << endl;
    cout << "1.  ������  ��ȭ 1��" << endl;
    cout << "2.  �׼�   ��ȭ 2��" << endl;
    cout << "3.   SF   ��ȭ 3��" << endl;
    cout << "9.  ���   ����" << endl;
    cout << endl << "����(1~3) �׿� ���� : ";

    int select;       // ����ڰ� ������ ��ȣ�� ������ ����
    cin >> select;    // ������ ������ ����ڰ� �Է��� ��ȣ ����
    cout << endl;     // �������� ���� ���� �ٷ� ���� �ڵ�

    switch (select) {   // ����ڰ� �Է��� ��ȣ�� ���� �ٸ� �Լ� ����
    case 1:        // 1�� �Է� ��
        return pThrillerScreen;   // ������ ��ȭ�� �̵�
    case 2:        // 2�� �Է� ��
        return pActionScreen;     // �׼� ��ȭ�� �̵�
    case 3:        // 3�� �Է� ��
        return pSFScreen;  // SF ��ȭ�� �̵�
    case 9:         // 9�� �Է� ��
        Manage();   // ������ ��� �Լ� ����
        return NULL;       
    default:       // �� �� ��ȣ �Է� ��
        return NULL;            // ���α׷� ����
    }

}

void TUKoreaTBox::Manage() {        // ������ ��� 
    string PWD;         // �Է��� ��й�ȣ�� ������ ����
    Statistics sta;         // Statistics ���� ����
    int totalcount = 0;     // �� Ƽ�� �Ǹŷ� 0���� �ʱⰪ ����

    cout << "------------------------------------" << endl;
    cout << "             ������ �޴�" << endl;
    cout << "------------------------------------" << endl;
    cout << "������ ��й�ȣ �Է� : ";
    cin >> PWD;     // �Է��� ������ ��й�ȣ ����

    if (PWD == TICKETBOX_MANAGER_PWD) {     // ������ ����� ��й�ȣ�� �Է��� ��й�ȣ�� ���� ��
        totalcount += sta.totalSalesCount(pThrillerScreen);     // ������ �󿵰����� �Ǹŵ� Ƽ�ϴ� totalcount �ϳ��� ����
        totalcount += sta.totalSalesCount(pActionScreen);       // �׼� �󿵰����� �Ǹŵ� Ƽ�ϴ� totalcount �ϳ��� ����
        totalcount += sta.totalSalesCount(pSFScreen);           // SF �󿵰����� �Ǹŵ� Ƽ�ϴ� totalcount �ϳ��� ����

        cout << endl;
        cout << "1. ������ �󿵰� �����ݾ� : " << sta.totalRevenue(pThrillerScreen) << " ��" << endl;  // ������ �󿵰� ���� �ݾ� ���
        cout << "2. �׼� �󿵰� �����ݾ� : " << sta.totalRevenue(pActionScreen) << " ��" << endl;      // �׼� �󿵰� ���� �ݾ� ���
        cout << "3. SF �󿵰� �����ݾ� : " << sta.totalRevenue(pSFScreen) << " ��" << endl;            // SF �󿵰� ���� �ݾ� ���
        cout << "4. ��ü Ƽ�� �Ǹŷ� : " << totalcount << " ��" << endl;        // ������ totalcount�� ��ü Ƽ�� �Ǹŷ����� ���
    }
    else {      // ����� ��й�ȣ�� �Է��� ��й�ȣ�� �ٸ����
        cout << endl;  
        cout << "�߸��� ��й�ȣ �Դϴ�." << endl;       // ��й�ȣ�� �߸��Ǿ��ٰ� ���
    }
}