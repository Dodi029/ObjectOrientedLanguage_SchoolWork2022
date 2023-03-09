// 지수 승 계산을 예외 처리 코드로 재작성(완결판)
#include <iostream>
using namespace std;

int getExp(int base, int exp){      // base의 exp 지수승을 계산하여 리턴
    if (base <= 0 || exp <= 0) {        // 오류 검사
        throw "음수 사용 불가 ";         // 예외 발생    catch 블럭으로 바로 점프
    }
    int value = 1;
    for (int n=0;n<exp;n++)
        value = value*base;
    return value;       // 계산 결과 리턴
}

int main(){
    int v=0;
    try{
        v = getExp(2,3);        // v = 2의 3승 = 8
        cout << "2의 3승은 " << v << "입니다." << endl;
        v = getExp(2,-3);       // 2의 -3승은?  예외 발생
        cout << "2의 -3승은 " << v << "입니다." << endl;
    }
    catch(const char *s){       // 예외 발생 시 출력
        cout << "예외 발생 !!" << s << endl;
    }
}