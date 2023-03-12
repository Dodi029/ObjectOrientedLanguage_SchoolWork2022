#include "ATMachine.h"
#include "Account.h"
#include "Statistics.h"
#include <random>
#define ID_CHECK 1
using namespace std;

ATMachine::ATMachine(int size, int balance, string password)
{
	nMachineBalance = balance;
	strManagerPassword = password;
	nMaxAccountNum = size;
	nCurrentAccountNum = 0;
	pAcctArray = new Account[nMaxAccountNum];
}

bool ATMachine::isManager(string password)
{
	if (strManagerPassword == password)
		return true;
	else
		return false;
}

void ATMachine::displayReport()
{
	cout << "\n----------------" << endl;
	cout << "ATM  현재 잔고: " << nMachineBalance << "원" << endl;
	cout << "고객 잔고 총액: " << Statistics::sum(pAcctArray, nCurrentAccountNum) << "원" << "(총" << nCurrentAccountNum << "명)" << endl;
	cout << "고객 잔고 평균: " << Statistics::average(pAcctArray, nCurrentAccountNum) << "원" << endl;
	cout << "고객 잔고 최고: " << Statistics::max(pAcctArray, nCurrentAccountNum) << "원" << endl;
	cout << "----------------" << endl;
	cout << "-고객 계좌 목록-" << endl;
	cout << "----------------" << endl;
	Statistics::sort(pAcctArray, nCurrentAccountNum);
}

ATMachine::~ATMachine()
{
	delete[] pAcctArray;
}


void ATMachine::displayMenu()
{
	cout << "----------------" << endl;
	cout << "--TUKOREA BANK--" << endl;
	cout << "----------------" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 계좌 조회" << endl;
	cout << "3. 계좌 입금" << endl;
	cout << "4. 계좌 출금" << endl;
	cout << "5. 계좌 이체" << endl;
	cout << "6. 계좌 해지" << endl;
	cout << "7. 고객 관리" << endl;
	cout << "9. 업무 종료" << endl;
}

void ATMachine::createAccount()
{
	int id;
	int money = 0;
	string name, password;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(BASE_ACCOUNT_ID, 1000);
	id = dis(gen);

	cout << "------개설------" << endl;
	cout << "이름 입력: ";
	cin.ignore();
	getline(cin, name);
	cout << "비밀번호 입력: ";
	getline(cin, password);
	
	pAcctArray[nCurrentAccountNum].create(id, money, name, password);
	cout << name << "님 " << id << "번 계좌번호가 정상적으로 개설되었습니다. 감사합니다." << endl;
	nCurrentAccountNum++;
}

void ATMachine::checkMoney()
{
	int id, check = 0;
	string password;
	cout << "------조회------" << endl;
	cout << "계좌번호 입력: ";
	cin >> id;
	cin.ignore();

	for (int i = 0; i < nCurrentAccountNum; i++)
	{
		if (pAcctArray[i].getAcctID() == id)
		{
			check = ID_CHECK;
			cout << "비밀번호 입력: ";
			getline(cin, password);
			if (pAcctArray[i].check(id, password) != AUTHENTIFICATION_FAIL)
				cout << "현재잔액: " << pAcctArray[i].check(id, password) << "원" << endl;
			else
				cout << "비밀번호가 틀렸습니다." << endl;
		}
	}
	if (check == 0)
		cout << "해당 계좌번호는 존재하지 않습니다." << endl;
}

void ATMachine::closeAccount()
{
	int id, check = 0;
	string password;
	cout << "------해지------" << endl;
	cout << "계좌번호 입력: ";
	cin >> id;
	cin.ignore();
	cout << "비밀번호 입력: ";
	getline(cin, password);
	for (int i= 0; i < nCurrentAccountNum; i++)
	{ 
		if (pAcctArray[i].getAcctID() == id)
		{
			check = ID_CHECK;
			if (pAcctArray[i].check(id, password) != AUTHENTIFICATION_FAIL)
			{
				if (pAcctArray[i].check(id, password) != 0)
				{
					cout << id << "번 계좌를 해지할 수 없습니다.  잔액: " << pAcctArray[i].check(id, password) << "원" << endl;
				}
				else
				{
					pAcctArray[i].close();
				}
			}
			else
				cout << "비밀번호가 틀렸습니다." << endl;
		}
	}
	if (check == 0)
		cout << "해당 계좌번호는 존재하지 않습니다." << endl;
		
}

void ATMachine::despositMoeny()
{
	int id, money, check = 0, d_money;
	string password;
	cout << "------입금------" << endl;
	cout << "계좌번호 입력: ";
	cin >> id;
	cin.ignore();
	for (int i = 0; i < nCurrentAccountNum; i++)
	{
		if (pAcctArray[i].getAcctID() == id)
		{
			check = ID_CHECK;
			cout << "비밀번호 입력: ";
			getline(cin, password);
			if (pAcctArray[i].check(id, password) != AUTHENTIFICATION_FAIL)
			{
				cout << "입금액  입력: ";
				cin >> money;
				d_money = pAcctArray[i].deposit(id, password, money);
				cout << "현재 잔액: " << d_money << "원" << endl;
				cout << "입금 완료" << endl;
				nMachineBalance += d_money;
			}
			else
				cout << "비밀번호가 틀렸습니다." << endl;
		}
	}
	if (check == 0)
		cout << "해당 계좌번호는 존재하지 않습니다." << endl;
}

void ATMachine::widrawMoney()
{
	if (nMachineBalance == NEGATIVE_ATM_BALANCE)
		cout << "죄송합니다. ATM 잔액이 부족하니 다른 ATM 이용바랍니다." << endl;
	else
	{
		int id, money, check = 0, w_money = 0;
		string password;
		cout << "------출금------" << endl;
		cout << "계좌번호 입력: ";
		cin >> id;
		cin.ignore();
		for (int i = 0; i < nCurrentAccountNum; i++)
		{
			if (pAcctArray[i].getAcctID() == id)
			{
				check = ID_CHECK;
				cout << "비밀번호 입력: ";
				getline(cin, password);
				if (pAcctArray[i].check(id, password) != AUTHENTIFICATION_FAIL)
				{
					cout << "출금액  입력: ";
					cin >> money;
					w_money = pAcctArray[i].widraw(id, password, money);
					if (w_money > -1)
					{
						if (nMachineBalance >= money)
						{
							cout << "현재 잔액: " << w_money << "원" << endl;
							cout << "출금 완료" << endl;
							nMachineBalance -= w_money;
						}
					}
					else
					{
						cout << "잔액 부족" << endl;
						cout << "현재잔액: " << pAcctArray[i].check(id, password) << "원" << endl;
					}
				}
				else
					cout << "비밀번호가 틀렸습니다." << endl;
			}
		}
		if (check == 0)
			cout << "해당 계좌번호는 존재하지 않습니다." << endl;
	}
}

void ATMachine::transfer()
{
	int id, check = 0, t_id, t_id_check = 0, t_money = 0, i_money = 0, balance = 0;
	string password;
	cout << "------이체------" << endl;
	cout << "계좌번호 입력: ";
	cin >> id;
	cin.ignore();
	for (int i = 0; i < nCurrentAccountNum; i++)
	{
		if (pAcctArray[i].getAcctID() == id)
		{
			check = ID_CHECK;
			cout << "비밀번호 입력: ";
			getline(cin, password);
			if (pAcctArray[i].check(id, password) != AUTHENTIFICATION_FAIL)
			{
				cout << "이체계좌 입력: ";
				cin >> t_id;
				cin.ignore();
				for (int j = 0; j < nCurrentAccountNum; j++)
				{
					if (pAcctArray[j].getAcctID() == t_id)
					{
						t_id_check = ID_CHECK;
						cout << "이체금액 입력: ";
						cin >> t_money;
						i_money = pAcctArray[i].widraw(id, password, t_money);
						if (i_money > -1)
						{
							pAcctArray[j].deposit(t_id, t_money);
							cout << "현재 잔액: " << i_money << endl;
						}
						else
							cout << "잔액 부족" << endl;
					}
				}
				if (t_id_check == 0)
					cout << "해당 계좌번호는 존재하지 않습니다." << endl;
			}
			else
				cout << "비밀번호가 틀렸습니다." << endl;
		}
	}
	if (check == 0)
		cout << "해당 계좌번호는 존재하지 않습니다." << endl;
}

void ATMachine::managerMode()
{
	string password;
	cout << "------관리------" << endl;
	cout << "관리자 비밀번호 입력: ";
	cin >> password;
	if (isManager(password) == 1)
	{
		cout << "\n관리자입니다." << endl;
		displayReport();
	}

	else
		cout << "관리자 권한이 없습니다." << endl;
}

	