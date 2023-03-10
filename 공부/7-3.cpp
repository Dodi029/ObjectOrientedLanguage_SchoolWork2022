// 다른 클래스 전체를 프렌드로 선언
#include <iostream>
using namespace std;
class Rect;		// Rect 클래스가 선언되기 전에 먼저 참조되는 컴파일 오류를 막기 위한 선언문

class RectManager {	 // RectManager 클래스 선언
public:
	bool equals(Rect r, Rect s);
	void copy(Rect& dest, Rect& src);
};

class Rect {	// Rect 클래스 선언
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend RectManager;	// RectManager 클래스를 프랜드 함수로 선언
};

bool RectManager::equals(Rect r, Rect s) {	// r과 s가 같으면 true 리턴
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

void RectManager::copy(Rect& dest, Rect& src) {		// src를 dest에 복사
	dest.width = src.width;
	dest.height = src.height;
}

int main() {
	Rect a(3, 4), b(5, 6);
	RectManager man;

	man.copy(b, a);		// 객체 b의 width, height 값이 a와 같아진다
	if (man.equals(a, b))cout << "equal" << endl;
	else cout << "not equal" << endl;
}
// man.copy(b,a)를 통해 객체 b와 a의 크기가 동일하므로 "equal" 출력