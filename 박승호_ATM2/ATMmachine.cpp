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
	cout << "1. ���� ����\n" << "2. ���� ��ȸ\n" << "3. ���� �Ա�\n"<<"4. ���� ���\n"<<"5. ������ü\n"
		<< "6. ���� ����\n"<<"7. ������\n" << "9. ���� ����\n";
}

void ATMachine::createAccount() {
	cout << " ------ ���� ------ \n";
	cout << "�̸� �Է� : ";
	getline(cin, name);
	cout << "��й�ȣ �Է� : ";
	cin >> password;
	int id = BASE_ACCOUNT_ID + nCurrentAccountNum;
	pAcctArray[nCurrentAccountNum].create(id, 0, name, password);
	nCurrentAccountNum++;
}

void ATMachine::checkMoney() {
	
	cout << " ------ ��ȸ ------ \n";
	cout << "���¹�ȣ �Է� : ";
	cin >> id;
	cout << "��й�ȣ �Է� : ";
	cin >> password;
	for (int i = 0; i < nCurrentAccountNum; i++)
	{
		if (pAcctArray[i].getAcctID() == id) {
			index = pAcctArray[i].check(id, password);
			if (index == -1) {
				cout << "\n���¹�ȣ�� ��й�ȣ�� �ùٸ��� �ʽ��ϴ�." << endl;
				break;
			}
			else {
				cout << "\n���� �ܾ��� " << index << "�� �Դϴ�." << endl;
				break;
			}
		}
		else if (i == nCurrentAccountNum - 1)
			cout << "\n�������� �ʴ� ���¹�ȣ�Դϴ�." << endl;
	}
}
void ATMachine::closeAccount() {
	cout << " ------ ��ȸ ------ \n";
	cout << "���¹�ȣ �Է� : ";
	cin >> id;
	cout << "��й�ȣ �Է� : ";
	cin >> password;
	for (int i = 0; i < nCurrentAccountNum; i++)
	{
		if (pAcctArray[i].getAcctID() == id) {
			index = pAcctArray[i].check(id, password);
			if (index == -1) {
				cout << "\n���¹�ȣ�� ��й�ȣ�� �ùٸ��� �ʽ��ϴ�." << endl;
				break;
			}
			else if (index == 0) {
				cout << id << "���°� �����Ǿ����ϴ�." << endl;
				pAcctArray[i].close();
				break;
			}
			else {
				cout << id << "���¿� �ܾ��� �����ֽ��ϴ�." << endl;
				break;
			}
		}
		else if (i == nCurrentAccountNum - 1)
			cout << "\n�������� �ʴ� ���¹�ȣ�Դϴ�." << endl;
	}
}
void ATMachine::depositMoney() {
	cout << " ------ �Ա� ------ \n";
	cout << "���¹�ȣ �Է� : ";
	cin >> id;
	cout << "��й�ȣ �Է� : ";
	cin >> password;
	cout << "�Աݾ� �Է� : ";
	cin >> money;
	for (int i = 0; i < nCurrentAccountNum; i++)
	{
		if (pAcctArray[i].getAcctID() == id) {
			index = pAcctArray[i].deposit(id, password, money);
			if (index == -1) {
				cout << "\n���¹�ȣ�� ��й�ȣ�� �ùٸ��� �ʽ��ϴ�." << endl;
				break;
			}
			else {
				cout << "\n���� �ܾ� : " << index  << endl;
				cout << "�Ա� �Ϸ�" << endl;
				break;
			}
		}
		else if (i == nCurrentAccountNum - 1)
			cout << "\n�������� �ʴ� ���¹�ȣ�Դϴ�." << endl;
	}
}
void ATMachine::widrawMoney() {
	cout << " ------ ��� ------ \n";
	cout << "���¹�ȣ �Է� : ";
	cin >> id;
	cout << "��й�ȣ �Է� : ";
	cin >> password;
	cout << "��ݾ� �Է� : ";
	cin >> money;
	for (int i = 0; i < nCurrentAccountNum; i++)
	{
		if (pAcctArray[i].getAcctID() == id) {
			index = pAcctArray[i].widraw(id, password, money);
			if (index == -1) {
				cout << "\n���¹�ȣ�� ��й�ȣ�� �ùٸ��� �ʽ��ϴ�." << endl;
				break;
			}
			else if (index < 0) {
				cout << "���¿� �ܾ��� �����մϴ�.\n" << endl;
			}
			else {
				cout << "\n���� �ܾ� : " << index << endl;
				cout << "��� �Ϸ�" << endl;
				break;
			}
		}
		else if (i == nCurrentAccountNum - 1)
			cout << "\n�������� �ʴ� ���¹�ȣ�Դϴ�." << endl;
	}
}
void ATMachine::transfer() {
	cout << " ------ ��ü ------ \n";
	cout << "���¹�ȣ �Է� : ";
	cin >> id1;
	cout << "��й�ȣ �Է� : ";
	cin >> password;
	for (int i = 0; i < nCurrentAccountNum; i++) {
		if (pAcctArray[i].getAcctID() == id1)
			store = i;		//�Է��� ���� ����
	}
	cout << "��ü���� �Է� : ";
	cin >> id2;
	cout << "��ü�ݾ� �Է� : ";
	cin >> money;
	for (int i = 0; i < nCurrentAccountNum; i++)
	{
		if (pAcctArray[i].getAcctID() == id2) {
			index = pAcctArray[store].widraw(id1, password, money);
			if (index == -1) {
				cout << "\n���¹�ȣ�� ��й�ȣ�� �ùٸ��� �ʽ��ϴ�." << endl;
				return;
			}
			else if (index == 1) {
				cout << "\n���¿� ���� ������� �ʽ��ϴ�." << endl;
				return;
			}
			else {
				cout << "\n���� �ܾ��� " << index << "�� �Դϴ�." << endl;
				index = pAcctArray[i].deposit(id2 ,money);
				cout << "��ü �Ϸ�" << endl;
				break;
			}
		}
		else if (i == nCurrentAccountNum - 1) {
			cout << "\n�������� �ʴ� ���¹�ȣ�Դϴ�.\n" << endl;
			return;
		}
	}
}
bool ATMachine::isManager(string password) {
	return (strManagerPassword == password);
}
void ATMachine::displayReport() {
	cout << " \n------ ���� ------ " << endl;
	cout << "������ ��й�ȣ �Է� : ";
	cin >> password;
	if (isManager(password)) {
		cout << "\n�������Դϴ�.\n" << endl;
		cout << "---------------------\n"<<endl;
		cout << "ATM ���� �ܰ� : " << nMachineBalance + s.sum(pAcctArray, nCurrentAccountNum) << endl;
		cout << "�� �ܰ� �Ѿ� : " << s.sum(pAcctArray, nCurrentAccountNum) << "(�� " << nCurrentAccountNum << "��)" << endl;
		cout << "�� �ܰ� ��� : " << a.average(pAcctArray, nCurrentAccountNum) << endl;
		cout << "�� �ܰ� �ְ� : " << m.max(pAcctArray, nCurrentAccountNum) << endl;
		cout << "---------------------\n" << endl;
		cout << "\n-- �� ���� ��� -- " << endl;
		cout << "---------------------- " << endl;
		so.sort(pAcctArray, nCurrentAccountNum);
	}
	else
		cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
}
void ATMachine::managerMode() {
	displayReport();
}
ATMachine::~ATMachine() {
	delete[] pAcctArray;
}