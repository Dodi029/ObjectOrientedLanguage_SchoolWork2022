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

inline bool Account :: authenticate(int id, string passwd) // ���� ���� : true(1), ���� ���� : false(0)
{
	if (getAcctID() == id)
	{
		if (strPassword.compare(passwd) == 0)
			return true;
		else
		{
			cout << endl << "��й�ȣ�� �ٸ��ϴ�." << endl;
			return false;
		}
	}
	else
		return false;
}

void Account::create(int id, int money, string name, string password) // ���� ����
{
	//random_device rd;                                //������ �õ尪�������
	//mt19937 gen(rd());                               //���� ���� ���� ��ü����
	//uniform_int_distribution<int> dis(BASE_ACCOUNT_ID, 1000);    //���� ���� ����
	nBalance = money;
	strAccountName = name;
	strPassword = password;
	nID = id;
	cout << strAccountName << "�� " << getAcctID() << "�� ���¹�ȣ�� ���������� �����Ǿ����ϴ�. �����մϴ�." << endl;
}

int Account :: check(int id, string password) // return �� : nBalance (�ܰ�) or ���� ����(AUTHENTIFICATION_FAIL)
{
	if (authenticate(id, password))
		return nBalance;
	else
		return AUTHENTIFICATION_FAIL;
}

void Account :: close() // ���� ����
{
	if (nBalance == 0)
	{
		cout << getAcctID() << "���°� �����Ǿ����ϴ�. �����մϴ�." << endl << endl;
		nID = -1;
		nBalance = 0;
		strAccountName.clear();
		strPassword.clear();
	}
	else
		cout << "���¿� " << nBalance << "�� �����ֽ��ϴ�. #�����Ұ�#" << endl << endl;;
	
	//������ ���� �ʱ� ��ü ����ó�� ����
}

int Account::deposit(int id, string password, int money)      //���� �Ա�
{
	if (authenticate(id, password))
	{
		nBalance += money;
		return nBalance;
	}
	else
		return AUTHENTIFICATION_FAIL;
}

int Account :: widraw(int id, string password, int money)     //���� ���
{
	if (authenticate(id, password))
	{
		if (nBalance < money)
		{
			cout << "��� �Ҽ� �����ϴ�." <<endl;
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