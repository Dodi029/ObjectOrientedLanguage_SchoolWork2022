// ������ �Լ� �����
#include <iostream>
using namespace std;

class Rect; // Rect Ŭ������ ����Ǳ� ���� ���� �����Ǵ� ������ ������ ���� ���� ����
bool equals(Rect r, Rect s);	// equals() �Լ� ����

class Rect {	// Rectr Ŭ���� ����
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend bool equals(Rect r, Rect s);		// equaks() �Լ��� ������� ����
};

bool equals(Rect r, Rect s) {	// �ܺ� �Լ� // equals() �Լ��� private �Ӽ��� ���� width, height�� ������ �� �ִ�
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

int main() {
	Rect a(3, 4), b(4, 5);
	if (equals(a, b)) cout << "equals" << endl;
	else
		cout << "not equals" << endl;
}
// ��ü a�� b�� ������ ũ���� �簢���� �ƴϹǷ� "not equals" ���