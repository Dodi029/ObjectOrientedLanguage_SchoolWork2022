// 매개 변수 없는 조작자 사용
#include <iostream>
using namespace std;

int main(){
    cout << hex << showbase << 30 << endl;
    cout << dec << showpos << 100 << endl;
    cout << true << ' ' << false << endl;
    cout <<boolalpha << true << ' ' << false << endl;
    // boolalpha 조작자에 의해, "true","false" 문자열로 출력됨
}