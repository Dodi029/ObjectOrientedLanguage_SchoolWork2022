#include <iostream>
using namespace std;

class Calculator{
    void input(){
        cout << " 정수 2개를 입력하세요>>";
        cin >> a >> b;
    }
protected:
    int a,  b;
    virtual int calc(int a, int b) = 0;     // 두 정수의 합
public:
    void run(){
        input();
        cout << " 계산된 값은 " << calc(a, b) << endl;
    }
};
class Adder : public Calculator{        // 순수 가상 함수 구현
public:
    int calc(int a, int b){      // 기본 클래스에서 이미 virtual로 선언되어
                                 // 있으므로 기본 클래스의 calc로 받아도 됨
        return a+b;
    }
};
class Substractor : public Calculator{  // 순수 가상 함수 구현
    public:
    int calc(int a, int b){
        return a-b;
    }
};
int main(){
    Adder adder;
    Substractor substractor;
    adder.run();
    substractor.run();
}