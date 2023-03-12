#include<iostream>
#include<string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person();
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};

Person::Person(){...}
void Person::set(string name, string tel) {...}

class PersonManager {
	Person* p;
	int size;
public:
	PersonManager(int n) {...}
	void show() {...}
	void search() {...}
	~PersonManager() {
		delete[]p;
	}
};

int main(){
	PersonManager manager(3);
	manager.show();

	cout << "이름과 전화 번호를 입력해 주세요" << endl;

	for (int i = 0; i < 3; i++) {
		cout << "사람"<<[i]<<">>";
		getline(cin, PersonManager[i], '\n');
	}

}