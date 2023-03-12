#include <iostream>
#include <string>
#include "ATMachine.h"
#include "Account.h"
#include "Statistics.h"

using namespace std;

Account::Account() {
}

void Account::create(int id, int money, string name, string password) {
	nID = id;
	nBalance = money;
	strAccountName = name;
	strPassword = password;
	cout << "\n" << strAccountName << "님 " << nID << "번 계좌번호가 정상적으로 개설되었습니다. 감사합니다.\n";
}
inline bool Account::authenticate(int id, string passwd) {
	return (this->strPassword == passwd);
}
int Account::check(int id, string password) {
	if (authenticate(id, password))
		return nBalance;
	else
		return AUTHENTIFICATION_FAIL;
}
void Account::close() {
	nID = -1;
	nBalance = 0;
	strAccountName = "";
	strPassword = "";
}
int Account::deposit(int id, string password, int money) {
	if (authenticate(id, password)) {
		nBalance += money;
		return nBalance;
	}
	else
		return AUTHENTIFICATION_FAIL;
}
int Account::deposit(int id, int money) {
	nBalance += money;
	return nBalance;
}
int Account::widraw(int id, string password, int money) {
	if (authenticate(id, password)) {
		nBalance -= money;
		return nBalance;
	}
	else
		return AUTHENTIFICATION_FAIL;
}