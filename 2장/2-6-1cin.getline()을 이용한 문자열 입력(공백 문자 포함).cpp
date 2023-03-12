#include<iostream>
using namespace std;

int main()
{
	cout << "학번과 이름을 입력하세요>>";

	char NumName[100];
	cin.getline(NumName, 100, '\n');			// 키보드로부터 주소 읽기

	cout << "학번과 이름은 " << NumName << "입니다\n";	// 주소 출력
}