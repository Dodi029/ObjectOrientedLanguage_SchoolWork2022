#include<iostream>
using namespace std;

int main()
{
	cout << "�̸��� �Է��ϼ��� >>";

	char address_name[20];
	cin.getline(address_name, 20, '\n');

	cout << "�ּҸ� �Է��ϼ��� >>";

	char address_home[100];
	cin.getline(address_home, 100, '\n');

	cout << "���̸� �Է��ϼ��� >>";

	int age;
	cin >> age;
	cout << "���̸� �Է��ϼ��� >>";

	cout << address_name << ", " << address_home << ", " << age << "��\n";
}

/*
#define MAX 1000

char address_name[MAX]
char address_home[MAX]
char age[MAX]

cout << "�̸��� �Է��ϼ��� >>";
cin.getline(address_name, MAX, '\n');

cout << "�ּҸ� �Է��ϼ��� >>";
cin.getline(address_home, MAX, '\n');

cout << "���̸� �Է��ϼ��� >>";
cin.getline(age, MAX, '\n');

cout << address_name << ", " << address_home << ", " << age << "��;
*/