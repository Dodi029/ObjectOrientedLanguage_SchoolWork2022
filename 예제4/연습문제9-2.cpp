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
	cout << "�̸��� ��ȭ��ȣ�� �Է����ּ���>>" << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "��� " << i + 1 << ">> ";
		cin >> name >> tel;
		people[i].set(name, tel);
	}

	cout << "��� ��� �̸� ";
	for (int i = 0; i < 3; i++) {
		cout << people[i].getName() << ' ';
	}

	cout << endl;

	cout << "��ȭ��ȣ�� �˻��մϴ�. �̸��� �Է��ϼ���>>";
	string str;
	cin >> str;

	for (int i = 0; i < 3; i++) {
		if (str.compare(people[i].getName()) == 0) {
			cout << "��ȭ��ȣ�� " << people[i].getTel() << endl;
			break;
		}
	}
}