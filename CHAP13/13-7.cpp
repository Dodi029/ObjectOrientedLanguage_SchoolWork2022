// 예외 처리를 가진 스택 클래스 만들기
#include <iostream>
using namespace std;

class MyStack{
    int data[100];
    int tos;
public:
    MyStack(){tos =-1;}
    void push(int n) throw(char*);
    int pop() throw(char*);
};

void MyStack::push(int n) throw(char*){
    if(tos == 99)
        throw "Stack Full";
    tos++;
    data[tos] = n;
}

int MyStack::pop() throw(char*){
    if(tos == -1)
        throw "Stack Empty";
    int rData = data[tos--];
    return rData;
}

int main(){
    MyStack intStack;
    try{
        intStack.push(100);         // 푸시 100
        intStack.push(200);         // 푸시 200
        cout << intStack.pop() << endl;     // 팝 200
        cout << intStack.pop() << endl;     // 팝 100
        cout << intStack.pop() << endl;     // "Stack Empty" 예와 발생
    }
    catch(const char*s){
        cout << "예외 발생 : " << s << endl;
    }
}