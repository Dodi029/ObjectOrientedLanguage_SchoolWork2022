#include<iostream>
using namespace std;

int main()
{
	cout << "�й��� �̸��� �Է��ϼ���>>";

	char NumName[100];
	cin.getline(NumName, 100, '\n');			// Ű����κ��� �ּ� �б�

	cout << "�й��� �̸��� " << NumName << "�Դϴ�\n";	// �ּ� ���
}