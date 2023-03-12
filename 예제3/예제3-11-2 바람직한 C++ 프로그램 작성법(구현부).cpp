#include<iostream>
using namespace std;

#include "예제3-11-1 바람직한 C++ 프로그램 작성법(헤더파일)circle.h"

// Circle 클래스 구현. 모든 멤벼 함수를 작성
Circle::Circle() {
	radius = 1;
	cout << "반지름 " << radius << " 원 생성\n";
}
Circle::Circle(int r) {
	radius = r;
	cout << "반지름 " << radius << " 원 생성\n";
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}