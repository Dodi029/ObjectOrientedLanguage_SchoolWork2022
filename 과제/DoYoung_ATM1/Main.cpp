#include<iostream>
using namespace std;

#include "ATMachine.h"
#include "Account.h"

int main() {
	int select;

	ATMachine atm(100, 50000, "admine");

	while (1) {
		atm.displayMunu();
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
		case 6:
			atm.closeAccount();
			break;
		case 9:
			cout << "������ �� �̿��� �ּ���." << endl;
			return 0;

		default:
			cout << "�ٽ� �������ּ���.." << endl;
		}
	}
}