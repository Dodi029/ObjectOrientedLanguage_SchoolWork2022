#include<iostream>
using namespace std;

class Rectangle {					// Rectangle Ŭ���� �����
public:
	int width;
	int height;
	double getArea();				// ������ ����Ͽ� �����ϴ� �Լ�
};
double Rectangle::getArea() {		// Rectangle Ŭ���� ������
	return width* height;
}
int main() {
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;
	cout << "�簢���� ������ " << rect.getArea() << endl;
}