#include<iostream>
#include<cstring>

using namespace std;

class Person {												// Person Ŭ���� ����
	char* name;
	int id;
public:
	Person(int id, char* name);								// ������
	~Person();
	void changeName(char* name);
	void show() { cout << id << ',' << name << endl; }
};
Person::Person(int id, char* name) {						// ������
	this->id = id;
	int len = strlen(name);									// name�� ���� ����
	this->name = new char[len + 1];							// name ���ڿ� ���� �Ҵ�
	strcpy(this->name, name);								// name�� ���ڿ� ����
}
Person::~Person() {											// �Ҹ���
	if (name)												// ���� name�� ���� �Ҵ�� �迭�� ������
		delete[]name;										// ���� �Ҵ� �޸� �Ҹ�
}
void Person::changeName(char* name) {						// �̸� ����
	if (strlen(name) > strlen(this->name)) return;
	strcpy(this->name, name);
}
int main() {
	Person father(1, "Kitae");								// (1) father ��ü ����
	Person daughter(father);								// (2) daughter ��ü ���� ����, ���� ������ ȣ��

	cout << "daughter ��ü ���� ���� ---" << endl;
	father.show();											// (3) father ��ü ���
	daughter.show();										// (4) daughter ��ü ���

	daughter.changeName("Grace");
	cout << "daughter �̸��� Grace�� ������ ��---"endl;
	father.show();											// (5) father ��ü ���
	daughter.show();										// (6) daughter ��ü ���

	return 0;												// (6), (7) daughter, father ��ü �Ҹ�
}