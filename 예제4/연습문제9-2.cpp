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

void Person::set(string name, string tel)
{
	this->name = name;
	this->tel = tel;
}
Person::Person()
{

}

int main() {
	Person people[3];
	string name;
	string tel;
	cout << "이름과 전화번호를 입력해주세요>>" << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "사람 " << i + 1 << ">> ";
		cin >> name >> tel;
		people[i].set(name, tel);
	}

	cout << "모든 사람 이름 ";
	for (int i = 0; i < 3; i++) {
		cout << people[i].getName() << ' ';
	}

	cout << endl;

	cout << "전화번호를 검색합니다. 이름을 입력하세요>>";
	string str;
	cin >> str;

	for (int i = 0; i < 3; i++) {
		if (str.compare(people[i].getName()) == 0) {
			cout << "전화번호는 " << people[i].getTel() << endl;
			break;
		}
	}
}