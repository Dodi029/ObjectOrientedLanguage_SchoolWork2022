#include <iostream>
#include <string>
#include <random>

using namespace std;

#include "ATMachine.h"
#include "Statistics.h"

ATMachine::ATMachine(int size, int balance, string password) {
	nCurrentAccountNum = 0;
	nMaxAccountNum = size;
	nMachineBalance = balance;
	strManagerPassword = password;
	pAcctArray = new Account[size];
}

ATMachine ::~ATMachine() { delete[]pAcctArray; }

void ATMachine :: displayMenu() {									// ȭ�� ��º�
	cout << "-------------------------" << endl;
	cout << "-     TUKOREA BANK     -" << endl;
	cout << "-------------------------" << endl;
	cout << " 1. ���� ����" << endl;
	cout << " 2. ���� ��ȸ" << endl;
	cout << " 3. ���� �Ա�" << endl;
	cout << " 4. ���� ���" << endl;
	cout << " 5. ���� ��ü" << endl;
	cout << " 6. ���� ����" << endl;
	cout << " 7. �� ����" << endl;
	cout << " 9. ���� ����" << endl;
}

void ATMachine::createAccount() {									// ���� ����
	random_device rd;												// ��ǻ�Ͱ� �����ϸ鼭 ����ġ�� ���������� ���
	mt19937 gen(rd());												// <random> ���̺귯������ �����ϴ� ���� ���� ����
	uniform_int_distribution<int> dis(BASE_ACCOUNT_ID, 1000);		// �յ� ��ȣ ��ü (���ϴ� ���� �ۼ�)
	int id = dis(gen);												// ������ ������ ������ id�� ����

	string name;
	string password;
	
	cout << "------  ���� ------" << endl;
	cout << " �̸� �Է� : ";
	cin >> name;
	cout << " ��ȣ �Է� : ";
	cin >> password;

	for (int i = 0; i < nMaxAccountNum; i++) {
		if (pAcctArray[i].getAcctID() == -1) {						// �迭�� �ʱⰪ���� ����Ǿ� ������ �װ��� ���¹�ȣ ����
			(pAcctArray + i)->create(id, 0, name, password);		// create()�Լ� ���·� ����
			nCurrentAccountNum++;									// ���� �����ϴ� ���� ���� ����
			break;													// �迭�� �����ϸ� �ݺ��� Ż��
		}
	}
}

void ATMachine::closeAccount() {									// ���� ����
	int id;
	string password;
	int bol;														// ������ Ȯ���ϱ� ���� ����
	int i, j;														// �ݺ��� Ƚ���� �����ϱ� ���� ����

	cout << "------ ��ȸ ------" << endl;
	cout << " ���¹�ȣ �Է�: ";
	cin >> id;
	cout << " ��й�ȣ �Է�: ";
	cin >> password;
	
	for (i = 0; i < nMaxAccountNum; i++) {
		bol = (pAcctArray + i)->check(id, password);				// �ݺ��ϸ鼭 �迭�� ���̵� ��й�ȣ ������ �ִ��� Ȯ��
		if (bol != -1) {											// '-1'�� ������ �� ����, -1�� �ƴϸ� ���� ���°� �ִ°�
			(pAcctArray + i)->close();								// ���̵� ��й�ȣ�� ���� ���°� ������ close()�Լ��� ���� ����
			nCurrentAccountNum--;									// ���� �����ϴ� ���� ���� ����
			j = i;
			break;													// �迭���� �ش��ϴ� ���¸� ã���� �ݺ��� Ż��
		}
	}
	if (bol == -1) {
		cout << " �߸��� ���� ��ȣ �Դϴ�." << endl;
	}
	else {
		for (int i =j; i < nMaxAccountNum - 1; i++) {				// ���¸� ���������� �������� ��
			int k = i + 1;											// �迭�� ����� ���µ� ��ġ�� ���
			*(pAcctArray + i) = *(pAcctArray + k);
		}
	}
}

void ATMachine::checkMoney() {										// ���� ��ȸ
	int id;
	string password;
	int money;           

	cout << "------ ��ȸ ------" << endl;
	cout << " ���� ��ȣ �Է�: ";
	cin >> id;
	cout << " ��� ��ȣ �Է�: ";
	cin >> password;

	for (int i = 0; i < nMaxAccountNum; i++) {
		money = (pAcctArray+i)->check(id, password);				// check()�Լ����� ���̵� ��й�ȣ�� ������ nBalacne ������
		if (money != -1) {											// ���°� �´��� Ȯ�εǸ� �ܾ� ���
			cout << "���� �ܾ� : " << money << endl;
			break;
		}
	}
	if (money == -1) {												// ���� Ȯ�ο� �������� ��
		cout << " �߸��� ���� ��ȣ �Դϴ�." << endl;
	}
}

void ATMachine::depositMoney() {									// �Ա�
	int id;
	string password;
	int inmoney;													// �Աݾ�
	int totalMoney;													// �ܾ�

	cout << "------ �Ա� ------" << endl;
	cout << " ���� ��ȣ �Է� : ";
	cin >> id;
	cout << " ��� ��ȣ �Է� : ";
	cin >> password;
	cout << " �Աݾ�    �Է� : ";
	cin >> inmoney;

	for (int i = 0; i < nMaxAccountNum; i++) {
			totalMoney = (pAcctArray + i)->deposit(id, password, inmoney);	// ���̵�, ��й�ȣ�� ������ deposit() �Լ� ����

		if (totalMoney != -1) {										// ������ �ƴ� ��
			nMachineBalance += inmoney;								// ATM �� �ܾ� ����
			cout << " ���� �ܾ� : " << totalMoney << endl;
			cout << " �Ա� �Ϸ�" << endl;
			break;
		}
	}
	if (totalMoney == -1)											// ������ ���
		cout << " �߸��� ���� ��ȣ �Դϴ�." << endl;
}

void ATMachine::widrawMoney() {										// ���
	int id;
	string password;
	int outmoney;
	int totalMoney;

	cout << "------ ��� ------" << endl;
	cout << " ���� ��ȣ �Է� : ";
	cin >> id;
	cout << " ��� ��ȣ �Է� : ";
	cin >> password;
	cout << " ��ݾ�    �Է� : ";
	cin >> outmoney;

	for (int i = 0; i < nMaxAccountNum; i++) {
		totalMoney = (pAcctArray + i)->widraw(id, password, outmoney);		// ���̵� ��й�ȣ�� ������ widraw() �Լ� ����
		if (totalMoney != -1) {												// �ܾ��� �������� ���� ��
			if (totalMoney == -2) break;									// ������ ��� �ݺ��� ����
			else {
				if (nMachineBalance >= outmoney) {							// ATM �� �ܾ��� ��ݾ׺��� ���� ��
					nMachineBalance -= outmoney;							// ATM �� �ܾ׿��� ��ݾ��� ��
					cout << " ���� �ܾ� : " << totalMoney << endl;			// ���
					cout << " ��� �Ϸ�" << endl;
					break;
				}
				else {
					cout << " �ܾ��� �����մϴ�." << endl;					// �ƴ� ���
					break;
				}
			}
		}
		
	}
	if (totalMoney == -1) {													// ���°� �߸��Ǿ��� ��
		cout << " �߸��� ���� ��ȣ �Դϴ�." << endl;
	}
}

void ATMachine::transfer() {												// ���� ��ü
	int id;																	// ��ü�� ����
	int to_id;																// ��ü���� ����
	string password;														// ��ü�� ������ ��й�ȣ
	int money;																// ��ü�� ��
	int inmoney = 0;														// ��ü���� ������ ���� ��
	int outmoney = 0;														// ��ü�� ������ ���� ��

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
	for (int i = 0; i < nCurrentAccountNum; i++) {
		outmoney = (pAcctArray + i)->check(id, password);					// ��ü�� ������ ���̵� ��й�ȣ Ȯ��
		if (outmoney != -1) {												// ��ü�� ������ ���̵� �����Ѵٸ�
			for (int j = 0; j < nCurrentAccountNum; j++) {
				if ((pAcctArray + i)->getBalance() >= money) {				// ����Ϸ��� �ݾ��� �ܾ׺��� ����� ��
					inmoney = (pAcctArray + j)->deposit(to_id, money);		// ��ü�ϴ� �Լ� ����
					if (inmoney != -1) {									// ��ü ���� ���°� �����Ѵٸ�
						outmoney = (pAcctArray + i)->widraw(to_id, password, money);	// �� ���·� ���

						if (outmoney == -2) break;							// ��ü�� ���°� ������ �ݺ��� Ż��

						cout << " ���� �ܾ� : " << outmoney << endl;			// ��ü�� ������ ���� �� ���
						cout << " ��ü �Ϸ�" << endl;
						break;
					}
				}
				else {
					cout << " �ܾ��� �����մϴ�." << endl;					// ����Ϸ��� �ݾ��� �ܾ׺��� ���� ���
					break;
				}
			}
			if (inmoney == -1) {											// ��ü���� ���¹�ȣ�� Ʋ���� ��
				cout << " ��ü���� ���¸� ã�� �� �����ϴ�." << endl;	
				break;
			}
			break;
		}
	}
	if (outmoney == -1)														// ��ü�� ���¹�ȣ�� Ʋ���� ��
		cout << " �߸��� ���� ��ȣ �Դϴ�." << endl;
}

bool  ATMachine::isManager(string password) {
	if (strManagerPassword.compare(password) == 0)							// ������ ��ȣ�� ���� ��
		return true;														// true(1) ����
	else																	// ������ ��ȣ�� Ʋ�� ��
		return false;														// false(0) ����
}

void  ATMachine::displayReport() {											// ��� ȭ�� ���
	int sumMoney;
	int avg;
	int max;

	sumMoney = Statistics::sum(pAcctArray, nCurrentAccountNum);				// Ŭ���� ���ϰ� ����
	avg = Statistics::average(pAcctArray, nCurrentAccountNum);				// Ŭ���� ���ϰ� ����
	max = Statistics::max(pAcctArray, nCurrentAccountNum);					// Ŭ���� ���ϰ� ����

	cout << " ATM  ���� �ܰ� :      " << nMachineBalance <<"��" << endl;
	cout << " �� �ܰ� �Ѿ� :      " << sumMoney << "��" << "(" << "��" << nCurrentAccountNum << "��" << ")" << endl;
	cout << " �� �ܰ� ��� :      " << avg << "��" << endl;
	cout << " �� �ܰ� �ְ� :      " << max << "��" << endl;
	cout << "------------------------" << endl;
	cout << "-   �� ���� ���   -" << endl;
	cout << "------------------------" << endl;

	Statistics::sort(pAcctArray, nCurrentAccountNum);						// �������� ����

}

void  ATMachine::managerMode() {											// ������ ���
	string password;

	cout << "-------- ���� --------" << endl;
	cout << " ������ ��й�ȣ �Է� : ";
	cin >> password;

	if (isManager(password)) {												// �Է��� ��й�ȣ�� �´��� Ȯ��
		cout << " �������Դϴ�." << endl;
		cout << "---------------------" << endl;
		displayReport();

	}
	else {
		cout << endl;
		cout << "������ ��й�ȣ�� �ٸ��ϴ�." << endl;
	}
}