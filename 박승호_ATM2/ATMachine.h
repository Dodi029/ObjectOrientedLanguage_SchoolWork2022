#pragma once
#include <iostream>
#include <string>

#ifndef ATMACHINE_H
#define ATMACHINE_H


#include "ATMachine.h"
#include "Account.h"
#include "Statistics.h"

using std::string;

#define NEGATIVE_ATM_BALANCE -10	// ATM �ܰ� ������

class ATMachine {
private:
	Account* pAcctArray;	// �������� ������ �迭 ������
	int nMachineBalance;	// ATM�ܰ�
	int nMaxAccountNum;		// �������� ������ �迭 ũ��
	int nCurrentAccountNum = 0;	// ������ �� ���� ��
	string strManagerPassword;	// ������ ��й�ȣ

	string name, password;
	int id, id1, id2;
	int index, money,store;

	Statistics s, a, m,so;

	bool isManager(string password);
	void displayReport();

public:
	ATMachine(int size, int balance, string password);
	// (���� �迭ũ��, ATM �ܰ�, ������ ��ȣ �ʱ�ȭ)
	~ATMachine();

	int getnCurrentAccountNum() { return nCurrentAccountNum; }
	void displayMenu();	// ATM �޴� ���
	void createAccount();	// ���� ����
	void checkMoney();		// ���� ��ȸ
	void closeAccount(); // ���� �Ա�
	void depositMoney();
	void widrawMoney();
	void transfer();		// ���� ��ü
	void managerMode();		// �� ����
};

#endif