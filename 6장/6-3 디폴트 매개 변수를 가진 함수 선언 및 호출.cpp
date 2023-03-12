#include<iostream>
#include<string>
using namespace std;

void star(int a = 5);					// 함수 원형 선언
void msg(int id, string text = "");

void star(int a) {						// 함수 구현
	for (int i = 0; i < a; i++)
		cout << '*';
	cout << endl;
}
void msg(int id, string text) {
	cout << id << ' ' << text << endl;
}
int main() {
	star();								// star() 호출
	star(10);

	msg(10);							// msg() 호출
	msg(10, "hello");
}