// 매개변수 x,y의 합을 출력하는 람다식 만들기
#include <iostream>
using namespace std;

int main(){
    // 람다 함수 선언과 동시에 호출(x=2, y=3 전달)
    [](int x, int y){cout << "합은 " << x+y;} (2,3);
    // 함수의 이름이 없으므로 식이 끝날 때 바로 값을 대입함
}