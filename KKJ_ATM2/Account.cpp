#include "Account.h"
#include "ATMachine.h"
#include <iostream>
using namespace std;

inline bool Account::authenticate(int id, string passwd)
{
	if (nID == id && strPassword == passwd)
		return AUTHENTIFICATION_SUCCESS;
	else
		return false;
}

Account::Account(){
	nID = -1;
	nBalance = 0;
	strAccountName;
	strPassword;
}

void Account::create(int id, int money, string name, string password)
{
	nID = id;
	nBalance = money;
	strAccountName = name;
	strPassword = password;
}

int Account::check(int id, string password)
{
	if (authenticate(id, password))
		return nBalance;
	else
		return AUTHENTIFICATION_FAIL;
}

void Account::close()
{
	cout << nID << "번 계좌가 해지되었습니다. 감사합니다." << endl;
	this->nID = -1;
}

int Account::deposit(int id, string password, int money)
{

	if (authenticate(id, password))
	{
		nBalance += money;
		return nBalance;
	}
	else
		return AUTHENTIFICATION_FAIL;

}

int Account::widraw(int id, string password, int money)
{

	if (authenticate(id, password))
	{
		if (nBalance >= money)
		{
			nBalance = nBalance - money;
			return nBalance;
		}
		else
			return -1;
	}
	else
		return AUTHENTIFICATION_FAIL;
	
}

int Account::deposit(int id, int money)
{
	if (this->nID = id)
	{
		nBalance += money;
		return nBalance;
	}
	else
		return -1;
		
}


