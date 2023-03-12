#include <iostream>
using namespace std;
class Rectangle {
	int width;
public:
	Rectangle();
	Rectangle(int w);
	~Rectangle();
	void setWidth(int w) { width = w; }
	int getArea() { return width * width; }
};
Rectangle::Rectangle() {
	width = 1;
	cout << "积己磊 角青 width = " << width << endl;
}
Rectangle::Rectangle(int w) {
	width = w;
	cout << "积己磊 角青 width = " << width << endl;
}
Rectangle::~Rectangle() {
	cout << "家戈磊 角青 width = " << width << endl;
}
int main() {
	Rectangle* pArray = new Rectangle[3];
	pArray[0].setWidth(10);
	pArray[1].setWidth(20);
	pArray[2].setWidth(30);
	for (int i = 0; i < 3; i++) {
		cout << pArray[i].getArea() << '\n';
	}
	Rectangle* p = pArray;
	for (int i = 0; i < 3; i++) {
		cout << p->getArea() << '\n';
		p++;
	}
	delete[] pArray;
}