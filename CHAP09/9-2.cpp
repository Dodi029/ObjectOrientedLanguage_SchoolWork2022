#include<iostream>
using namespace std;

class Base{
    public:
    virtual void f(){cout<<"Base::f() called"<<endl;}
};

class Derived : public Base{
    public:
    virtual void f(){cout<<"Derived::f() called"<<endl;}
};

int main(){
    Derived d, *pDer;
    pDer=&d;
    pDer->f();      // Derived::f() 호출

    Base *pBase;
    pBase=pDer;     // 업 캐스팅
    pBase->f();     // 동적바인딩 발생 Derived::f() 실행
}