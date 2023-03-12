#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
	int 계좌번호;
	string 예금주;
	int 잔액;
public:
	BankAccount(int a, string b, int c);
	void set계좌번호(int 계좌번호);
	void set예금주(string 예금주);
	void set잔액(int 잔액);
	int get계좌번호();
	string get예금주();
	int get잔액();
	void 입금(int 입금액);
	void 출금(int 출금액);
	void 계좌정보출력();
};