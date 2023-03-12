#include<iostream>
#include<string>
#include<random>
using namespace std;

#include "ATMachine.h"
#include "Account.h"

ATMachine::ATMachine(int size, int balance, string password) {
	nCurrentAccountNum = 0;
	nMaxAccountNum = size;
	nMachineBalance = balance;
	strManagerPassword = password;
	pAcctArray = new Account[size];
}

void ATMachine::displayMunu() {									// ȭ�� ��º�
	cout << "---------------------" << endl;
	cout << "--     TUKOREA     --" << endl;
	cout << "---------------------" << endl;
	cout << " 1. ���� ����" << endl;
	cout << " 2. ���� ��ȸ" << endl;
	cout << " 3. ���� �Ա�" << endl;
	cout << " 4. ���� ���" << endl;
	cout << " 5. ���� ��ü" << endl;
	cout << " 6. ���� ����" << endl;
	cout << " 9. ���� ����" << endl;
}

void ATMachine::createAccount() {
	random_device rd;											// ��ǻ�Ͱ� �����ϸ鼭 ����ġ�� ���������� ���
	mt19937 gen(rd());											// <random> ���̺�������� �����ϴ� ���� ���� ����
	uniform_int_distribution<int> dis(BASE_ACCOUNT_ID, 1000);	// �յ� ���� ��ü(���ϴ� ���� �ۼ�)
	int id = dis(gen);											// ������ ������ id�� ����

	string name;
	string password;

	cout << "-------  ����  -------" << endl;
	cout << " �̸� �Է� : ";
	cin >> name;
	cout << " ��ȣ �Է� : ";
	cin >> password;

	for (int i = 0; i < nMaxAccountNum; i++) {
		if (pAcctArray[i].getAcctID() == -1) {					// ���� ��ȣ�� �ʱⰪ�� �ƴϸ� �迭�� ����
			(pAcctArray + i)->create(id, 0, name, password);	// create()�Լ� ���·� ����
			nCurrentAccountNum++;								// ���� �����ϴ� ���� ���� ����
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

	for (int i = 0; i < nMaxAccountNum; i++) {
		bol = (pAcctArray + i)->check(id, password);			// �ݺ��ϸ鼭 �迭�� ���̵� ��й�ȣ ������ �ִ��� Ȯ��
		if (bol != -1) {										// '-1'�� ������ �� ����, -1�� �ƴϸ� ���� ���°� �ִ°�
			(pAcctArray + i)->close();							// ���̵� ��й�ȣ�� ���� ���°� ������ close()�Լ��� ���� ����
			for (int i = 0; i < nMaxAccountNum; i++) {
				if ((pAcctArray + i)->getAcctID() != -1) {
					nCurrentAccountNum++;
				}
				break;
			}
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

	for (int i = 0; i < nMaxAccountNum; i++) {
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

	cout << "-------  �Ա�  -------" << endl;
	cout << " ���� ��ȣ �Է� : ";
	cin >> id;
	cout << " ��� ��ȣ �Է� : ";
	cin >> password;
	cout << " �Աݾ�    �Է� : ";
	cin >> inmoney;

	for (int i = 0; i < nMaxAccountNum; i++) {
		totalMoney = (pAcctArray + i)->deposit(id, password, inmoney);
		if (totalMoney != -1) {									// ������ �ƴϸ� �ܾ� ���
			nMachineBalance += inmoney;							// ATM����� �� �ܾ� ����
			cout << " ���� �ܾ� : " << totalMoney << endl;
			cout << " �Ա� �Ϸ�" << endl;
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

	for (int i = 0; i < nMaxAccountNum; i++) {
		totalMoney = (pAcctArray + i)->widraw(id, password, outmoney);
		if (totalMoney != -1 ) {				// ���°� Ʋ���� �ʰ� �ܾ��� �������� ���� �� ����
			if (totalMoney != -2) {
				if (nMachineBalance >= outmoney) {
					nMachineBalance -= outmoney;
					cout << " ���� �ܾ� : " << totalMoney << endl;
					cout << " ��� �Ϸ�" << endl;
					break;
				}
				else {
					cout << " ����� �� �����ϴ�." << endl;
				}
			}
			else
				break;
		}
		if (totalMoney == -2) break;							// �ܾ��� ������ ��
	}
	if (totalMoney == -1) {										// ���°� �߸��Ǿ��� ��
		cout << " �߸��� ���� ��ȣ Ȥ�� ��� ��ȣ �Դϴ�." << endl;
	}
}

void ATMachine::transfer() {									// ���� ��ü
	int id;														// ��ü�� ���¹�ȣ
	string password;											// ��ü�� ������ ��й�ȣ
	int to_id;													// ��ü���� ���¹�ȣ
	int money;													// ��ü�� ��
	// int totalMoney;												// ��ü�ϰ� ���� ��
	int inmoney;												// ��ü���� ������ ���� ��
	int outmoney;												// ��ü�� ������ ���� ��

	cout << "------ ��ü ------" << endl;
	cout << " ���� ��ȣ �Է� : ";
	cin >> id;
	cout << " ��� ��ȣ �Է� : ";
	cin >> password;
	cout << " ��ü ���� �Է� : ";
	cin >> to_id;
	cout << " ��ü �ݾ� �Է� : ";
	cin >> money;

	//for (int i = 0; i < BASE_ACCOUNT_ID; i++) {
	//	outmoney = (pAcctArray + i)->deposit(to_id, money);
	//	if (outmoney != -1) {									// ������ �ƴϸ� �ܾ� ���
	//		
	//		for (int j = 0; j < BASE_ACCOUNT_ID; j++)
	//		{
	//			inmoney = (pAcctArray + j)->widraw(id, password, money);
	//			if (inmoney != -1 )	{
	//				if (outmoney == -2)break;
	//				cout << " ���� �ܾ� : " << inmoney << endl;
	//				cout << " ��ü �Ϸ�" << endl;
	//				break;
	//			}
	//			if (inmoney == -1) {
	//				cout << " ���¸� ã�� �� �����ϴ�." << endl;
	//				break;
	//			}
	//			break;
	//		}
	//		if (inmoney==-1&&outmoney==-1) {										// ���°� �߸��Ǿ��� ��
	//			cout << " �߸��� ���� ��ȣ Ȥ�� ��� ��ȣ �Դϴ�." << endl;
	//		}
	//		if (outmoney == -1) {
	//			cout << " ��ü�� ���°� �߸��Ǿ����ϴ�." << endl;
	//		}
	//	}
	//}
	for (int i = 0; i < nMaxAccountNum; i++)
	{
		outmoney = (pAcctArray + i)->deposit(to_id, money);
		if (outmoney != -1)
		{
			for (int k = 0; k < nMaxAccountNum; k++)
			{
				inmoney = (pAcctArray + k)->widraw(id, password, money);
				if (inmoney != -1)
				{
					if (inmoney == -2) break;
					cout << " ���� �ܾ� : " << inmoney << endl;
					cout << " ��ü �Ϸ�" << endl << endl;
					break;
				}
				break;
			}
			if (inmoney == -1)
			{
				cout << " ���¸� ã�� �� �����ϴ�." << endl << endl;
				break;
			}
			break;
		}
	}
	if (inmoney == -1 && outmoney == -1)
		cout << " ���¸� ã�� �� �����ϴ�." << endl;
	if (outmoney == -1)
		cout << " ��ü���¸� ã�� �� �����ϴ�." << endl << endl;
}

ATMachine::~ATMachine() { delete[] pAcctArray; }								// �迭 �Ҹ���