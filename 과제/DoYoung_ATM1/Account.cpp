#include<iostream>
#include<string>
using namespace std;

#include "Account.h"
#include "Account.h"

Account::Account() {
	int nID = -1;														// �ʱⰪ
	int nBalance = 0;
}

inline bool Account::authenticate(int id, string passwd) {				// ���� ��(����:true=1, ����:false=0)
	if (getAcctID() == id) {											// ���̵� ������ Ȯ��
		if (strPassword.compare(passwd) == 0)							// ��й�ȣ�� ������ Ȯ��
			return true;												// �Ѵ� ������ ���� 1
		else {
			return false;												// ����� Ʋ���� ���� 0
		}
	}
	else {
		return false;													// ���̵� �޶� ���� 0
	}
}
void Account::create(int id, int money, string name, string password) {	// ���� ����
	nID = id;
	nBalance = money;
	strAccountName = name;
	strPassword = password;

	cout << strAccountName << "�� " << getAcctID() << "�� ���� ��ȣ�� ���������� �����Ǿ����ϴ�. �����մϴ�." << endl;
}
void Account::close() {													// ���� ����
	if (nBalance == 0) {												// ���� 0�϶� ��������
		cout << getAcctID() << " �� ���°� �����Ǿ����ϴ�. �����մϴ�." << endl;
		nID = -1;														// �ʱⰪ���� �ʱ�ȭ
		strAccountName = " ";											// �ʱⰪ���� �ʱ�ȭ
		strPassword = " ";												// �ʱ�ȭ
	}
	else {																// ���� ���������� �����Ұ�
		cout << " ���� ������ �Ұ����մϴ�." << endl;
		cout << " ���� ���¿� " << nBalance << " �� �����ֽ��ϴ�." << endl;
		cout << " ���� ���� ��� ����ϰ� �ٽ� �õ����ּ���. �����մϴ�." << endl;
	}
}
int Account::check(int id, string password) {
	if (authenticate(id, password)) {									// ���� ���̵� ��й�ȣ ���ϴ� �Լ� ���
		return nBalance;												// ���̵� ��й�ȣ�� ������ �ܾ� Ȯ��
	}
	else {
		return AUTHENTIFICATION_FAIL;									// ���̵� ��й�ȣ�� �ٸ��� ���� ���
	}
}

int Account::deposit(int id, string password, int inmoney) {			// �Ա�
	if (authenticate(id, password)) {									// ���̵� ��й�ȣ �� �Լ�
		nBalance += inmoney;											// �ܾ׿� �Աݾ� ���ϱ�
		return nBalance;												// �ܾ� ����
	}
	else {
		return AUTHENTIFICATION_FAIL;									// ���� ����
	}
}

int Account::widraw(int id, string password, int outmoney)				// ���
{
	if (authenticate(id, password))										// ���̵� ��й�ȣ ��
	{
		if (nBalance < outmoney)										// �ܾ׺��� ����Ϸ��� �ݾ��� ���� ��
		{
			cout << " �ܾ��� �����մϴ�. " << endl;
			return -2;													// ���� ���ϱ� ���� ���ϰ� ����
		}
		else															// ����� ������ ��
		{
			nBalance -= outmoney;										// �ܾ׿� ��ݾ� ����
			return nBalance;											// �ܾ� ����
		}
	}
	else
		return AUTHENTIFICATION_FAIL;									// ���� ����
}