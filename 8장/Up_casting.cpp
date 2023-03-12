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
	ColorPoint cp;			// 파생 클래스의 객체 생성
	ColorPoint* pDer = &cp;
	Point* pBase = pDer;	// 업 캐스팅
	// 기본 클래스 포인터가 파생 클래스 객체를 가리킴
	pDer->set(3, 4);
	pBase->ShowPoint();		// ShowPoint()가 기본 클래스 공간이므로 접근가능
	pDer->setColor("Red");
	pDer->ShowColorPoint();
}