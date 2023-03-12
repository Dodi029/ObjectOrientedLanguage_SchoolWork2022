#include<iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};
Circle::Circle() {
	radius = 1;
	cout << "������ ���� radius = " << radius << endl;
}
Circle::Circle(int r) {
	radius = r;
	cout << "������ ���� radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "�Ҹ��� ���� radius = " << radius << endl;
}
int main() {
	// ��ü�� �ϳ� �� ���� (circle�̸����� ��ü ����)
	// setRadius�� getArea�� �ڵ� ����
	// new�� delete�� �ִ� �� ����
	// ���� �������� �� �� ����
	int radius;
	Circle circle;		// ���� ��ü ����
	while (true) {
		cout << "���� ������ �Է�(�����̸� ����)>>";
		cin >> radius;
		if (radius < 0) break;								// ������ �ԷµǾ� ����
		//Circle* p = new Circle(radius);						// ������ü����
		//cout << "���� ������ " << p->getArea() << endl;
		circle.setRadius(radius);
		cout << "���� ������ " << circle.getArea() << endl;
		//delete p;											// ��ü ��ȯ
	}
}
// ���� ������ ���� ������ ���̸� �˾ƾ���
// ��Ȯ�� �迭�� ũ�⸦ �˰� �����ϴ°� �ƴѰ�