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

void ATMachine::displayMunu() {									// 화면 출력부
	cout << "---------------------" << endl;
	cout << "--     TUKOREA     --" << endl;
	cout << "---------------------" << endl;
	cout << " 1. 계좌 개설" << endl;
	cout << " 2. 계좌 조회" << endl;
	cout << " 3. 계좌 입금" << endl;
	cout << " 4. 계좌 출금" << endl;
	cout << " 5. 계좌 이체" << endl;
	cout << " 6. 계좌 해지" << endl;
	cout << " 9. 업무 종료" << endl;
}

void ATMachine::createAccount() {
	random_device rd;											// 컴퓨터가 실행하면서 마주치는 무작위적인 요소
	mt19937 gen(rd());											// <random> 라이브버리에서 제공하는 난수 생성 엔진
	uniform_int_distribution<int> dis(BASE_ACCOUNT_ID, 1000);	// 균등 분포 객체(원하는 범위 작성)
	int id = dis(gen);											// 무작위 난수를 id로 지정

	string name;
	string password;

	cout << "-------  개설  -------" << endl;
	cout << " 이름 입력 : ";
	cin >> name;
	cout << " 암호 입력 : ";
	cin >> password;

	for (int i = 0; i < nMaxAccountNum; i++) {
		if (pAcctArray[i].getAcctID() == -1) {					// 계좌 번호가 초기값이 아니면 배열에 저장
			(pAcctArray + i)->create(id, 0, name, password);	// create()함수 형태로 저장
			nCurrentAccountNum++;								// 현재 존재하는 계좌 개수 증가
			break;												// 저장하면 반복문 탈출
		}
	}
}

void ATMachine::closeAccount() {								// 계좌 해지
	int id;
	string password;
	int bol;													// 정보를 확인하기위해 작성

	cout << "-------  조회  -------" << endl;
	cout << " 계좌 번호 입력 : ";
	cin >> id;
	cout << " 비밀 번호 입력 : ";
	cin >> password;

	for (int i = 0; i < nMaxAccountNum; i++) {
		bol = (pAcctArray + i)->check(id, password);			// 반복하면서 배열에 아이디 비밀번호 같은게 있는지 확인
		if (bol != -1) {										// '-1'은 오류일 때 리턴, -1이 아니면 같은 계좌가 있는것
			(pAcctArray + i)->close();							// 아이디 비밀번호가 같은 계좌가 있으면 close()함수로 계좌 해지
			for (int i = 0; i < nMaxAccountNum; i++) {
				if ((pAcctArray + i)->getAcctID() != -1) {
					nCurrentAccountNum++;
				}
				break;
			}
			break;												// 반복문 탈출
		}
	}
	if (bol == -1) {											// 같은 계좌가 없을때, 해지할 수 없을 때
		cout << " 잘못된 계좌 번호 혹은 비밀 번호 입니다." << endl;
	}
}

void ATMachine::checkMoney() {									// 계좌 확인
	int id;
	string password;
	int money;

	cout << "-------  조회  -------" << endl;
	cout << " 계좌 번호 입력 : ";
	cin >> id;
	cout << " 비밀 번호 입력 : ";
	cin >> password;

	for (int i = 0; i < nMaxAccountNum; i++) {
		money = (pAcctArray + i)->check(id, password);			// check()함수에서 아이디 비밀번호가 맞으면 nBalance리턴함
		if (money != -1) {										// 계좌가 맞는지 확인되면 잔액 출력
			cout << " 현재 잔액 : " << money << endl;
			break;
		}
	}
	if (money == -1)											// 계좌가 확인이 안될 때
		cout << " 잘못된 계좌 번호 혹은 비밀 번호 입니다." << endl;
}

void ATMachine::depositMoney() {								// 입금
	int id;
	string password;
	int inmoney;												// 입금액
	int totalMoney;												// 잔액

	cout << "-------  입금  -------" << endl;
	cout << " 계좌 번호 입력 : ";
	cin >> id;
	cout << " 비밀 번호 입력 : ";
	cin >> password;
	cout << " 입금액    입력 : ";
	cin >> inmoney;

	for (int i = 0; i < nMaxAccountNum; i++) {
		totalMoney = (pAcctArray + i)->deposit(id, password, inmoney);
		if (totalMoney != -1) {									// 오류가 아니면 잔액 계산
			nMachineBalance += inmoney;							// ATM기계의 총 잔액 증가
			cout << " 현재 잔액 : " << totalMoney << endl;
			cout << " 입금 완료" << endl;
			break;
		}
	}
	if (totalMoney == -1)										// 오류			
		cout << " 잘못된 계좌 번호 혹은 비밀 번호 입니다." << endl;
}

void ATMachine::widrawMoney() {									// 출금
	int id;
	string password;
	int outmoney;												// 출금액
	int totalMoney;												// 잔액

	cout << "------ 출금 ------" << endl;
	cout << " 계좌 번호 입력 : ";
	cin >> id;
	cout << " 비밀 번호 입력 : ";
	cin >> password;
	cout << " 출금액    입력 : ";
	cin >> outmoney;

	for (int i = 0; i < nMaxAccountNum; i++) {
		totalMoney = (pAcctArray + i)->widraw(id, password, outmoney);
		if (totalMoney != -1 ) {				// 계좌가 틀리지 않고 잔액이 부족하지 않을 때 실행
			if (totalMoney != -2) {
				if (nMachineBalance >= outmoney) {
					nMachineBalance -= outmoney;
					cout << " 현재 잔액 : " << totalMoney << endl;
					cout << " 출금 완료" << endl;
					break;
				}
				else {
					cout << " 출금할 수 없습니다." << endl;
				}
			}
			else
				break;
		}
		if (totalMoney == -2) break;							// 잔액이 부족할 때
	}
	if (totalMoney == -1) {										// 계좌가 잘못되었을 때
		cout << " 잘못된 계좌 번호 혹은 비밀 번호 입니다." << endl;
	}
}

void ATMachine::transfer() {									// 계좌 이체
	int id;														// 이체할 계좌번호
	string password;											// 이체할 계좌의 비밀번호
	int to_id;													// 이체받을 계좌번호
	int money;													// 이체할 돈
	// int totalMoney;												// 이체하고 남은 돈
	int inmoney;												// 이체받은 계좌의 남은 돈
	int outmoney;												// 이체한 계좌의 남은 돈

	cout << "------ 이체 ------" << endl;
	cout << " 계좌 번호 입력 : ";
	cin >> id;
	cout << " 비밀 번호 입력 : ";
	cin >> password;
	cout << " 이체 계좌 입력 : ";
	cin >> to_id;
	cout << " 이체 금액 입력 : ";
	cin >> money;

	//for (int i = 0; i < BASE_ACCOUNT_ID; i++) {
	//	outmoney = (pAcctArray + i)->deposit(to_id, money);
	//	if (outmoney != -1) {									// 오류가 아니면 잔액 계산
	//		
	//		for (int j = 0; j < BASE_ACCOUNT_ID; j++)
	//		{
	//			inmoney = (pAcctArray + j)->widraw(id, password, money);
	//			if (inmoney != -1 )	{
	//				if (outmoney == -2)break;
	//				cout << " 현재 잔액 : " << inmoney << endl;
	//				cout << " 이체 완료" << endl;
	//				break;
	//			}
	//			if (inmoney == -1) {
	//				cout << " 계좌를 찾을 수 없습니다." << endl;
	//				break;
	//			}
	//			break;
	//		}
	//		if (inmoney==-1&&outmoney==-1) {										// 계좌가 잘못되었을 때
	//			cout << " 잘못된 계좌 번호 혹은 비밀 번호 입니다." << endl;
	//		}
	//		if (outmoney == -1) {
	//			cout << " 이체할 계좌가 잘못되었습니다." << endl;
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
					cout << " 현재 잔액 : " << inmoney << endl;
					cout << " 이체 완료" << endl << endl;
					break;
				}
				break;
			}
			if (inmoney == -1)
			{
				cout << " 계좌를 찾을 수 없습니다." << endl << endl;
				break;
			}
			break;
		}
	}
	if (inmoney == -1 && outmoney == -1)
		cout << " 계좌를 찾을 수 없습니다." << endl;
	if (outmoney == -1)
		cout << " 이체계좌를 찾을 수 없습니다." << endl << endl;
}

ATMachine::~ATMachine() { delete[] pAcctArray; }								// 배열 소멸자