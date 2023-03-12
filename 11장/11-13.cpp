// 사용자 정의 조작자 만들기
#include <iostream>
#include <string>
using namespace std;

istream& question(istream& ins) {	// 조작자 작성
	cout << "거울아 거울아 누가 제일 예쁘니?";
	return ins;
}

int main() {
	string answer;
	cin >> question >> answer;	// 조작자 사용
	cout << "세상에서 제일 예븐 사람은 " << answer << "입니다." << endl;
}