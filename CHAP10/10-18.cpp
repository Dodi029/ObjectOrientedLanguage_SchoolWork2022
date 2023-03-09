// 캡쳐 리스트에 참조 활용. 합을 외부에 저장하는 람다식
#include <iostream>
using namespace std;

int main(){
    int sum = 0;        // 지역 변수

    // 합 5를 지역변수 sum에 저장
    [&sum](int x, int y){sum = x+y;} (2,3);
    // 캡쳐 리스트의 값을 바꾸기 위해서는 참조 변수로 선언해야 함
    // 지역 변수 sum에 대한 참조를 캡쳐 리스트를 통해 받고, 합한 결과를 지역변수 sum에 저장
    cout << "합은 " << sum;
}