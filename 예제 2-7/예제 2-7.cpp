#include<iostream>
#include<string>
using namespace std;

int main()
{
	string song("Falling in love with you");
	string elvis("Elvis Presley");
	char singer[6];	

	cout << song + "를 부른 가수는";
	cout << "(힌트 : 첫글자는 " << elvis[0] << ")?";

	cin.getline(singer,6);
	if (singer == elvis)
		cout << "맞았습니다";
	else
		cout << "틀렸습니다 " + elvis + "입니다" << endl;
}