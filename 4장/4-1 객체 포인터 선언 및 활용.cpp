#include<iostream>
using namespace std;

#include"Circle.h"

int main() {
	Circle donut;
	Circle pizza(30);

	cout << donut.getArea() << endl;
	Circle* p;
	p = &donut;
	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;
	p = &pizza;
	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;
}