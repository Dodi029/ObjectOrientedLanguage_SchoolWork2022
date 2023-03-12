#include<iostream>
using namespace std;

int main()
{
	cout << "이름을 입력하세요 >>";

	char address_name[20];
	cin.getline(address_name, 20, '\n');

	cout << "주소를 입력하세요 >>";

	char address_home[100];
	cin.getline(address_home, 100, '\n');

	cout << "나이를 입력하세요 >>";

	int age;
	cin >> age;
	cout << "나이를 입력하세요 >>";

	cout << address_name << ", " << address_home << ", " << age << "세\n";
}

/*
#define MAX 1000

char address_name[MAX]
char address_home[MAX]
char age[MAX]

cout << "이름을 입력하세요 >>";
cin.getline(address_name, MAX, '\n');

cout << "주소를 입력하세요 >>";
cin.getline(address_home, MAX, '\n');

cout << "나이를 입력하세요 >>";
cin.getline(age, MAX, '\n');

cout << address_name << ", " << address_home << ", " << age << "세;
*/