#include<iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	Power operator+(Power op2);							// +연산자 함수
};
void Power::show() {
	cout << "kick = " << kick << ", " << "punch = " << punch << endl;
}
Power Power::operator+(Power op2) {
	Power tmp;											// 임시 객체 생성
	tmp.kick = this->kick + op2.kick;
	tmp.punch = this->punch + op2.punch;
	return tmp;											// 더한 결과 리턴
}
int main() {
	Power a(3, 5), b(4, 6), c;
	c = a + b;											// 파워 객체 + 연산
	a.show();
	b.show();
	c.show();	
														// 객체 a, b, c 순으로 출력
}