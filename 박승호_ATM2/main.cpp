#include <iostream>
#include <string>
#include "ATMachine.h"
#include "Account.h"
#include "Statistics.h"

using namespace std;

int main()
{
	int select;
	ATMachine atm(100, 50000, "admin");
	// (고객수, ATM 잔금 초기화, 관리자 암호)

	while (1)
	{
		atm.displayMenu();
		cout << "메뉴를 선택하세요 : ";
		cin >> select;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << endl;
		cin.clear();
		
		switch (select) {
		case 1:
			atm.createAccount();
			break;
		case 2:
			if (atm.getnCurrentAccountNum() == 0)
				cout << "\n계좌가 등록되지 않았습니다." << endl;
			else
				atm.checkMoney();
			break;
		case 3:
			if (atm.getnCurrentAccountNum() == 0)
				cout << "\n계좌가 등록되지 않았습니다." << endl;
			else
				atm.depositMoney();
			break;
		case 4:
			if (atm.getnCurrentAccountNum() == 0)
				cout << "\n계좌가 등록되지 않았습니다." << endl;
			else
				atm.widrawMoney();
			break;
		case 5:
			if (atm.getnCurrentAccountNum() < 2)
				cout << "\n두 개 이상의 계좌가 등록되지 않았습니다." << endl;
			else
				atm.transfer();
			break;
		case 6:
			atm.closeAccount();
			break;
		case 7:
			atm.managerMode();
			break;
		case 9:
			cout << "안녕히가세요." << endl;
			return 0;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}
}