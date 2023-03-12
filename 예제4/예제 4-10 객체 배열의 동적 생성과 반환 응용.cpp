#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	~Circle() {}
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};
Circle::Circle() {
	radius = 1;
}
int main() {
	cout << "�����ϰ��� �ϴ� ���� ����?";
	int n, radius;
	cin >> n;																			// ���� ���� �Է�
	Circle* pArray = new Circle[n];														// n ���� �迭 ����
	for (int i = 0; i < n; i++)
	{
		cout << "��" << i + 1 << ": ";													// ������Ʈ ���
		cin >> radius;																	// ������ ���
																						// �� Circle ��ü�� ���������� �ʱ�ȭ
		pArray[i].setRadius(radius);
	}

	int count = 0;
	Circle* p = pArray;
	for (int i = 0; i < n; i++)
	{
		cout << p->getArea() << ' ';													// ���� ���� ���
		if (p->getArea() >= 100 && p->getArea() <= 200)
			count++;
			p++;
	}
	cout << endl << "������ 100���� 200 ������ ���� ������ " << count << endl;	
	
	delete[] pArray;																	// ��ü �迭 �Ҹ�
}