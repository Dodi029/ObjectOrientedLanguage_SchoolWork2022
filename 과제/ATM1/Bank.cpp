#include "Bank.h"

Bank::Bank() {
	num = 0;
}

void Bank::계좌가입() {
	string 예금주;
	cout << "예금주 입력 : ";
	cin >> 예금주;
	int 잔액;
	cout << "잔액 입력 : ";
	cin >> 잔액;

	계좌[num] = new BankAccount(num, 예금주, 잔액);
	num++;
}

void Bank::계좌해지() {
	int 계좌번호;
	cout << "계좌번호 입력 : ";
	cin >> 계좌번호;
	for(int i=0; i<num; i++) {
		if(계좌[i]->get계좌번호() == 계좌번호) {
			delete 계좌[i];
			for(int j=i+1; j<num; j++) {
				계좌[j-1] = 계좌[j];
			}
			cout << i << "번 계좌가 소멸되었습니다." << endl;
			num--;
			return;
		}
	}
}

void Bank::전체계좌출력() {
	cout << "총 계좌의 수 : " << num << endl;
	cout << "------------------------" << endl;
	cout << "  계좌번호         이름 " << endl;
	cout << "------------------------" << endl;
	
	for(int i=0; i<num; i++) {
		cout << "   " << 계좌[i]->get계좌번호() << "  " << 계좌[i]->get예금주() << endl;
	}
	cout << "------------------------" << endl;
}

void Bank::단일계좌출력() {
	int 계좌번호;
	cout << "계좌번호 입력 : ";
	cin >> 계좌번호;
	
	for(int i = 0; i < num; i++) {
		if(계좌[i]->get계좌번호() == 계좌번호)
			계좌[i]->계좌정보출력();
	}
}

void Bank::입금() {
	int 계좌번호, 입금액;
	cout << "계좌번호 입력 : ";
	cin >> 계좌번호;
	cout << "입금액 입력 : ";
	cin >> 입금액;
	
	for(int i=0 ; i<num; i++) {
		if(계좌[i]->get계좌번호() == 계좌번호) {
			계좌[i]->입금(입금액);
			return;
		}
	}
}

void Bank::출금() {
	int 계좌번호, 출금액;
	cout << "계좌번호 입력 : ";
	cin >> 계좌번호;
	cout << "출금액 입력 : ";
	cin >> 출금액;
	
	for(int i=0; i<num; i++) {
		if(계좌[i]->get계좌번호() == 계좌번호) {
			계좌[i]->출금(출금액);
			return;
		}
	}
}