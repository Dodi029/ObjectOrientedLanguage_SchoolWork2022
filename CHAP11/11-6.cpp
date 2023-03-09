// width(), fill(), precision()을 사용한 포맷 출력
#include <iostream>
using namespace std;

void showWidth(){
    cout.width(10);         // 다음에 출력되는 "Hello"를 10칸으로 지정
    cout << "Hello" << endl;
    cout.width(5);          // 다음에 출력되는 정수 12를 5칸으로 지정
    cout << 12 << endl;

    cout << '%';
    cout.width(10);         // 다음에 출력되는 "Korea/"만 10칸으로 지정
    cout << "Korea/" << "Seoul/" << "City" << endl;
}

int main(){
    showWidth();
    cout << endl;

    cout.fill('^');
    showWidth();
    cout << endl;

    cout.precision(5);
    cout << 11./3. << endl;
}