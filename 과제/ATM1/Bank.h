#include "BankAccount.h"

#define SIZE 10

class Bank {
private:
	BankAccount *계좌[SIZE];
	int num;
public:
	Bank();
	void 계좌가입();
	void 계좌해지();
	void 전체계좌출력();
	void 단일계좌출력();
	void 입금();
	void 출금();
};