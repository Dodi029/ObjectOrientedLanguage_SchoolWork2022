#include<iostream>
using namespace std;
class triangle
{
public:
	int width, height;
	triangle();							// 위임 생성자
	triangle(int a, int b);				// 타켓 생성자
	double getArea();
};
triangle::triangle() :triangle(1, 1) {}	// 위임 생성자
triangle::triangle(int a, int b)		// 타켓 생성자
{
	width = a;
	height = b;
	cout << "밑변이 " << width << " 이고 높이가 " << height << "인 삼각형 생성" << endl;
}
double triangle::getArea()
{
	return width * height / 2;
}
int main()
{
	triangle tri1;						// 매개 변수 없는 생성자 호출
	double area = tri1.getArea();
	cout << "작은 삼각형 면적은 " << area << endl;

	triangle tri(5, 6);					// 매개 변수 있는 생성자 호출
	area = tri.getArea();
	cout<<"큰 삼각형 면적은 "<<area<<endl;
}