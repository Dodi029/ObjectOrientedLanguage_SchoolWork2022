#include<iostream>
using namespace std;

#include "����3-11-1 �ٶ����� C++ ���α׷� �ۼ���(�������)circle.h"

// Circle Ŭ���� ����. ��� �⺭ �Լ��� �ۼ�
Circle::Circle() {
	radius = 1;
	cout << "������ " << radius << " �� ����\n";
}
Circle::Circle(int r) {
	radius = r;
	cout << "������ " << radius << " �� ����\n";
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}