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
	// (����, ATM �ܱ� �ʱ�ȭ, ������ ��ȣ)

	while (1)
	{
		atm.displayMenu();
		cout << "�޴��� �����ϼ��� : ";
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
				cout << "\n���°� ��ϵ��� �ʾҽ��ϴ�." << endl;
			else
				atm.checkMoney();
			break;
		case 3:
			if (atm.getnCurrentAccountNum() == 0)
				cout << "\n���°� ��ϵ��� �ʾҽ��ϴ�." << endl;
			else
				atm.depositMoney();
			break;
		case 4:
			if (atm.getnCurrentAccountNum() == 0)
				cout << "\n���°� ��ϵ��� �ʾҽ��ϴ�." << endl;
			else
				atm.widrawMoney();
			break;
		case 5:
			if (atm.getnCurrentAccountNum() < 2)
				cout << "\n�� �� �̻��� ���°� ��ϵ��� �ʾҽ��ϴ�." << endl;
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
			cout << "�ȳ���������." << endl;
			return 0;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}
	}
}