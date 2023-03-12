#include<iostream>
#include<string>
#include<random>
using namespace std;

#include "ATMachine.h"
#include "Account.h"

ATMachine::ATMachine(int size, int balance, string password) {
	int nCurrentAccountNum = size;
	int nMachinBalance = balance;
	string strMangetPassword = password;
	pAcctArray = new Account[size];
}

ATMachine::~ATMachine() { delete[] pAcctArray; }

void ATMachine::displayMunu() {									// ȭ�� ��º�
	cout << "---------------------" << endl;
	cout << "--     TUKOREA     --" << endl;
	cout << "---------------------" << endl;
	cout << " 1. ���� ����" << endl;
	cout << " 2. ���� ��ȸ" << endl;
	cout << " 3. ���� �Ա�" << endl;
	cout << " 4. ���� ���" << endl;
	cout << " 6. ���� ����" << endl;
	cout << " 9. ���� ����" << endl;
}

void ATMachine::createAccount() {
	// ���� ����
	random_device rd;											// ��ǻ�Ͱ� �����ϸ鼭 ����ġ�� ���������� ���
	mt19937 gen(rd());											// <random> ���̺�������� �����ϴ� ���� ���� ����
	uniform_int_distribution<int> dis(BASE_ACCOUNT_ID, 1000);	// �յ� ���� ��ü(���ϴ� ���� �ۼ�)
	int id = dis(gen);

	string name;
	string password;

	cout << "-------  ����  -------" << endl;
	cout << " �̸� �Է� : ";
	cin >> name;
	cout << " ��ȣ �Է� : ";
	cin >> password;

	for (int i = 0; i < BASE_ACCOUNT_ID; i++) {
		if (pAcctArray[i].getAcctID() != -1)					// ���� ��ȣ�� �ʱⰪ�� �ƴϸ� �迭�� ����
		{
			(pAcctArray + i)->create(id, 0, name, password);	// create()�Լ� ���·� ����
			break;												// �����ϸ� �ݺ��� Ż��
		}
	}
}

void ATMachine::closeAccount() {								// ���� ����
	int id;
	string password;
	int bol;													// ������ Ȯ���ϱ����� �ۼ�

	cout << "-------  ��ȸ  -------" << endl;
	cout << " ���� ��ȣ �Է� : ";
	cin >> id;
	cout << " ��� ��ȣ �Է� : ";
	cin >> password;

	for (int i = 0; i < BASE_ACCOUNT_ID; i++) {
		bol = (pAcctArray + i)->check(id, password);			// �ݺ��ϸ鼭 �迭�� ���̵� ��й�ȣ ������ �ִ��� Ȯ��
		if (bol != -1) {										// '-1'�� ������ �� ����, -1�� �ƴϸ� ���� ���°� �ִ°�
			(pAcctArray + i)->close();							// ���̵� ��й�ȣ�� ���� ���°� ������ close()�Լ��� ���� ����
			break;												// �ݺ��� Ż��
		}
	}
	if (bol == -1) {											// ���� ���°� ������, ������ �� ���� ��
		cout << " �߸��� ���� ��ȣ Ȥ�� ��� ��ȣ �Դϴ�." << endl;
	}
}

void ATMachine::checkMoney() {									// ���� Ȯ��
	int id;
	string password;
	int money;

	cout << "-------  ��ȸ  -------" << endl;
	cout << " ���� ��ȣ �Է� : ";
	cin >> id;
	cout << " ��� ��ȣ �Է� : ";
	cin >> password;

	for (int i = 0; i < BASE_ACCOUNT_ID; i++) {
		money = (pAcctArray + i)->check(id, password);			// check()�Լ����� ���̵� ��й�ȣ�� ������ nBalance������
		if (money != -1) {										// ���°� �´��� Ȯ�εǸ� �ܾ� ���
			cout << " ���� �ܾ� : " << money << endl;
			break;
		}
	}
	if (money == -1)											// ���°� Ȯ���� �ȵ� ��
		cout << " �߸��� ���� ��ȣ Ȥ�� ��� ��ȣ �Դϴ�." << endl;
}

void ATMachine::depositMoney() {								// �Ա�
	int id;
	string password;
	int inmoney;												// �Աݾ�
	int totalMoney;												// �ܾ�

	cout << "-------  ��ȸ  -------" << endl;
	cout << " ���� ��ȣ �Է� : ";
	cin >> id;
	cout << " ��� ��ȣ �Է� : ";
	cin >> password;
	cout << " �Աݾ�    �Է� : ";
	cin >> inmoney;

	for (int i = 0; i < BASE_ACCOUNT_ID; i++) {
		totalMoney = (pAcctArray + i)->deposit(id, password, inmoney);
		if (totalMoney != -1) {									// ������ �ƴϸ� �ܾ� ���
			cout << " ���� �ܾ� : " << totalMoney << endl;
			break;
		}
	}
	if (totalMoney == -1)										// ����			
		cout << " �߸��� ���� ��ȣ Ȥ�� ��� ��ȣ �Դϴ�." << endl;
}

void ATMachine::widrawMoney() {									// ���
	int id;
	string password;
	int outmoney;												// ��ݾ�
	int totalMoney;												// �ܾ�

	cout << "------ ��� ------" << endl;
	cout << " ���� ��ȣ �Է� : ";
	cin >> id;
	cout << " ��� ��ȣ �Է� : ";
	cin >> password;
	cout << " ��ݾ�    �Է� : ";
	cin >> outmoney;
	for (int i = 0; i < 100; i++)
	{
		totalMoney = (pAcctArray + i)->widraw(id, password, outmoney);
		if (totalMoney != -1 && totalMoney != -2)				// ���°� Ʋ���� �ʰ� �ܾ��� �������� ���� �� ����
		{
			cout << " ���� �ܾ� : " << totalMoney << endl;
			cout << " ��� �Ϸ�" << endl;
			break;
		}
		if (totalMoney == -2) break;							// �ܾ��� ������ ��
	}
	if (totalMoney == -1) {										// ���°� �߸��Ǿ��� ��
		cout << " �߸��� ���� ��ȣ Ȥ�� ��� ��ȣ �Դϴ�." << endl;
	}
}