#include<iostream>
using namespace std;
class Rectangle					// Rectangle Ŭ���� �����
{
public:							// public ����
	int width;
	int height;
	int getAtea();				// ������ ����Ͽ� �����ϴ� �Լ�
};
int Rectangle::getAtea()		// Rectangle Ŭ���� ������
{
	return width * height;
}
int main()
{
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;
	cout << "�簢���� ������ " << rect.getAtea() << endl;
}