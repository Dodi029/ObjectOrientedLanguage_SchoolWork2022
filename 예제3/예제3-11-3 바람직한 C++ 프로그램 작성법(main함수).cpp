#include<iostream>
using namespace std;

#include "����3-11-1 �ٶ����� C++ ���α׷� �ۼ���(�������)circle.h"
int main() {
	Circle donut;
	double area = donut.getArea();
	cout << "donut�� ������ " << area << "\n";

	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza�� ������ " << area << "\n";
}