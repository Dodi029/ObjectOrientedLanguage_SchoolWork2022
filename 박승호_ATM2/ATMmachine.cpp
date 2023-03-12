#include <iostream>
#include <string>
#include "ATMachine.h"
#include "Account.h"
#include "Statistics.h"

using namespace std;

ATMachine::ATMachine(int size, int balance, string password) {
	nMaxAccountNum = size;
	pAcctArray = new Account[size];
	nMachineBalance = balance;
	strManagerPassword = password;
}

void ATMachine::displayMenu() {
	cout << "--------------------\n";
	cout << "=   TUKOREA BANK   =\n";
	cout << "--------------------\n";
	cout << "1. 계좌 개설\n" << "2. 계좌 조회\n" << "3. 계좌 입금\n"<<"4. 계좌 출금\n"<<"5. 계좌이체\n"
		<< "6. 계좌 해지\n"<<"7. 고객관리\n" << "9. 업무 종료\n";
}

void ATMachine::createAccount() {
	cout << " ------ 개설 ------ \n";
	cout << "이름 입력 : ";
	getline(cin, name);
	cout << "비밀번호 입력 : ";
	cin >> password;
	int id = BASE_ACCOUNT_ID + nCurrentAccountNum;
	pAcctArray[nCurrentAccountNum].create(id, 0, name, password);
	nCurrentAccountNum++;
}

void ATMachine::checkMoney() {
	
	cout << " ------ 조회 ------ \n";
	cout << "계좌번호 입력 : ";
	cin >> id;
	cout << "비밀번호 입력 : ";
	cin >> password;
	for (int i = 0; i < nCurrentAccountNum; i++)
	{
		if (pAcctArray[i].getAcctID() == id) {
			index = pAcctArray[i].check(id, password);
			if (index == -1) {
				cout << "\n계좌번호와 비밀번호가 올바르지 않습니다." << endl;
				break;
			}
			else {
				cout << "\n현재 잔액은 " << index << "원 입니다." << endl;
				break;
			}
		}
		else if (i == nCurrentAccountNum - 1)
			cout << "\n존재하지 않는 계좌번호입니다." << endl;
	}
}
void ATMachine::closeAccount() {
	cout << " ------ 조회 ------ \n";
	cout << "계좌번호 입력 : ";
	cin >> id;
	cout << "비밀번호 입력 : ";
	cin >> password;
	for (int i = 0; i < nCurrentAccountNum; i++)
	{
		if (pAcctArray[i].getAcctID() == id) {
			index = pAcctArray[i].check(id, password);
			if (index == -1) {
				cout << "\n계좌번호와 비밀번호가 올바르지 않습니다." << endl;
				break;
			}
			else if (index == 0) {
				cout << id << "계좌가 해지되었습니다." << endl;
				pAcctArray[i].close();
				break;
			}
			else {
				cout << id << "계좌에 잔액이 남아있습니다." << endl;
				break;
			}
		}
		else if (i == nCurrentAccountNum - 1)
			cout << "\n존재하지 않는 계좌번호입니다." << endl;
	}
}
void ATMachine::depositMoney() {
	cout << " ------ 입금 ------ \n";
	cout << "계좌번호 입력 : ";
	cin >> id;
	cout << "비밀번호 입력 : ";
	cin >> password;
	cout << "입금액 입력 : ";
	cin >> money;
	for (int i = 0; i < nCurrentAccountNum; i++)
	{
		if (pAcctArray[i].getAcctID() == id) {
			index = pAcctArray[i].deposit(id, password, money);
			if (index == -1) {
				cout << "\n계좌번호와 비밀번호가 올바르지 않습니다." << endl;
				break;
			}
			else {
				cout << "\n현재 잔액 : " << index  << endl;
				cout << "입금 완료" << endl;
				break;
			}
		}
		else if (i == nCurrentAccountNum - 1)
			cout << "\n존재하지 않는 계좌번호입니다." << endl;
	}
}
void ATMachine::widrawMoney() {
	cout << " ------ 출금 ------ \n";
	cout << "계좌번호 입력 : ";
	cin >> id;
	cout << "비밀번호 입력 : ";
	cin >> password;
	cout << "출금액 입력 : ";
	cin >> money;
	for (int i = 0; i < nCurrentAccountNum; i++)
	{
		if (pAcctArray[i].getAcctID() == id) {
			index = pAcctArray[i].widraw(id, password, money);
			if (index == -1) {
				cout << "\n계좌번호와 비밀번호가 올바르지 않습니다." << endl;
				break;
			}
			else if (index < 0) {
				cout << "계좌에 잔액이 부족합니다.\n" << endl;
			}
			else {
				cout << "\n현재 잔액 : " << index << endl;
				cout << "출금 완료" << endl;
				break;
			}
		}
		else if (i == nCurrentAccountNum - 1)
			cout << "\n존재하지 않는 계좌번호입니다." << endl;
	}
}
void ATMachine::transfer() {
	cout << " ------ 이체 ------ \n";
	cout << "계좌번호 입력 : ";
	cin >> id1;
	cout << "비밀번호 입력 : ";
	cin >> password;
	for (int i = 0; i < nCurrentAccountNum; i++) {
		if (pAcctArray[i].getAcctID() == id1)
			store = i;		//입력한 계좌 저장
	}
	cout << "이체계좌 입력 : ";
	cin >> id2;
	cout << "이체금액 입력 : ";
	cin >> money;
	for (int i = 0; i < nCurrentAccountNum; i++)
	{
		if (pAcctArray[i].getAcctID() == id2) {
			index = pAcctArray[store].widraw(id1, password, money);
			if (index == -1) {
				cout << "\n계좌번호와 비밀번호가 올바르지 않습니다." << endl;
				return;
			}
			else if (index == 1) {
				cout << "\n계좌에 돈이 충분하지 않습니다." << endl;
				return;
			}
			else {
				cout << "\n현재 잔액은 " << index << "원 입니다." << endl;
				index = pAcctArray[i].deposit(id2 ,money);
				cout << "이체 완료" << endl;
				break;
			}
		}
		else if (i == nCurrentAccountNum - 1) {
			cout << "\n존재하지 않는 계좌번호입니다.\n" << endl;
			return;
		}
	}
}
bool ATMachine::isManager(string password) {
	return (strManagerPassword == password);
}
void ATMachine::displayReport() {
	cout << " \n------ 관리 ------ " << endl;
	cout << "관리자 비밀번호 입력 : ";
	cin >> password;
	if (isManager(password)) {
		cout << "\n관리자입니다.\n" << endl;
		cout << "---------------------\n"<<endl;
		cout << "ATM 현금 잔고 : " << nMachineBalance + s.sum(pAcctArray, nCurrentAccountNum) << endl;
		cout << "고객 잔고 총액 : " << s.sum(pAcctArray, nCurrentAccountNum) << "(총 " << nCurrentAccountNum << "명)" << endl;
		cout << "고객 잔고 평균 : " << a.average(pAcctArray, nCurrentAccountNum) << endl;
		cout << "고객 잔고 최고 : " << m.max(pAcctArray, nCurrentAccountNum) << endl;
		cout << "---------------------\n" << endl;
		cout << "\n-- 고객 개좌 목록 -- " << endl;
		cout << "---------------------- " << endl;
		so.sort(pAcctArray, nCurrentAccountNum);
	}
	else
		cout << "비밀번호가 틀렸습니다." << endl;
}
void ATMachine::managerMode() {
	displayReport();
}
ATMachine::~ATMachine() {
	delete[] pAcctArray;
}