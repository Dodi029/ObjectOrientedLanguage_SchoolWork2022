#pragma once
#include <iostream>
#include "Account.h"

#ifndef ATMACHINE_H
#define ATMACHINE_H
using std::string;
#define NEGATIVE_ATM_BALANCE -10 // ATM �ܾ� ����
class ATMachine {
private:
	Account* pAcctArray; // ���� ������ ������ �迭 ������
	int nMachineBalance; // ATM �ܰ�
	int nMaxAccountNum; // ���� ������ ������ �迭 ũ��
	int nCurrentAccountNum; // ������ �� ���� ��
	string strManagerPassword; // ������ ��й�ȣ
	bool isManager(string password);
	void displayReport();
public:
	ATMachine(int size, int balance, string password); // ���� �迭ũ��, ATM �ܰ�, ������ ��ȣ �ʱ�ȭ
	~ATMachine();
	void displayMenu(); // ATM ��� ���� ȭ��
	void createAccount(); // ���� ����
	void closeAccount(); // ���� ����
	void checkMoney(); // ���� ��ȸ
	void despositMoeny();
	void widrawMoney();
	void transfer();
	void managerMode();
};
#endif