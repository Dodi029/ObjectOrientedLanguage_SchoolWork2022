// 리턴 값과 참조 매개 변수를 이용한 오류 처리
#include <iostream>
using namespace std;
// base exp 값을 계산하여 ret에 저장

bool getExp(int base, int exp, int &ret){
    if(base <= 0 || exp<= 0){       // 매개 변수 중 하나라도 음수면 -1을 리턴
        return false;
    }
    int value = 1;
    for (int n=0;n<exp;n++)
        value = value * base;
    ret = value;
    return true;
}

int main(){
    int v = 0;
    if(getExp(2,3,v))       // v = 2^3 = 8. getExp()는 true 리턴
        cout << "2의 3제곱은" << v << "입니다." << endl;
    else
        cout << " 오류. 2의 3제곱은 " << "계산할 수 없습니다." << endl;

    int e = 0;
    if(getExp(2,-3,e))      // 2^-3? getExp()는 false 리턴
        cout << "2의 -3 제곱은 " << e << "입니다." << endl;
    else
        cout << " 오류. 2의 -3제곱은 " << "계산할 수 없습니다." << endl;
}
// 음수 입력에 대한 대처 있음