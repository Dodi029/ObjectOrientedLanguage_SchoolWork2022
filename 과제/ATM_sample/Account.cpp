#include <iostream>
#include <random>
#include <string>
using namespace std;

#include "Account.h"

Account :: Account()
{
	nID = -1;
	nBalance = 0;
}

inline bool Account :: authenticate(int id, string passwd) // 인증 성공 : true(1), 인증 실패 : false(0)
{
	if (getAcctID() == id)
	{
		if (strPassword.compare(passwd) == 0)
			return true;
		else
		{
			cout << endl << "비밀번호가 다릅니다." << endl;
			return false;
		}
	}
	else
		return false;
}

void Account::create(int id, int money, string name, string password) // 계좌 개설
{
	//random_device rd;                                //양질의 시드값얻기위함
	//mt19937 gen(rd());                               //난수 생성 엔진 객체정의
	//uniform_int_distribution<int> dis(BASE_ACCOUNT_ID, 1000);    //난수 범위 설정
	nBalance = money;
	strAccountName = name;
	strPassword = password;
	nID = id;
	cout << strAccountName << "님 " << getAcctID() << "번 계좌번호가 정상적으로 개설되었습니다. 감사합니다." << endl;
}

int Account :: check(int id, string password) // return 값 : nBalance (잔고) or 인증 실패(AUTHENTIFICATION_FAIL)
{
	if (authenticate(id, password))
		return nBalance;
	else
		return AUTHENTIFICATION_FAIL;
}

void Account :: close() // 계좌 해지
{
	if (nBalance == 0)
	{
		cout << getAcctID() << "계좌가 해지되었습니다. 감사합니다." << endl << endl;
		nID = -1;
		nBalance = 0;
		strAccountName.clear();
		strPassword.clear();
	}
	else
		cout << "계좌에 " << nBalance << "원 남아있습니다. #해지불가#" << endl << endl;;
	
	//해지시 계좌 초기 객체 생성처럼 변경
}

int Account::deposit(int id, string password, int money)      //계좌 입금
{
	if (authenticate(id, password))
	{
		nBalance += money;
		return nBalance;
	}
	else
		return AUTHENTIFICATION_FAIL;
}

int Account :: widraw(int id, string password, int money)     //계좌 출금
{
	if (authenticate(id, password))
	{
		if (nBalance < money)
		{
			cout << "출금 할수 없습니다." <<endl;
			return -2;
		}
		else
		{
			nBalance -= money;
			return nBalance;
		}
	}
	else
		return AUTHENTIFICATION_FAIL;
}