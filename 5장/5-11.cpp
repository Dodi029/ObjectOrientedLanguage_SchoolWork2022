#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	int id;
public:
	Person(int id, string name);
	Person(Person& person);
	~Person();
	void changeName(string name);
	void show() { cout << id << ", " << name << endl; }
};
Person::Person(int id, string name) {
	this->name = name;
	this->id = id;
}
Person::Person(Person& person) {
	this->name = person.name;
	this->id = person.id;
}
Person::~Person() {}

void Person::changeName(string name) {
	this->name = name;
}

int main() {
	string name = "Kitae";
	Person father(1, name);
	Person daugther(father);

	cout << "daughter 객체 생성 직후" << endl;
	father.show();
	daugther.show();

	string changeName = "Grace";
	daugther.changeName(changeName);
	cout << "daughter 이름을 Grace로 변경한 후" << endl;
	father.show();
	daugther.show();
}