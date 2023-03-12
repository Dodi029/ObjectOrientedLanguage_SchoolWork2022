#pragma once
#include <iostream>
#include <string>

#ifndef ATMACHINE_H
#define ATMACHINE_H


#include "ATMachine.h"
#include "Account.h"
#include "Statistics.h"

using std::string;

#define NEGATIVE_ATM_BALANCE -10	// ATM 잔고 부족시

class ATMachine {
private:
	Account* pAcctArray;	// 동적생성 고객계좌 배열 포인터
	int nMachineBalance;	// ATM잔고
	int nMaxAccountNum;		// 동적생성 고객계좌 배열 크기
	int nCurrentAccountNum = 0;	// 개설된 고객 계좌 수
	string strManagerPassword;	// 관리자 비밀번호

	string name, password;
	int id, id1, id2;
	int index, money,store;

	Statistics s, a, m,so;

	bool isManager(string password);
	void displayReport();

public:
	ATMachine(int size, int balance, string password);
	// (계좌 배열크기, ATM 잔고, 관리자 암호 초기화)
	~ATMachine();

	int getnCurrentAccountNum() { return nCurrentAccountNum; }
	void displayMenu();	// ATM 메뉴 출력
	void createAccount();	// 계좌 개설
	void checkMoney();		// 계좌 조회
	void closeAccount(); // 계좌 입금
	void depositMoney();
	void widrawMoney();
	void transfer();		// 계좌 이체
	void managerMode();		// 고객 관리
};

#endif