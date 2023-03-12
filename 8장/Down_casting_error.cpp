#include <iostream>
#include <string>
using namespace std;

class Point {		// 2���� ��鿡�� �� ���� ǥ���ϴ� Ŭ���� Point ����
	int x, y;		// �� �� (x, y) ��ǥ��
public:
	void set(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void ShowPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};
class ColorPoint : public Point {		// 2���� ��鿡�� �÷� ���� ǥ���ϴ� Ŭ����
										// ColorPoint, Point�� ��ӹ���
	string color;			// ���� �� ǥ��
public:
	void setColor(string color) { this->color = color; }
	void ShowColorPoint();
};
void ColorPoint::ShowColorPoint() {
	cout << color << ":";
	ShowPoint();			// Point�� ShowPoint() ȣ��
}
int main() {
	Point po, * pBase;
	ColorPoint* pDer;
	pBase = &po;

	pDer = (ColorPoint*)pBase;
	// �⺻ Ŭ������ ��ĳ���õǾ� ���� �ʱ� ������
	// �Ļ�Ŭ������ ����Ű�� ����
	// �ٿ� ĳ������ �� �Ļ� Ŭ������ ��ü�� ����Ű�� ����
	pDer->set(3, 4);
	pDer->setColor("Red");
}