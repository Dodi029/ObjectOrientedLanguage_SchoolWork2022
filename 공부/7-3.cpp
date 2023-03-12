// �ٸ� Ŭ���� ��ü�� ������� ����
#include <iostream>
using namespace std;
class Rect;		// Rect Ŭ������ ����Ǳ� ���� ���� �����Ǵ� ������ ������ ���� ���� ����

class RectManager {	 // RectManager Ŭ���� ����
public:
	bool equals(Rect r, Rect s);
	void copy(Rect& dest, Rect& src);
};

class Rect {	// Rect Ŭ���� ����
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend RectManager;	// RectManager Ŭ������ ������ �Լ��� ����
};

bool RectManager::equals(Rect r, Rect s) {	// r�� s�� ������ true ����
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

void RectManager::copy(Rect& dest, Rect& src) {		// src�� dest�� ����
	dest.width = src.width;
	dest.height = src.height;
}

int main() {
	Rect a(3, 4), b(5, 6);
	RectManager man;

	man.copy(b, a);		// ��ü b�� width, height ���� a�� ��������
	if (man.equals(a, b))cout << "equal" << endl;
	else cout << "not equal" << endl;
}
// man.copy(b,a)�� ���� ��ü b�� a�� ũ�Ⱑ �����ϹǷ� "equal" ���