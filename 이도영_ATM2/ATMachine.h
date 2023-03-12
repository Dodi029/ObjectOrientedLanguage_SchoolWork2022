#ifndef ATMACHINE_H
#define ATMACHINE_H

using namespace std;

#define NEGATIVE_ATM_BALANCE -10							// ATM �ܾ� ����

#include "Account.h"

class ATMachine {
private:
	Account* pAcctArray;									// ���� ������ ������ �迭 ������ // ��ü���� �����ϱ� ���� ������ ����
	int nMachineBalance;									// ATM �ܰ�
	int nMaxAccountNum;										// ���� ������ ������ �迭 ũ��
	int nCurrentAccountNum;									// ������ �� ���� ��
	string strManagerPassword;								// ������ ��й�ȣ

	bool isManager(string password);						// �޴��� ��ȣ Ȯ��
	void displayReport();									// ��� ȭ�� ó��

public:
	ATMachine(int size, int balance, string password);		// ���� �迭ũ��, ATM �ܰ�, ������ ��ȣ �ʱ�ȭ
	~ATMachine();

	void displayMenu();										// ATM ��� ���� ȭ��
	void createAccount();									// ���� ����
	void closeAccount();									// ���� ����
	void checkMoney();										// ���� ��ȸ
	void depositMoney();									// ���� �Ա�
	void widrawMoney();										// ���� ���

	void transfer();										// ���� ��ü
	void managerMode();										// �� ����
};

#endif
