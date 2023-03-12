#include<iostream>
#include<string>
using namespace std;

#include "Account.h"
#include "Account.h"

Account::Account() {
	int nID = -1;														// 초기값
	int nBalance = 0;
}

inline bool Account::authenticate(int id, string passwd) {				// 계좌 비교(성공:true=1, 실패:false=0)
	if (getAcctID() == id) {											// 아이디가 같은지 확인
		if (strPassword.compare(passwd) == 0)							// 비밀번호가 같은지 확인
			return true;												// 둘다 같으면 리턴 1
		else {
			return false;												// 비번이 틀리면 리턴 0
		}
	}
	else {
		return false;													// 아이디가 달라도 리턴 0
	}
}
void Account::create(int id, int money, string name, string password) {	// 계좌 개설
	nID = id;
	nBalance = money;
	strAccountName = name;
	strPassword = password;

	cout << strAccountName << "님 " << getAcctID() << "번 계좌 번호가 정상적으로 개설되었습니다. 감사합니다." << endl;
}
void Account::close() {													// 계좌 해지
	if (nBalance == 0) {												// 돈이 0일때 해지가능
		cout << getAcctID() << " 번 계좌가 해지되었습니다. 감사합니다." << endl;
		nID = -1;														// 초기값으로 초기화
		strAccountName = " ";											// 초기값으로 초기화
		strPassword = " ";												// 초기화
	}
	else {																// 돈이 남아있으면 해지불가
		cout << " 계좌 해지가 불가능합니다." << endl;
		cout << " 아직 계좌에 " << nBalance << " 원 남아있습니다." << endl;
		cout << " 남은 돈을 모두 출금하고 다시 시도해주세요. 감사합니다." << endl;
	}
}
int Account::check(int id, string password) {
	if (authenticate(id, password)) {									// 계좌 아이디 비밀번호 비교하는 함수 사용
		return nBalance;												// 아이디 비밀번호가 같으면 잔액 확인
	}
	else {
		return AUTHENTIFICATION_FAIL;									// 아이디 비밀번호가 다르면 오류 출력
	}
}

int Account::deposit(int id, string password, int inmoney) {			// 입금
	if (authenticate(id, password)) {									// 아이디 비밀번호 비교 함수
		nBalance += inmoney;											// 잔액에 입금액 더하기
		return nBalance;												// 잔액 리턴
	}
	else {
		return AUTHENTIFICATION_FAIL;									// 오류 리턴
	}
}

int Account::widraw(int id, string password, int outmoney)				// 출금
{
	if (authenticate(id, password))										// 아이디 비밀번호 비교
	{
		if (nBalance < outmoney)										// 잔액보다 출금하려는 금액이 많을 때
		{
			cout << " 잔액이 부족합니다. " << endl;
			return -2;													// 값을 비교하기 위해 리턴값 지정
		}
		else															// 출금이 가능할 때
		{
			nBalance -= outmoney;										// 잔액에 출금액 빼기
			return nBalance;											// 잔액 리턴
		}
	}
	else
		return AUTHENTIFICATION_FAIL;									// 오류 리턴
}