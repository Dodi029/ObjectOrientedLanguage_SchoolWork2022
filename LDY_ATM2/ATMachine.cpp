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

void ATMachine :: displayMenu() {									// 화면 출력부
	cout << "-------------------------" << endl;
	cout << "-     TUKOREA BANK     -" << endl;
	cout << "-------------------------" << endl;
	cout << " 1. 계좌 개설" << endl;
	cout << " 2. 계좌 조회" << endl;
	cout << " 3. 계좌 입금" << endl;
	cout << " 4. 계좌 출금" << endl;
	cout << " 5. 계좌 이체" << endl;
	cout << " 6. 계좌 해지" << endl;
	cout << " 7. 고객 관리" << endl;
	cout << " 9. 업무 종료" << endl;
}

void ATMachine::createAccount() {									// 계좌 생성
	random_device rd;												// 컴퓨터가 실행하면서 마주치는 무작위적인 요소
	mt19937 gen(rd());												// <random> 라이브러리에서 제공하는 난수 생성 엔진
	uniform_int_distribution<int> dis(BASE_ACCOUNT_ID, 1000);		// 균등 분호 객체 (원하는 범위 작성)
	int id = dis(gen);												// 생성된 무작위 난수를 id로 지정

	string name;
	string password;
	
	cout << "------  개설 ------" << endl;
	cout << " 이름 입력 : ";
	cin >> name;
	cout << " 암호 입력 : ";
	cin >> password;

	for (int i = 0; i < nMaxAccountNum; i++) {
		if (pAcctArray[i].getAcctID() == -1) {						// 배열이 초기값으로 저장되어 있으면 그곳에 계좌번호 저장
			(pAcctArray + i)->create(id, 0, name, password);		// create()함수 형태로 저장
			nCurrentAccountNum++;									// 현재 존재하는 계좌 개수 증가
			break;													// 배열에 저장하면 반복문 탈출
		}
	}
}

void ATMachine::closeAccount() {									// 계좌 해지
	int id;
	string password;
	int bol;														// 정보를 확인하기 위해 저장
	int i, j;														// 반복문 횟수를 저장하기 위해 선언

	cout << "------ 조회 ------" << endl;
	cout << " 계좌번호 입력: ";
	cin >> id;
	cout << " 비밀번호 입력: ";
	cin >> password;
	
	for (i = 0; i < nMaxAccountNum; i++) {
		bol = (pAcctArray + i)->check(id, password);				// 반복하면서 배열에 아이디 비밀번호 같은게 있는지 확인
		if (bol != -1) {											// '-1'은 오류일 때 리턴, -1이 아니면 같은 계좌가 있는것
			(pAcctArray + i)->close();								// 아이디 비밀번호가 같은 계좌가 있으면 close()함수로 계좌 해지
			nCurrentAccountNum--;									// 현재 존재하는 계좌 개수 감소
			j = i;
			break;													// 배열에서 해당하는 계좌를 찾으면 반복문 탈출
		}
	}
	if (bol == -1) {
		cout << " 잘못된 계좌 번호 입니다." << endl;
	}
	else {
		for (int i =j; i < nMaxAccountNum - 1; i++) {				// 계좌를 정상적으로 해지했을 때
			int k = i + 1;											// 배열에 저장된 계좌들 위치를 당김
			*(pAcctArray + i) = *(pAcctArray + k);
		}
	}
}

void ATMachine::checkMoney() {										// 계좌 조회
	int id;
	string password;
	int money;           

	cout << "------ 조회 ------" << endl;
	cout << " 계좌 번호 입력: ";
	cin >> id;
	cout << " 비밀 번호 입력: ";
	cin >> password;

	for (int i = 0; i < nMaxAccountNum; i++) {
		money = (pAcctArray+i)->check(id, password);				// check()함수에서 아이디 비밀번호가 맞으면 nBalacne 리턴함
		if (money != -1) {											// 계좌가 맞는지 확인되면 잔액 출력
			cout << "현재 잔액 : " << money << endl;
			break;
		}
	}
	if (money == -1) {												// 계좌 확인에 실패했을 때
		cout << " 잘못된 계좌 번호 입니다." << endl;
	}
}

void ATMachine::depositMoney() {									// 입금
	int id;
	string password;
	int inmoney;													// 입금액
	int totalMoney;													// 잔액

	cout << "------ 입금 ------" << endl;
	cout << " 계좌 번호 입력 : ";
	cin >> id;
	cout << " 비밀 번호 입력 : ";
	cin >> password;
	cout << " 입금액    입력 : ";
	cin >> inmoney;

	for (int i = 0; i < nMaxAccountNum; i++) {
			totalMoney = (pAcctArray + i)->deposit(id, password, inmoney);	// 아이디, 비밀번호가 맞으면 deposit() 함수 실행

		if (totalMoney != -1) {										// 오류가 아닐 때
			nMachineBalance += inmoney;								// ATM 총 잔액 증가
			cout << " 현재 잔액 : " << totalMoney << endl;
			cout << " 입금 완료" << endl;
			break;
		}
	}
	if (totalMoney == -1)											// 오류일 경우
		cout << " 잘못된 계좌 번호 입니다." << endl;
}

void ATMachine::widrawMoney() {										// 출금
	int id;
	string password;
	int outmoney;
	int totalMoney;

	cout << "------ 출금 ------" << endl;
	cout << " 계좌 번호 입력 : ";
	cin >> id;
	cout << " 비밀 번호 입력 : ";
	cin >> password;
	cout << " 출금액    입력 : ";
	cin >> outmoney;

	for (int i = 0; i < nMaxAccountNum; i++) {
		totalMoney = (pAcctArray + i)->widraw(id, password, outmoney);		// 아이디 비밀번호가 맞으면 widraw() 함수 실행
		if (totalMoney != -1) {												// 잔액이 부족하지 않을 때
			if (totalMoney == -2) break;									// 오류인 경우 반복문 종료
			else {
				if (nMachineBalance >= outmoney) {							// ATM 총 잔액이 출금액보다 많을 때
					nMachineBalance -= outmoney;							// ATM 총 잔액에서 출금액을 뺌
					cout << " 현재 잔액 : " << totalMoney << endl;			// 출금
					cout << " 출금 완료" << endl;
					break;
				}
				else {
					cout << " 잔액이 부족합니다." << endl;					// 아닐 경우
					break;
				}
			}
		}
		
	}
	if (totalMoney == -1) {													// 계좌가 잘못되었을 때
		cout << " 잘못된 계좌 번호 입니다." << endl;
	}
}

void ATMachine::transfer() {												// 계좌 이체
	int id;																	// 이체할 계좌
	int to_id;																// 이체받을 계좌
	string password;														// 이체할 계좌의 비밀번호
	int money;																// 이체할 돈
	int inmoney = 0;														// 이체받은 계좌의 남은 돈
	int outmoney = 0;														// 이체할 계좌의 남은 돈

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
	for (int i = 0; i < nCurrentAccountNum; i++) {
		outmoney = (pAcctArray + i)->check(id, password);					// 이체할 계좌의 아이디 비밀번호 확인
		if (outmoney != -1) {												// 이체할 계좌의 아이디가 존재한다면
			for (int j = 0; j < nCurrentAccountNum; j++) {
				if ((pAcctArray + i)->getBalance() >= money) {				// 출금하려는 금액이 잔액보다 적어야 함
					inmoney = (pAcctArray + j)->deposit(to_id, money);		// 이체하는 함수 실행
					if (inmoney != -1) {									// 이체 받을 계좌가 존재한다면
						outmoney = (pAcctArray + i)->widraw(to_id, password, money);	// 그 계좌로 출금

						if (outmoney == -2) break;							// 이체할 계좌가 없으면 반복문 탈출

						cout << " 현재 잔액 : " << outmoney << endl;			// 이체할 계좌의 남은 돈 출력
						cout << " 이체 완료" << endl;
						break;
					}
				}
				else {
					cout << " 잔액이 부족합니다." << endl;					// 출금하려는 금액이 잔액보다 많을 경우
					break;
				}
			}
			if (inmoney == -1) {											// 이체받을 계좌번호가 틀렸을 때
				cout << " 이체받을 계좌를 찾을 수 없습니다." << endl;	
				break;
			}
			break;
		}
	}
	if (outmoney == -1)														// 이체할 계좌번호가 틀렸을 때
		cout << " 잘못된 계좌 번호 입니다." << endl;
}

bool  ATMachine::isManager(string password) {
	if (strManagerPassword.compare(password) == 0)							// 관리자 암호가 맞을 때
		return true;														// true(1) 리턴
	else																	// 관리자 암호가 틀릴 때
		return false;														// false(0) 리턴
}

void  ATMachine::displayReport() {											// 통계 화면 출력
	int sumMoney;
	int avg;
	int max;

	sumMoney = Statistics::sum(pAcctArray, nCurrentAccountNum);				// 클래스 리턴값 저장
	avg = Statistics::average(pAcctArray, nCurrentAccountNum);				// 클래스 리턴값 저장
	max = Statistics::max(pAcctArray, nCurrentAccountNum);					// 클래스 리턴값 저장

	cout << " ATM  현재 잔고 :      " << nMachineBalance <<"원" << endl;
	cout << " 고객 잔고 총액 :      " << sumMoney << "원" << "(" << "총" << nCurrentAccountNum << "명" << ")" << endl;
	cout << " 고객 잔고 평균 :      " << avg << "원" << endl;
	cout << " 고객 잔고 최고 :      " << max << "원" << endl;
	cout << "------------------------" << endl;
	cout << "-   고객 계좌 목록   -" << endl;
	cout << "------------------------" << endl;

	Statistics::sort(pAcctArray, nCurrentAccountNum);						// 내림차순 정렬

}

void  ATMachine::managerMode() {											// 관리자 모드
	string password;

	cout << "-------- 관리 --------" << endl;
	cout << " 관리자 비밀번호 입력 : ";
	cin >> password;

	if (isManager(password)) {												// 입력한 비밀번호가 맞는지 확인
		cout << " 관리자입니다." << endl;
		cout << "---------------------" << endl;
		displayReport();

	}
	else {
		cout << endl;
		cout << "관리자 비밀번호가 다릅니다." << endl;
	}
}