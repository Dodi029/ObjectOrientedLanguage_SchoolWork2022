#include<iostream>
using namespace std;
class Circle
{
public:
	int radius;
	Circle();						// 매개 변수 없는 생산자
	Circle(int r);					// 매개 변수 1개 있는 생산자
	double getArea();
};
Circle::Circle()
{
	radius = 1;						// 반지름 값 1을 임의로 넣어둠
	cout << "반지름 " << radius << " 원 생성" << endl;
}
Circle::Circle(int r)
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
									// 선언과 동시에 반지름 1
	double area = donut.getArea();	
	cout << "donut 면적은" << area << endl;

	Circle pizza(30);				// 매개 변수 있는 생산자 호출
	area = pizza.getArea();
	cout << "pizza 면적은" << area << endl;
}

/*
int main()
{
	Circle donut;

	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;

	Circle pizza(30);

	double area1 = donut.getArea();
	cout << "pizza 면적은 " << area1 << endl;
	// 이렇게 해도 똑같이 구동되지만 변수가 하나 더 생기는것 (area1)
	   아마 메모리를 더 잡아먹을듯
*/