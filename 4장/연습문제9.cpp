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

void Person::set(string N, string T) {
	name = N;
	tel = T;
}

int main() {
	string Name, Tel;
	Person* pinfo = new Person[3];

	cout << "이름과 전화번호를 입력해주세요>>" << endl;

	for (int i = 0; i < 3; i++) {
		cout << "사람" << i + 1 << ">>";
		cin >> Name >> Tel;
	}

	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < 3; i++) {
		cout << pinfo[i].getName() << " ";
	}

	cout << endl << "전화본호를 검색할 이름을 입력하세요>>";
	cin >> Name;

	for (int i = 0; i < 3; i++) {
		if (Name.compare(pinfo[i].getName()) == 0) {
			cout << "전화번호는 " << pinfo[i].getTel();
			break;
		}
	}
}