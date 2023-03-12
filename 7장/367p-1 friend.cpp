#include<iostream>
using namespace std;

class Book;

int operator+=(int op2);
int operator-=(int op2);

class Book {
	string name;
	int price;
	int page;
public:
	Book(string name, int price, int page) {
		this->name = name;
		this->price = price;
		this->page = page;
	}
	void show();
	friend Book& operator+=(Book&Book, int op2);
	friend Book& operator-=(Book&Book, int op2);
};

void Book::show() {
	cout << name << ' ' << price << "원 " << page << " 페이지" << endl;
}
Book& operator+=(int op2) {
	price = price + op2;
	return *this;
}
Book& operator-=(int op2) {
	price = price - op2;
	return *this;
}
int main() {
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();
}