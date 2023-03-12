#include<iostream>
using namespace std;

class Circle {
private:
	static int numOfCircle;
	int radius;
public:
	Circle(int r = 1);
	~Circle() { numOfCircle--; }							// ������ ���� ���� ����
	double getArea() { return 3.14 * radius * radius; }
	static int getNumOfCircle() { return numOfCircle; }
};
Circle::Circle(int r) {
	radius = r;
	numOfCircle++;											// ������ ���� ���� ����
}
int Circle::numOfCircle = 0;								// 0���� �ʱ�ȭ
int main() {
	Circle* p = new Circle[10];
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircle() << endl;
	delete[]p;												// 10���� �Ҹ��� ����
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircle() << endl;
	Circle a;												// ������ ����
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircle() << endl;
	Circle b;												// ������ ����
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircle() << endl;
}