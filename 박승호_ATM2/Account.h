#pragma once
#include <iostream>
#include <string>

#ifndef ACCOUNT_H
#define ACCOUNT_H


#include "ATMachine.h"
#include "Account.h"
#include "Statistics.h"

using std::string;

#define AUTHENTIFICATION_FAIL -1	// ���� ���� ����
#define AUTHENTIFICATION_SUCCESS 1	// ���� ���� ����
#define BASE_ACCOUNT_ID 100			// ���¹�ȣ�� 100������

class Account {
private:
	int nID=-1;	// ���� ��ȣ
	int nBalance=0; // �ܰ�
	string strAccountName; // ����
	string strPassword;	// ���� ��й�ȣ

private:
	inline bool authenticate(int id, string passwd); // ���� ���� : true(1), ���� ���� : false(0)

public:
	Account();
	void create(int id, int money, string name, string password); // ���� ����
	void close();
	int check(int id, string password); // return �� : nBalance(�ܰ�) or ���� ����(AUTHENTIFICATION_FAIL)
	int getAcctID() { return nID; }	// ���� ��ȣ �о����
	int deposit(int id, string password, int money);
	int deposit(int id, int money);		//��ü�� ���� deposit�Լ� �ߺ�
	int widraw(int id, string password, int money);
	int getBalance() { return nBalance; }
	string getAccountName() { return strAccountName; }
};
#endif