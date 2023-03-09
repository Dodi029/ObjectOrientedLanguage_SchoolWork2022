// 매개 변수를 가진 조작자 사용 예 -0에서 50까지의 5의 배수를 10진수, 8진수, 16진수로 출력하라
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    cout << showbase;

    // 타이틀을 출력한다
    cout << setw(8) << "Number";
    cout << setw(10) << "Octal";
    cout << setw(10) << "Hexa" << endl;

    // 하나의 수를 10진수, 8진수, 16진수 형태로 한 줄에 출력한다
    for (int i=0;i<50;i++){
        cout << setw(8) << setfill('.') << dec << i;            // 10진수
        cout <<setw(10) << setfill(' ') << oct << i;            // 8진수
        cout << setw(10) << setfill(' ') << hex << i << endl;   // 16진수
    }
}