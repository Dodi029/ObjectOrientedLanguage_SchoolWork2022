#include<iostream>
#include<cstring>												// strcmp() �Լ��� ����ϱ� ���� ��� ����
using namespace std;

int main()
{
	char password[11];
	cout << "���α׷��� �����Ϸ��� ��ȣ�� �Է��ϼ���." << endl;		// �� ĭ ���� Ű �Է��ؾ� ��
	while (true)
	{
		cout << "��ȣ>>";
		cin >> password;
		if (strcmp(password, "C++") == 0)
		{
			cout << "���α׷��� ���� �����մϴ�." << endl;
			break;
		}
		else
			cout << "��ȣ�� Ʋ���ϴ�~~" << endl;
	}
}