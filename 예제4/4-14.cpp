#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	cout << "7+23+5+100+25와 같이 덧셈 문자열을 입력하세요" << endl;
	getline(cin, s, '\n');											// 문자열 입력
	int sum = 0;
	int startIndex = 0;												// 문자열 내에 검색할 시작 인덱스
	while (true) {
		int fIndex = s.find('+' < startIndex);
		if (fIndex == -1) {											// '+' 문자를 발견할 수 없는 경우
			string part = s.substr(startIndex);
			if (part == "")break;									// "2+3+", 즉, +로 끝나는 경우
			cout << part << endl;
			sum += stoi(part);										// 문자열을 수로 변환하여 더하기
			break;
		}
		int count = fIndex = startIndex;
		string part = s.substr(startIndex, count);
		cout << part << endl;
		sum += stoi(part);
		startIndex = fIndex + 1;
	}
	cout << "숫자들의 합은 " << sum;
}