// iterator를 사용하여 vector의 모든 원소에 3 곱하기
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int>v;	// 벡터 정수 생성
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	vector<int>::iterator it;		// 벡터 v의 원소에 대한 포인터 it 선언

	for (it = v.begin(); it != v.end(); it++) {
		// v.end()는 NULL로 이 반복문은 NULL이 나오기 전까지 반복함
		int n = *it;		// it가 가리키는 원소 값 리턴
		n = n * 3;		// 곱하기 3
		*it = n;		// it가 가리키는 원소에 값 쓰기
	}
	for (it = v.begin(); it != v.end(); it++)		// 백터 v의 모든 원소 출력
		cout << *it << ' ';
	cout << endl;
}