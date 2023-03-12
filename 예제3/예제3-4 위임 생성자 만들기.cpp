#include<iostream>
using namespace std;
class Circle
{
public:
	int radius;
	Circle();
	Circle(int r);
	double getArea();
};
Circle::Circle():Circle(1)			// 위임 생성자 생성
{
									// 내부에 아무것도 없음
}
Circle::Circle(int r)				// 타겟 생성자
{
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}
double Circle::getArea()
{
	return 3.14 * radius * radius;
}

int main()
{
	Circle donut;					// 매개 변수 없는 생산자 호출
	double area = donut.getArea();
	cout << "donut 면적은" << area << endl;

	Circle pizza(30);				// 매개 변수 있는 생산자 호출
	area = pizza.getArea();
	cout << "pizza 면적은" << area << endl;
}