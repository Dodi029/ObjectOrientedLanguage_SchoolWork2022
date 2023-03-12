#include<iostream>
#include<string>
#include<random>
using namespace std;

#include "ATMachine.h"
#include "Account.h"

ATMachine::ATMachine(int size, int balance, string password) {
	int nCurrentAccountNum = size;
	int nMachinBalance = balance;
	string strMangetPassword = password;
	pAcctArray = new Account[size];
}

ATMachine::~ATMachine() { delete[] pAcctArray; }

void ATMachine::displayMunu() {									// 화면 출력부
	cout << "---------------------" << endl;
	cout << "--     TUKOREA     --" << endl;
	cout << "---------------------" << endl;
	cout << " 1. 계좌 개설" << endl;
	cout << " 2. 계좌 조회" << endl;
	cout << " 3. 계좌 입금" << endl;
	cout << " 4. 계좌 출금" << endl;
	cout << " 6. 계좌 해지" << endl;
	cout << " 9. 업무 종료" << endl;
}

void ATMachine::createAccount() {
	// 난수 생성
	random_device rd;											// 컴퓨터가 실행하면서 마주치는 무작위적인 요소
	mt19937 gen(rd());											// <random> 라이브버리에서 제공하는 난수 생성 엔진
	uniform_int_distribution<int> dis(BASE_ACCOUNT_ID, 1000);	// 균등 분포 객체(원하는 범위 작성)
	int id = dis(gen);

	string name;
	string password;

	cout << "-------  개설  -------" << endl;
	cout << " 이름 입력 : ";
	cin >> name;
	cout << " 암호 입력 : ";
	cin >> password;

	for (int i = 0; i < BASE_ACCOUNT_ID; i++) {
		if (pAcctArray[i].getAcctID() != -1)					// 계좌 번호가 초기값이 아니면 배열에 저장
		{
			(pAcctArray + i)->create(id, 0, name, password);	// create()함수 형태로 저장
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

	for (int i = 0; i < BASE_ACCOUNT_ID; i++) {
		bol = (pAcctArray + i)->check(id, password);			// 반복하면서 배열에 아이디 비밀번호 같은게 있는지 확인
		if (bol != -1) {										// '-1'은 오류일 때 리턴, -1이 아니면 같은 계좌가 있는것
			(pAcctArray + i)->close();							// 아이디 비밀번호가 같은 계좌가 있으면 close()함수로 계좌 해지
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

	for (int i = 0; i < BASE_ACCOUNT_ID; i++) {
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

	cout << "-------  조회  -------" << endl;
	cout << " 계좌 번호 입력 : ";
	cin >> id;
	cout << " 비밀 번호 입력 : ";
	cin >> password;
	cout << " 입금액    입력 : ";
	cin >> inmoney;

	for (int i = 0; i < BASE_ACCOUNT_ID; i++) {
		totalMoney = (pAcctArray + i)->deposit(id, password, inmoney);
		if (totalMoney != -1) {									// 오류가 아니면 잔액 계산
			cout << " 현재 잔액 : " << totalMoney << endl;
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
	for (int i = 0; i < 100; i++)
	{
		totalMoney = (pAcctArray + i)->widraw(id, password, outmoney);
		if (totalMoney != -1 && totalMoney != -2)				// 계좌가 틀리지 않고 잔액이 부족하지 않을 때 실행
		{
			cout << " 현재 잔액 : " << totalMoney << endl;
			cout << " 출금 완료" << endl;
			break;
		}
		if (totalMoney == -2) break;							// 잔액이 부족할 때
	}
	if (totalMoney == -1) {										// 계좌가 잘못되었을 때
		cout << " 잘못된 계좌 번호 혹은 비밀 번호 입니다." << endl;
	}
}