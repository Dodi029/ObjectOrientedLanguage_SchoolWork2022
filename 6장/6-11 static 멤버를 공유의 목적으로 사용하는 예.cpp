#include<iostream>
using namespace std;

class Circle {
private:
	static int numOfCircle;
	int radius;
public:
	Circle(int r = 1);
	~Circle() { numOfCircle--; }							// 생성된 원의 개수 감소
	double getArea() { return 3.14 * radius * radius; }
	static int getNumOfCircle() { return numOfCircle; }
};
Circle::Circle(int r) {
	radius = r;
	numOfCircle++;											// 생성된 원의 개수 증가
}
int Circle::numOfCircle = 0;								// 0으로 초기화
int main() {
	Circle* p = new Circle[10];
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircle() << endl;
	delete[]p;												// 10개의 소멸자 실행
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircle() << endl;
	Circle a;												// 생성자 실행
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircle() << endl;
	Circle b;												// 생성자 실행
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircle() << endl;
}