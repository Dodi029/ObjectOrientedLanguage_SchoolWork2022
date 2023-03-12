#include <iostream>
#include <string>
#include "Screen.h"
#include "TicketBox.h"

using namespace std;

int main() {
	KpuTicketBox tBox;
	Screen* screen = NULL;
	bool bScreenMenu = true;
	int select = 0;
	tBox.Initialize(); // 3���� ��ũ�� ��ü ����
	while (1) {
		if (bScreenMenu) {
			screen = tBox.selectMenu();
			bScreenMenu = false;
			if (!screen) return 0;
		}
		screen->showMovieMenu();
		cout << endl;
		cout << "�޴��� �����ϼ���: ";
		cin >> select; cout << endl;
		switch (select) {
		case 1: // ��ȭ ����
			screen->showMovieInfo();
			break;
		case 2: // �¼� ��Ȳ
			screen->showSeatMap();
			break;
		case 3: // �¼� ����
			screen->reserveTicket();
			break;
		case 4: // ���� ���
			screen->cancelReservation();
			break;
		case 5: // ����
			screen->Payment();
			break;
		case 7: // ��ũ�� ���� �޴�
			bScreenMenu = true;
			break;
		default:
				cout << "�ٽ� �Է��ϼ���." << endl;
		}
	}
	return 0;
}
