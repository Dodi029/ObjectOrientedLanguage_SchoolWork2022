#include <iostream>
#include <string>
#include <random>

using namespace std;

#include "ATMachine.h"

int bol;        // 고객 정보확인
//int id;              //계좌번호
//string password;     //비밀번호

ATMachine::ATMachine(int size, int balance, string password)
{
	nCurrentAccountNum = size;
	nMachineBalance = balance;
	strManagerPassword = password;
	pAcctArray = new Account[size];
}

ATMachine ::~ATMachine() { delete[]pAcctArray; }

void ATMachine :: displayMenu()
{
	cout << "-------------------------" << endl;
	cout << "-     TUKOREA BANK     -" << endl;
	cout << "-------------------------" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 계좌 조회" << endl;
	cout << "3. 계좌 입금" << endl;
	cout << "4. 계좌 출금" << endl;
	cout << "6. 계좌 해지" << endl;
	cout << "9. 업무 종료" << endl;
}

void ATMachine::createAccount()
{
	random_device rd;                                //양질의 시드값얻기위함
	mt19937 gen(rd());                               //난수 생성 엔진 객체정의
	uniform_int_distribution<int> dis(BASE_ACCOUNT_ID, 1000);    //난수 범위 설정
	int id = dis(gen);
	string name;
	string password;
	
	cout << "------  개설 ------" << endl;
	cout << "이름 입력: ";
	cin >> name;
	cout << "암호 입력: ";
	cin >> password;
	//pAcctArray 배열 for문 돌려서 id가 -1인 값을 찾아서 거기다 할당
	for (int i = 0; i < BASE_ACCOUNT_ID; i++) {
		if (pAcctArray[i].getAcctID() == -1)
		{
			(pAcctArray + i)->create(id, 0, name, password);
			break;
		}
	}
}

void ATMachine::checkMoney()
{
	int id;              //계좌번호
	string password;     //비밀번호
	int money;           //현재 잔액 또는 인증실패
	cout << "------ 조회 ------" << endl;
	cout << "계좌번호 입력: ";
	cin >> id;
	cout << "비밀번호 입력: ";
	cin >> password;
	for (int i = 0; i < BASE_ACCOUNT_ID; i++)
	{
		money = (pAcctArray+i)->check(id, password);
		if (money != -1)
		{
			cout << "현재 잔액 : " << money << endl << endl;
			break;
		}
	}
	if (money == -1)
		cout << "계좌를 찾을 수 없습니다." << endl << endl;
}
void ATMachine::closeAccount() // 계좌 해지
{
	int id;              //계좌번호
	string password;     //비밀번호
	cout << "------ 조회 ------" << endl;
	cout << "계좌번호 입력: ";
	cin >> id;
	cout << "비밀번호 입력: ";
	cin >> password;
	for (int i = 0; i < 100; i++)
	{
		bol = (pAcctArray + i)->check(id, password);
		if (bol != -1)
		{
			(pAcctArray + i)->close();
			break;
		}	
	}
	if(bol == -1)
		cout << "계좌를 찾을 수 없습니다." << endl << endl;
}
void ATMachine::depositMoney()  // 계좌 입금
{
	int id;              // 계좌번호
	int money;           // 입금할 금액
	string password;     // 비밀번호
	int sumMoney;        // 현재 잔액 또는 인증실패

	cout << "------ 입금 ------" << endl;
	cout << "계좌번호 입력: ";
	cin >> id;
	cout << "비밀번호 입력: ";
	cin >> password;
	cout << "입금액 입력 : ";
	cin >> money;
	for (int i = 0; i < 100; i++)
	{
			sumMoney = (pAcctArray + i)->deposit(id, password, money);
		if (sumMoney != -1)
		{
			cout << "현재 잔액 : " << sumMoney << endl;
			cout << "입금 완료" << endl << endl;
			break;
		}
	}
	if(sumMoney == -1)
		cout << "계좌를 찾을 수 없습니다." << endl << endl;
}

void ATMachine::widrawMoney() // 계좌 출금
{
	int id;              // 계좌번호
	int money;           // 입금할 금액
	string password;     // 비밀번호
	int sumMoney;        // 현재 잔액 또는 인증실패

	cout << "------ 출금 ------" << endl;
	cout << "계좌번호 입력: ";
	cin >> id;
	cout << "비밀번호 입력: ";
	cin >> password;
	cout << "출금액 입력 : ";
	cin >> money;
	for (int i = 0; i < 100; i++)
	{
		sumMoney = (pAcctArray + i)->widraw(id, password, money);
		if (sumMoney != -1 && sumMoney!=-2)
		{
			cout << "현재 잔액 : " << sumMoney << endl;
				cout << "출금 완료" << endl << endl;
				break;
		}
		if (sumMoney == -2) break;
	}
	if (sumMoney == -1) {
		cout << "계좌를 찾을 수 없습니다." << endl << endl;
	}
}