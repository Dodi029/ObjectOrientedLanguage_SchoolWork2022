#include <iostream>
#include <string>
using namespace std;

class Point {		// 2차원 평면에서 한 점을 표현하는 클래스 Point 선언
	int x, y;		// 한 점 (x, y) 좌표값
public:
	void set(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void ShowPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};
class ColorPoint : public Point {		// 2차원 평면에서 컬러 점을 표현하는 클래스
										// ColorPoint, Point를 상속받음
	string color;			// 점의 색 표현
public:
	void setColor(string color) { this->color = color; }
	void ShowColorPoint();
};
void ColorPoint::ShowColorPoint() {
	cout << color << ":";
	ShowPoint();			// Point의 ShowPoint() 호출
}
int main() {
	Point po, * pBase;
	ColorPoint* pDer;
	pBase = &po;

	pDer = (ColorPoint*)pBase;
	// 기본 클래스가 업캐스팅되어 있지 않기 때문에
	// 파생클래스를 가리키지 못함
	// 다운 캐스팅할 때 파생 클래스가 객체를 가리키지 못함
	pDer->set(3, 4);
	pDer->setColor("Red");
}