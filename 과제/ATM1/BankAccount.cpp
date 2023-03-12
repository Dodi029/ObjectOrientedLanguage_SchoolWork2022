#include "BankAccount.h"

BankAccount::BankAccount(int a, string b, int c) {
	계좌번호 = a;
	예금주 = b;
	잔액 = c;
}

void BankAccount::set계좌번호(int 계좌번호) {
	this->계좌번호 = 계좌번호;
}
void BankAccount::set예금주(string 예금주) {
	this->예금주 = 예금주;
}

void BankAccount::set잔액(int 잔액) {
	this->잔액 = 잔액;
}

int BankAccount::get계좌번호() {
	return 계좌번호;
}

string BankAccount::get예금주() {
	return 예금주;
}

int BankAccount::get잔액() {
	return 잔액;
}

void BankAccount::입금(int 입금액) {
	잔액 += 입금액;
	cout << 입금액 << "원이 입금되어 현재 잔액은 " << 잔액 << "원입니다." << endl;
}

void BankAccount::출금(int 출금액) {
	while(잔액 < 출금액) {
		cout << "입력한 금액이 현재 잔액 " << 잔액 << "원보다 많습니다." << endl;
		cout << "출금액 입력 : ";
		cin >> 출금액;
	}
	잔액 -= 출금액;
	cout << 출금액 << "원이 출금되어 현재 잔액은 " << 잔액 << "원입니다." << endl;
}

void BankAccount::계좌정보출력() {
	cout << "======================" << endl;
	cout << "현재 계좌의 정보" << endl;
	cout << "계좌번호 : " << 계좌번호 << endl;
	cout << "예금주 : " << 예금주 << endl;
	cout << "잔액 : " << 잔액 << endl;
	cout << "======================" << endl;
}