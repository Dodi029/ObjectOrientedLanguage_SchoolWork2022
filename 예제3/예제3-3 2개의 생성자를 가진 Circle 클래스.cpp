#include<iostream>
using namespace std;
class Circle
{
public:
	int radius;
	Circle();						// �Ű� ���� ���� ������
	Circle(int r);					// �Ű� ���� 1�� �ִ� ������
	double getArea();
};
Circle::Circle()
{
	radius = 1;						// ������ �� 1�� ���Ƿ� �־��
	cout << "������ " << radius << " �� ����" << endl;
}
Circle::Circle(int r)
{
	radius = r;
	cout << "������ " << radius << " �� ����" << endl;
}
double Circle::getArea()
{
	return 3.14 * radius * radius;
}

int main()
{
	Circle donut;					// �Ű� ���� ���� ������ ȣ��
									// ����� ���ÿ� ������ 1
	double area = donut.getArea();	
	cout << "donut ������" << area << endl;

	Circle pizza(30);				// �Ű� ���� �ִ� ������ ȣ��
	area = pizza.getArea();
	cout << "pizza ������" << area << endl;
}

/*
int main()
{
	Circle donut;

	double area = donut.getArea();
	cout << "donut ������ " << area << endl;

	Circle pizza(30);

	double area1 = donut.getArea();
	cout << "pizza ������ " << area1 << endl;
	// �̷��� �ص� �Ȱ��� ���������� ������ �ϳ� �� ����°� (area1)
	   �Ƹ� �޸𸮸� �� ��Ƹ�����
*/