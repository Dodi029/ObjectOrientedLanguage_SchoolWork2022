#include<iostream>
using namespace std;
class Rect;

class RectManager {								// RectManager Ŭ���� ����
public:
	bool equals(Rect r, Rect s);
};
class Rect {									// Rect Ŭ���� ����
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend bool RectManager::equals(Rect r, Rect s);
};
bool RectManager::equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height)return true;
	else return false;
}
int main() {
	Rect a(3, 4), b(3, 4);
	RectManager man;
	if (man.equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}