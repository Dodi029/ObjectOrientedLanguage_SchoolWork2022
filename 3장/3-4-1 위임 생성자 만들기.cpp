#include<iostream>
using namespace std;
class triangle
{
public:
	int width, height;
	triangle();							// ���� ������
	triangle(int a, int b);				// Ÿ�� ������
	double getArea();
};
triangle::triangle() :triangle(1, 1) {}	// ���� ������
triangle::triangle(int a, int b)		// Ÿ�� ������
{
	width = a;
	height = b;
	cout << "�غ��� " << width << " �̰� ���̰� " << height << "�� �ﰢ�� ����" << endl;
}
double triangle::getArea()
{
	return width * height / 2;
}
int main()
{
	triangle tri1;						// �Ű� ���� ���� ������ ȣ��
	double area = tri1.getArea();
	cout << "���� �ﰢ�� ������ " << area << endl;

	triangle tri(5, 6);					// �Ű� ���� �ִ� ������ ȣ��
	area = tri.getArea();
	cout<<"ū �ﰢ�� ������ "<<area<<endl;
}