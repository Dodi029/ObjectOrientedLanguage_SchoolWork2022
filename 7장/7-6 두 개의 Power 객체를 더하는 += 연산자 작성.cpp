#include<iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show();							// == ������ �Լ� ����
	Power& operator+=(Power op2);
};
void Power::show() {
	cout << "kick = " << kick << ", " << "punch = " << punch << endl;
}
Power& Power::operator+=(Power op2) {
	kick = kick + op2.kick;					// kick ���ϱ�
	punch = punch + op2.punch;				// punch ���ϱ�
	return *this;							// ���� ��� ����
}
int main() {
	Power a(3, 5), b(4, 6), c;
	a.show();
	b.show();
	c = a += b;								// �Ŀ� ��ü ���ϱ�
	a.show();
	c.show();
}