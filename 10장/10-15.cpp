// 매개변수 x, y의 합을 출력하는 람다식 만들기
#include <iostream>
using namespace std;

int main() {
	// 람다 함수 선언과 동시에 호출(x=2, y=3 전달)
	[ ]   (int x, int y)                {cout << "합은 " << x + y; } (2, 3);	// 5출력
// 리스트	  리스트     리턴타입(생략됨)	        	함수 바디        값을 입력하여 람다식 호출
//  캡쳐 리스트
}