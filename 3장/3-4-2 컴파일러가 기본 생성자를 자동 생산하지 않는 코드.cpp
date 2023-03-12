#include<iostream>
using namespace std;
class triangle
{
public:
	int width, height;
	// 기본 생성자 없음
	triangle(int a, int b);				
	double getArea();
};
triangle::triangle() :triangle(1, 1) {}	
triangle::triangle(int a, int b)		
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
	triangle tri1;						// 매개 변수 없는 함수 호출 불가 = 기본 생성자 없음
	double area = tri1.getArea();
	cout << "작은 삼각형 면적은 " << area << endl;

	triangle tri(5, 6);					
	area = tri.getArea();
	cout << "큰 삼각형 면적은 " << area << endl;
}