#include <iostream>
#include <string>
#include <random>

using namespace std;

#include "ATMachine.h"

int bol;        // �� ����Ȯ��
//int id;              //���¹�ȣ
//string password;     //��й�ȣ

ATMachine::ATMachine(int size, int balance, string password)
{
	nCurrentAccountNum = size;
	nMachineBalance = balance;
	strManagerPassword = password;
	pAcctArray = new Account[size];
}

ATMachine ::~ATMachine() { delete[]pAcctArray; }

void ATMachine :: displayMenu()
{
	cout << "-------------------------" << endl;
	cout << "-     TUKOREA BANK     -" << endl;
	cout << "-------------------------" << endl;
	cout << "1. ���� ����" << endl;
	cout << "2. ���� ��ȸ" << endl;
	cout << "3. ���� �Ա�" << endl;
	cout << "4. ���� ���" << endl;
	cout << "6. ���� ����" << endl;
	cout << "9. ���� ����" << endl;
}

void ATMachine::createAccount()
{
	random_device rd;                                //������ �õ尪�������
	mt19937 gen(rd());                               //���� ���� ���� ��ü����
	uniform_int_distribution<int> dis(BASE_ACCOUNT_ID, 1000);    //���� ���� ����
	int id = dis(gen);
	string name;
	string password;
	
	cout << "------  ���� ------" << endl;
	cout << "�̸� �Է�: ";
	cin >> name;
	cout << "��ȣ �Է�: ";
	cin >> password;
	//pAcctArray �迭 for�� ������ id�� -1�� ���� ã�Ƽ� �ű�� �Ҵ�
	for (int i = 0; i < BASE_ACCOUNT_ID; i++) {
		if (pAcctArray[i].getAcctID() == -1)
		{
			(pAcctArray + i)->create(id, 0, name, password);
			break;
		}
	}
}

void ATMachine::checkMoney()
{
	int id;              //���¹�ȣ
	string password;     //��й�ȣ
	int money;           //���� �ܾ� �Ǵ� ��������
	cout << "------ ��ȸ ------" << endl;
	cout << "���¹�ȣ �Է�: ";
	cin >> id;
	cout << "��й�ȣ �Է�: ";
	cin >> password;
	for (int i = 0; i < BASE_ACCOUNT_ID; i++)
	{
		money = (pAcctArray+i)->check(id, password);
		if (money != -1)
		{
			cout << "���� �ܾ� : " << money << endl << endl;
			break;
		}
	}
	if (money == -1)
		cout << "���¸� ã�� �� �����ϴ�." << endl << endl;
}
void ATMachine::closeAccount() // ���� ����
{
	int id;              //���¹�ȣ
	string password;     //��й�ȣ
	cout << "------ ��ȸ ------" << endl;
	cout << "���¹�ȣ �Է�: ";
	cin >> id;
	cout << "��й�ȣ �Է�: ";
	cin >> password;
	for (int i = 0; i < 100; i++)
	{
		bol = (pAcctArray + i)->check(id, password);
		if (bol != -1)
		{
			(pAcctArray + i)->close();
			break;
		}	
	}
	if(bol == -1)
		cout << "���¸� ã�� �� �����ϴ�." << endl << endl;
}
void ATMachine::depositMoney()  // ���� �Ա�
{
	int id;              // ���¹�ȣ
	int money;           // �Ա��� �ݾ�
	string password;     // ��й�ȣ
	int sumMoney;        // ���� �ܾ� �Ǵ� ��������

	cout << "------ �Ա� ------" << endl;
	cout << "���¹�ȣ �Է�: ";
	cin >> id;
	cout << "��й�ȣ �Է�: ";
	cin >> password;
	cout << "�Աݾ� �Է� : ";
	cin >> money;
	for (int i = 0; i < 100; i++)
	{
			sumMoney = (pAcctArray + i)->deposit(id, password, money);
		if (sumMoney != -1)
		{
			cout << "���� �ܾ� : " << sumMoney << endl;
			cout << "�Ա� �Ϸ�" << endl << endl;
			break;
		}
	}
	if(sumMoney == -1)
		cout << "���¸� ã�� �� �����ϴ�." << endl << endl;
}

void ATMachine::widrawMoney() // ���� ���
{
	int id;              // ���¹�ȣ
	int money;           // �Ա��� �ݾ�
	string password;     // ��й�ȣ
	int sumMoney;        // ���� �ܾ� �Ǵ� ��������

	cout << "------ ��� ------" << endl;
	cout << "���¹�ȣ �Է�: ";
	cin >> id;
	cout << "��й�ȣ �Է�: ";
	cin >> password;
	cout << "��ݾ� �Է� : ";
	cin >> money;
	for (int i = 0; i < 100; i++)
	{
		sumMoney = (pAcctArray + i)->widraw(id, password, money);
		if (sumMoney != -1 && sumMoney!=-2)
		{
			cout << "���� �ܾ� : " << sumMoney << endl;
				cout << "��� �Ϸ�" << endl << endl;
				break;
		}
		if (sumMoney == -2) break;
	}
	if (sumMoney == -1) {
		cout << "���¸� ã�� �� �����ϴ�." << endl << endl;
	}
}