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
										// == ������ �Լ� ����
	Power operator+ (int op2);
};
void Power::show() {
	cout << "kick=" << kick << ',' << "punch="
		<< punch << endl;
}
Power Power::operator+(int op2) {
	Power tmp;
	tmp.kick = kick + op2;				// kick�� op2 ���ϱ�
										// punch�� op2 ���ϱ�
	tmp.punch = punch + op2;
	return tmp;							 // �ӽ� ��ü ����
}		
int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = a + 2;							 // �Ŀ� ��ü�� ���� ���ϱ�
	// b = 2 + a; �� �ۼ��� ���� �߻� (tmp�� �� ����ߴ��� �����غ� ��)
	a.show();
	b.show();
}
