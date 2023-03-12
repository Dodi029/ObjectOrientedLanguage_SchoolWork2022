#ifndef CIRCLE_H
#define CIRCLE_H

//Circle 클래스 선언
class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	double getArea();
};
#endif