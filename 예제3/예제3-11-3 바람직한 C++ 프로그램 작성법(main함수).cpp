#include<iostream>
using namespace std;

#include "예제3-11-1 바람직한 C++ 프로그램 작성법(헤더파일)circle.h"
int main() {
	Circle donut;
	double area = donut.getArea();
	cout << "donut의 면적은 " << area << "\n";

	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza의 면적은 " << area << "\n";
}