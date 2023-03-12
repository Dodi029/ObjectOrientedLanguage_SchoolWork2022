#include<iostream>
#include<string>

using namespace std;

class Book {
	string title;
	int price;
public:
	Book(string title, int price);
	~Book();
	void show() { cout << title << ' ' << price << "¿ø" << endl; }
};

Book::Book(string title, int price) {
	this->title = title;
	this->price = price;
}
Book::~Book() {}

int main() {
	Book cpp("C++", 10000);
	Book jave = cpp;
	cpp.show();
	jave.show();

	return 0;
}