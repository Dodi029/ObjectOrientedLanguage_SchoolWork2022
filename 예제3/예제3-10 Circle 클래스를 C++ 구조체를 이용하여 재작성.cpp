#include<iostream>
using namespace std;

// C++ ����ü ����
struct StructCircle
{
private:
	int radius;
public:
	StructCircle(int r) { radius = r; }		// ����ü�� ������
	double getArea();
};

double StructCircle::getArea()
{
	return 3.14 * radius * radius;
}

int main()
{
	StructCircle waffle(3);
	cout << "������ " << waffle.getArea();
}