// set() 사용하는거 빼고 작성
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class Book {
	char* title;
	int price;
public:
	Book(const char* title, int price);
	Book(Book& B);
	~Book();
	void show() { cout << title << ' ' << price << "원" << endl; }
};
Book::Book(const char* title, int price) {
	this->price = price;
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
}
Book::Book(Book& B) {
	this->price = B.price;
	int len = strlen(B.title);
	this->title = new char[len + 1];
	strcpy(this->title, B.title);
}
Book::~Book() {
	if (title)
		delete[] title;
}

int main() {
	Book cpp("C++", 10000);
	Book jave = cpp;
	cpp.show();
	jave.show();

	return 0;
}