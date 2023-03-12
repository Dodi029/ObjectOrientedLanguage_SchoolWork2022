#include <iostream>
#include <string>

using namespace std;

#include "Account.h"
#include "ATMachine.h"

Account::Account() {
	nID = -1;															// �ʱⰪ ����
	nBalance = 0;
}

inline bool Account::authenticate(int id, string passwd) {				// ���� �� (����:true=1, ����:false=0)
	if (getAcctID() == id) {											// ���̵� ������ Ȯ��
		if (strPassword.compare(passwd) == 0)							// ��й�ȣ�� ������ Ȯ��
			return true;												// �Ѵ� ������ ����(true ����)
		else {
			cout << endl << " �߸��� ��� ��ȣ�Դϴ�." << endl;			// ��� ��ȣ�� �ٸ��� ���� (false ����)
			return false;
		}
	}
	else
		return false;													// ���̵� �޶� ���� (false ����)
}

void Account::create(int id, int money, string name, string password) { // ���� ����
	nBalance = money;													// �Է¹��� �� ����
	strAccountName = name;												// �Է¹��� �̸� ����
	strPassword = password;												// �Է¹��� ��й�ȣ ����
	nID = id;															// �Է¹��� ���� ��ȣ ����
	cout << strAccountName << "�� " << getAcctID() << "�� ���� ��ȣ�� ���������� �����Ǿ����ϴ�. �����մϴ�." << endl;
}

void Account::close() {													// ���� ����
	if (nBalance == 0) {												// �ܰ� 0�� ���� ���� ����
		cout << getAcctID() << " �� ���°� �����Ǿ����ϴ�. �����մϴ�." << endl;
		nID = -1;														// ���� ��ȣ �ʱⰪ���� �ʱ�ȭ
		strAccountName = " ";											// �� �̸� �ʱ�ȭ
		strPassword = " ";												// ��� ��ȣ �ʱ�ȭ
	}

	else {
		cout << " ���� ������ �Ұ����մϴ�." << endl;
		cout << " ���� ���¿� " << nBalance << " �� �����ֽ��ϴ�." << endl;
		cout << " ���� ���� ��� ����ϰ� �ٽ� �õ����ּ���. �����մϴ�." << endl;
	}

}

int Account::check(int id, string password) {							// ���� Ȯ��
	if (authenticate(id, password)) {									// ���� ���̵� ��й�ȣ ���ϴ� �Լ� ���
		return nBalance;												// ���̵� ��й�ȣ�� ������ �ܾ� Ȯ��
	}
	else
		return AUTHENTIFICATION_FAIL;									// ���̵� ��й�ȣ�� �ٸ��� ���� ���
}

int Account::deposit(int id, string password, int inmoney) {			// �Ա�
	if (authenticate(id, password)) {									// ���̵� ��й�ȣ �� �Լ�
		nBalance += inmoney;											// �ܾ׿� �Աݾ� ���ϱ�
		return nBalance;												// �ܾ� ����
	}
	else
		return AUTHENTIFICATION_FAIL;									// ���̵� ��й�ȣ�� �ٸ��� ���� ���
}

int Account::widraw(int id, string password, int outmoney) {			// ���
	if (authenticate(id, password)) {									// ���̵� ��й�ȣ ��
		if (nBalance > outmoney) {										// �ܾ��� ����Ϸ��� �ݾ׺��� ���� ��
			nBalance -= outmoney;										// �ܾ׿� ��ݾ� ����
			return nBalance;											// �ܾ� ����
		}
		else {															// �ܾ��� ����Ϸ��� �ݾ׺��� ���� ��
			cout << " �ܾ��� �����մϴ�." << endl;
			return -2;													// ���� ���ϱ� ���� ���ϰ� ����
		}
	}
	else
		return AUTHENTIFICATION_FAIL;									// ���̵� ��й�ȣ�� �ٸ��� ���� ���
}

int Account::deposit(int id, int money) {								// ���� ��ü
	if (getAcctID() == id) {											// ���� �����ϴ� ������ id�� ��
		nBalance += money;												// id�� �����ϸ� �� ������ �ܾ� ����
		return nBalance;												// �ܾ� ����
	}
	else
		return AUTHENTIFICATION_FAIL;									// �Է��� id�� �������� ������ ���� ����
}