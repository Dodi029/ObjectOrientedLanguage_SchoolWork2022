#include<iostream>
#include<string>
using namespace std;

int main()
{
	string song("Falling in love with you");
	string elvis("Elvis Presley");
	char singer[6];	

	cout << song + "�� �θ� ������";
	cout << "(��Ʈ : ù���ڴ� " << elvis[0] << ")?";

	cin.getline(singer,6);
	if (singer == elvis)
		cout << "�¾ҽ��ϴ�";
	else
		cout << "Ʋ�Ƚ��ϴ� " + elvis + "�Դϴ�" << endl;
}