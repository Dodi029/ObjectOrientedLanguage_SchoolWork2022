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

	cout << "�̸��� ��ȭ��ȣ�� �Է����ּ���>>" << endl;

	for (int i = 0; i < 3; i++) {
		cout << "���" << i + 1 << ">>";
		cin >> Name >> Tel;
	}

	cout << "��� ����� �̸��� ";
	for (int i = 0; i < 3; i++) {
		cout << pinfo[i].getName() << " ";
	}

	cout << endl << "��ȭ��ȣ�� �˻��� �̸��� �Է��ϼ���>>";
	cin >> Name;

	for (int i = 0; i < 3; i++) {
		if (Name.compare(pinfo[i].getName()) == 0) {
			cout << "��ȭ��ȣ�� " << pinfo[i].getTel();
			break;
		}
	}
}