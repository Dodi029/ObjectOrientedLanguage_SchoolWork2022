#include <iostream>
using namespace std;

#include "Account.h"
#include "ATMachine.h"

int main()
{
	int select;
	// 고객수(100명), ATM 잔금 초기화, 관리자 암호
	ATMachine atm(100, 50000, "admin");
	while (1)
	{
		atm.displayMenu();
		cout << "메뉴를 선택하세요 : ";
		cin >> select;
		cout << endl;
		switch (select)
		{
		case 1:
			atm.createAccount();
			break;
		case 2:
			atm.checkMoney();
			break;
		case 3:
			atm.depositMoney();
			break;
		case 6:
			atm.closeAccount();
			break;
		case 4:
			atm.widrawMoney();
			break;
		case 9:
			cout << "안녕히 가세요." << endl;
			goto EXIT;
		default:
			cout << "번호 확인 후 다시 입력하세요." << endl << endl;
		}
	}
EXIT:
	return 0;
}