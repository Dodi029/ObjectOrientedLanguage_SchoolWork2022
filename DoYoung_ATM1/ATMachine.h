#ifndef ATMACHINE_H
#define ATMACHINE_H

using std::string;

#define NEGATIVE_ATM_BALANCE -10							// ATM �ܾ� ����
#include "Account.h"

class ATMachine {
private:
	Account* pAcctArray;									// ���� ������ ������ �迭 ������ //��ü���� �����ϱ� ���� ������ ����
	int nMachineBalance;									// ATM �ܰ�
	int nMaxAccountNum;									// ���� ������ ������ �迭 ũ��
	int nCurrentAccountNum;									// ������ �� ���� ��
	string strManagerPassword;								// �����ں�й�ȣ

public:
	ATMachine(int size, int balance, string password);		// ���� �迭ũ��, ATM �ܰ�, ������ ��ȣ �ʱ�ȭ
	~ATMachine();

	void displayMunu();										// ATM ��� ���� ȭ��
	void createAccount();									// ���� ����
	void closeAccount();									// ���� ����
	void checkMoney();										// ���� ��ȸ
	void depositMoney();									// ���� �Ա�	
	void widrawMoney();										// ���� ���
	void transfer();										// ���� ��ü
};
#endif