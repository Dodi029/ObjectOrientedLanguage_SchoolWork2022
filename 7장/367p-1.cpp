#include<iostream>

using namespace std;

class Book {
	string name;
	int original_price;
	int page;
public:
	Book (string name, int original_price, int page) {
		this->name = name;
		this->original_price = original_price;
		this->page = page;
	}
	void show();
	Book &operator+=(int op2);
	Book &operator-=(int op2);
};

void Book::show() {
	cout << name << ' ' << original_price << "�� " << page << " ������" << endl;
}
Book &Book::operator+=(int op2) {
	original_price = original_price + op2;
	return *this;
}
Book& Book::operator-=(int op2) {
	original_price = original_price - op2;
	return *this;
}
int main() {
	Book a("û��", 20000, 300), b("�̷�", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();
}