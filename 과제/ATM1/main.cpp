#include "Bank.h"
#include <conio.h>

int main() {
	Bank b;

	char menu;
	
	do {
		system("cls");
		cout << "=======================" << endl;
		cout << "�޴�" << endl;
		cout << "=======================" << endl;
		cout << "1. ���� ����" << endl;
		cout << "2. ���� ����" << endl;
		cout << "3. ��ü �������� ���" << endl;
		cout << "4. ���� �������� ���" << endl;
		cout << "5. �Ա�" << endl;
		cout << "6. ���" << endl;
		cout << "7. ����" << endl;
		cout << "=======================" << endl;
		cout << "�޴� ���� : ";
		cin >> menu;

		switch(menu) {
			case '1':
				b.���°���();
				break;
			case '2':
				b.��������();
				break;
			case '3':
				b.��ü�������();
				break;
			case '4':
				b.���ϰ������();
				break;
			case '5':
				b.�Ա�();
				break;
			case '6':
				b.���();
				break;
			default:
				;
		}
		cout << "=======================" << endl;
		cout << "�ƹ� Ű�� �����ʽÿ�...";
		getch();
	} while(menu >= '1' && menu <= '6');

	return 0;
}