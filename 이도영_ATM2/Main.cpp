#include <iostream>
using namespace std;

#include "Account.h"
#include "ATMachine.h"
#include "Statistics.h"

int main() {
	int select;

	// 고객수(100명), ATM 잔금 초기화, 관리자 암호
	ATMachine atm(100, 50000, "admin");

	while (1) {
		atm.displayMenu();
		cout << "메뉴를 선택하세요 : ";
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
			cout << "다음에 또 이용해 주세요." << endl;
			return 0;

		default:
			cout << "다시 선택해주세요.." << endl;
		}
	}
}