#include<iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};
Circle::Circle() {
	radius = 1;
	cout << "생성자 실행 radius = " << radius << endl;
}
Circle::Circle(int r) {
	radius = r;
	cout << "생성자 실행 radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "소멸자 실행 radius = " << radius << endl;
}
int main() {
	// 객체를 하나 더 생성 (circle이름으로 객체 생성)
	// setRadius와 getArea로 코드 생성
	// new와 delete가 있는 줄 제거
	// 정적 생성으로 할 수 있음
	int radius;
	Circle circle;		// 정적 객체 생성
	while (true) {
		cout << "정수 반지름 입력(음수이면 종료)>>";
		cin >> radius;
		if (radius < 0) break;								// 음수가 입력되어 종료
		//Circle* p = new Circle(radius);						// 동적객체생성
		//cout << "원의 면적은 " << p->getArea() << endl;
		circle.setRadius(radius);
		cout << "원의 면적은 " << circle.getArea() << endl;
		//delete p;											// 객체 반환
	}
}
// 동적 생성과 정적 생성의 차이를 알아야함
// 정확한 배열의 크기를 알고 시작하는가 아닌가