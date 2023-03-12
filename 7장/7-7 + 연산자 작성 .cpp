#include <iostream>
using namespace std;
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
										// == 연산자 함수 선언
	Power operator+ (int op2);
};
void Power::show() {
	cout << "kick=" << kick << ',' << "punch="
		<< punch << endl;
}
Power Power::operator+(int op2) {
	Power tmp;
	tmp.kick = kick + op2;				// kick에 op2 더하기
										// punch에 op2 더하기
	tmp.punch = punch + op2;
	return tmp;							 // 임시 객체 리턴
}		
int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = a + 2;							 // 파워 객체와 정수 더하기
	// b = 2 + a; 로 작성시 오류 발생 (tmp를 왜 사용했는지 생각해볼 것)
	a.show();
	b.show();
}
