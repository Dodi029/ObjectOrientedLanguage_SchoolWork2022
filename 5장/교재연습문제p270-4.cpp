#include<iostream>
using namespace std;

class Com {
private:
	int a, b;
public:
	int Compare(int a, int b);
	bool bigger(int a, int b, int& big);
};
int Com::Compare(int a, int b){
	if (a == b) {
		cout << a << endl;
	}
	else if (a > b) {
		cout << a << endl;
	}
	else {
		cout << b << endl;
	}
}
bool Com::bigger(int a, int b, int& big) {
	if (a > b) {
		big = a;
		return false;
	}
	else if (b > a) {
		big = b;
		return false;
	}
	else {
		big = a;
		return true;
	}
}
int main() {
	Com acc;
	int num1, num2;
	int big;

	cout << "숫자 2개를 입력하세요 : ";
	cin >> num1 >> num2;
	
	int a = num1;
	int b = num2;

	acc.bigger(num1, num2, big);
}