#include<iostream>
#include<string>
using namespace std;

void star(int a = 5);					// �Լ� ���� ����
void msg(int id, string text = "");

void star(int a) {						// �Լ� ����
	for (int i = 0; i < a; i++)
		cout << '*';
	cout << endl;
}
void msg(int id, string text) {
	cout << id << ' ' << text << endl;
}
int main() {
	star();								// star() ȣ��
	star(10);

	msg(10);							// msg() ȣ��
	msg(10, "hello");
}