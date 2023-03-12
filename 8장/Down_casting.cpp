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
	ColorPoint* pDer;
	Point* pBase = &cp;			// 업 캐스팅
	pBase->set(3, 4);
	pBase->ShowPoint();

	pDer = (ColorPoint*)pBase;	// 다운 캐스팅
	pDer->setColor("Red");		// 정상 컴파일
	pDer->ShowColorPoint();		// 정상 컴파일
}