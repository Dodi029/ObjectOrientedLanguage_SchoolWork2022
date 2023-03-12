#include <iostream>
using namespace std;

#include "Account.h"
#include "ATMachine.h"
#include "Statistics.h"

int main() {
	int select;

	// ����(100��), ATM �ܱ� �ʱ�ȭ, ������ ��ȣ
	ATMachine atm(100, 50000, "admin");

	while (1) {
		atm.displayMenu();
		cout << "�޴��� �����ϼ��� : ";
		cin >> select;
		cout << endl;

		switch (select) {
		case 1:
			atm.createAccount();
			break;
		case 2:
			atm.checkMoney();
			break;
		case 3:
			atm.depositMoney();
			break;
		case 4:
			atm.widrawMoney();
			break;
		case 5:
			atm.transfer();
			break;
		case 6:
			atm.closeAccount();
			break;
		case 7:
			atm.managerMode();
			break;
		case 9:
			cout << "������ �� �̿��� �ּ���." << endl;
			return 0;

		default:
			cout << "�ٽ� �������ּ���.." << endl;
		}
	}
}